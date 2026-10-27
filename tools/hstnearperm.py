#!/usr/bin/env python3
"""Random-mutation search (hstperm.py's mutations) seeded with the cheapest near misses in wip/.

    python tools/hstnearperm.py --tag n1 [--max-left 6] [--classes register_colouring,instruction_schedule,...]
                                [--levers permute,frame,types,expression]
                                [--rounds 8] [--mutants 16] [--parallel 6] [--seed 1] [--limit N] [wip/file ...]

hstperm.py starts from generated candidates under try/gen-*; this tool starts from the files in wip/ that
tools/hstnearmiss.py measured (try/nearmiss-report.json), so a near miss that a lane or an earlier permuter run
parked is mutated again from its best-known text. Each round compiles `--mutants` variants of every unfinished seed
with hstmatch.py, keeps the best by alignment score (words outside the longest common word alignment with retail),
and stops a seed the moment a variant is EXACT. Nothing is installed: exact variants are written to
try/nearperm-<tag>/exact/ (with the seed's name) for a person to review, give a provenance note and install, and
the best non-exact variants to try/nearperm-<tag>/best/. Mutations need not preserve meaning; only a byte-exact
build counts, but a variant that reads worse than its seed (casts, duplicated conditions) should not be installed.

Seeds must also have one of --levers (tools/hstnearmiss.py's routing; default: the levers whose calls and control
flow already agree with retail). A file whose calls or branches differ (lever body or structure) or whose only
difference is a symbol (referent) is not a permuter problem, so it is left out unless it is named on the command
line. Rows of a report written before the levers existed have no lever and are not filtered by it.

Compile cost is printed: every variant is one mwccpsp run.
"""
from __future__ import annotations

import argparse
import json
import random
import shutil
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import hstattempts as A
import hstmatch as M
import hstperm as P

ROOT = M.ROOT
DEFAULT_LEVERS = ("permute", "frame", "types", "expression")
DEFAULT_CLASSES = ("register_colouring", "instruction_schedule", "frame_layout", "branch_shape", "unknown",
                   "constant_materialisation")


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("files", nargs="*", type=Path)
    ap.add_argument("--tag", required=True)
    ap.add_argument("--max-left", type=int, default=6, help="seed only files with at most this many words left")
    ap.add_argument("--classes", default=",".join(DEFAULT_CLASSES))
    ap.add_argument("--levers", default=",".join(DEFAULT_LEVERS))
    ap.add_argument("--rounds", type=int, default=8)
    ap.add_argument("--mutants", type=int, default=16)
    ap.add_argument("--parallel", type=int, default=6)
    ap.add_argument("--seed", type=int, default=1)
    ap.add_argument("--limit", type=int, default=0)
    ap.add_argument("--max-words", type=int, default=1200)
    args = ap.parse_args()
    rng = random.Random(args.seed)
    work = ROOT / "try" / f"nearperm-{args.tag}"
    if work.exists():
        raise SystemExit(f"{work} exists; use a new tag")
    report = json.loads((ROOT / "try" / "nearmiss-report.json").read_text(encoding="utf-8"))
    classes = set(args.classes.split(","))
    levers = set(args.levers.split(","))
    attempts = A.collect()          # reserved addresses (batches of lanes that are not finished) are never touched
    src = attempts.src
    chosen = {Path(f).as_posix() for f in args.files}
    seeds = []
    reserved = 0
    for row in sorted(report["files"], key=lambda r: -r["yield"]):
        if chosen and row["wip"] not in chosen:
            continue
        if not chosen and (row["class"] not in classes or row["words_left"] is None or row["words_left"] > args.max_left):
            continue
        if not chosen and row.get("lever", next(iter(levers))) not in levers:
            continue
        if row["class"] in ("superseded", "blocked", "tool_state", "exact_now") and not chosen:
            continue
        if row["words"] > args.max_words or (row["module"], int(row["start"], 16)) in src:
            continue
        att_row = attempts.status(row["module"], int(row["start"], 16))
        if att_row and att_row.get("reserved_by"):
            reserved += 1
            continue
        seeds.append(row)
    if args.limit:
        seeds = seeds[:args.limit]
    print(f"seeds={len(seeds)} (skipped {reserved} reserved by lane batches) classes={sorted(classes)} levers={sorted(levers)} max_left={args.max_left}", flush=True)
    state, owner, ends = {}, {}, {}
    for idx, row in enumerate(seeds):
        path = ROOT / row["wip"]
        h = M.parse_header(path)
        key = (h["module"], h["start"])
        text = path.read_text(encoding="utf-8")
        ends[key] = h["end"]
        state[key] = [row["words_left"], text, row["wip"], path.suffix]
    cmd = [sys.executable, str(Path(M.__file__)), "--quiet", "--parallel", str(args.parallel), "--json"]
    exact_dir = work / "exact"
    exact_dir.mkdir(parents=True)
    (work / "best").mkdir()
    accepted: dict = {}
    compiles = 0
    # the seeds themselves, so that every later score is measured the same way (alignment, not positional)
    base_files, base_owner = [], {}
    for idx, (key, (_s, text, name, suffix)) in enumerate(state.items()):
        path = work / "seed" / f"{args.tag}_s{idx:04d}_{key[1]:08x}{suffix}"
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text(text, encoding="utf-8", newline="\n")
        base_files.append(path)
        base_owner[str(path.resolve())] = key
    compiles += len(base_files)
    for path_text, score in P.run_scored(cmd, base_files, work / "seed", ends, base_owner).items():
        state[base_owner[path_text]][0] = score
    keys = sorted(state, key=lambda k: state[k][0])
    print("seed scores: " + " ".join(f"{state[k][2].removeprefix('wip/')}={state[k][0]}" for k in keys[:40]), flush=True)
    for rnd in range(args.rounds):
        active = [k for k in keys if k not in accepted]
        if not active:
            break
        files, owner = [], {}
        for idx, key in enumerate(active):
            seen = set()
            for k in range(args.mutants):
                text = P.mutate(state[key][1], rng)
                if text is None or text in seen or text == state[key][1]:
                    continue
                seen.add(text)
                path = work / f"r{rnd:02d}" / f"{args.tag}_f{idx:04d}_{key[1]:08x}_m{k:02d}{state[key][3]}"
                path.parent.mkdir(parents=True, exist_ok=True)
                path.write_text(text, encoding="utf-8", newline="\n")
                files.append(path)
                owner[str(path.resolve())] = key
        compiles += len(files)
        results = P.run_scored(cmd, files, work / f"r{rnd:02d}", ends, owner)
        improved = 0
        for path_text, score in results.items():
            key = owner[path_text]
            if key in accepted:
                continue
            if score == 0:
                accepted[key] = Path(path_text)
                dest = exact_dir / Path(state[key][2]).name
                shutil.copyfile(path_text, dest)
                print(f"EXACT {key[0]} 0x{key[1]:08x} {state[key][2]} -> {dest.relative_to(ROOT).as_posix()}", flush=True)
            elif score < state[key][0] or (score == state[key][0] and rng.random() < 0.3):
                improved += score < state[key][0]
                state[key][0] = score
                state[key][1] = Path(path_text).read_text(encoding="utf-8")
        print(f"round={rnd} variants={len(files)} exact_total={len(accepted)} improved={improved} compiles={compiles}", flush=True)
    summary = {}
    for key, (score, text, name, suffix) in state.items():
        if key in accepted:
            continue
        out = work / "best" / Path(name).name
        out.write_text(text, encoding="utf-8", newline="\n")
        summary[name] = score
    (work / "report.json").write_text(json.dumps({"tag": args.tag, "seeds": len(seeds), "compiles": compiles,
                                                  "exact": sorted(state[k][2] for k in accepted),
                                                  "best_score_of_the_rest": summary}, indent=1) + "\n", encoding="utf-8")
    print(json.dumps({"seeds": len(seeds), "exact": len(accepted), "compiles": compiles}))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
