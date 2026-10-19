#!/usr/bin/env python3
"""Build hand-matching batches for matching agents.

    python tools/hstqueue.py --name fam1 [--module EBOOT.BIN] [--kind families|singles] [--per-batch 8]
                             [--max-size 1600] [--min-size 64] [--batches 4] [--exclude 0xb49ec,...]
                             [--execution-rank try/execution-rank.json]

families: one representative per unmatched clone family (same masked code as hstclone.py), largest total
bytes first; a match is propagated to the other members by hstclone.py. singles: unmatched reviewed
functions that are not in any family, smallest alignment distance first when a generated candidate exists
(try/best-mismatch.json), then by size. Writes try/agent-queue/<name>-NN.json; a function already
covered by a source in src/ or wip/, or listed in an earlier queue file, is never queued twice.
"""
from __future__ import annotations

import argparse
import glob
import hashlib
import json
import re
import sys
from collections import defaultdict
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import hstclone as C
import hstgen as G
import hstmatch as M


def load_execution_rank(path: Path) -> tuple[dict[str, dict[int, dict[str, int]]], dict[str, object]]:
    """Load a complete bounded hstexec result tied to this exact campaign ledger."""
    try:
        raw = path.read_bytes()
        if len(raw) > 64 * 1024 * 1024:
            raise ValueError("file exceeds 64 MiB")
        document = json.loads(raw.decode("utf-8-sig"))
    except (OSError, UnicodeError, json.JSONDecodeError, ValueError) as exc:
        raise ValueError(f"cannot read execution rank ({type(exc).__name__}: {exc})") from exc
    if not isinstance(document, dict) or document.get("schema_version") != 1:
        raise ValueError("unsupported execution-rank schema")
    capture = document.get("capture")
    if not isinstance(capture, dict) or capture.get("complete") is not True:
        raise ValueError("execution rank is not a complete bounded trace")
    if capture.get("unseen_is_not_zero_usage") is not True:
        raise ValueError("execution rank does not preserve unseen-function uncertainty")
    source_commit = capture.get("source_commit")
    trace_sha256 = capture.get("trace_sha256")
    record_count, record_limit = capture.get("record_count"), capture.get("record_limit")
    if (not isinstance(source_commit, str) or not re.fullmatch(r"[0-9a-f]{7,64}", source_commit)
            or not isinstance(trace_sha256, str) or not re.fullmatch(r"[0-9a-f]{64}", trace_sha256)
            or not isinstance(capture.get("scope"), str)
            or isinstance(record_count, bool) or not isinstance(record_count, int)
            or isinstance(record_limit, bool) or not isinstance(record_limit, int)
            or record_count <= 0 or record_count != record_limit):
        raise ValueError("execution rank lacks its source, trace, or scope identity")
    ledger_path = M.CAMPAIGN / "ledger" / "campaign.json"
    ledger_sha256 = hashlib.sha256(ledger_path.read_bytes()).hexdigest()
    if document.get("ledger_sha256") != ledger_sha256:
        raise ValueError("execution rank belongs to a different campaign ledger")
    raw_modules = document.get("modules")
    if not isinstance(raw_modules, list):
        raise ValueError("execution rank has no module list")
    result: dict[str, dict[int, dict[str, int]]] = {}
    for module in raw_modules:
        if not isinstance(module, dict) or not isinstance(module.get("name"), str):
            raise ValueError("execution rank contains a malformed module")
        name = module["name"]
        if name in result:
            raise ValueError(f"execution rank repeats module {name}")
        rows = module.get("functions")
        if not isinstance(rows, list):
            raise ValueError(f"execution rank has no function rows for {name}")
        weights: dict[int, dict[str, int]] = {}
        for row in rows:
            if not isinstance(row, dict) or not isinstance(row.get("address"), str):
                raise ValueError(f"execution rank has a malformed function row for {name}")
            try:
                address = int(row["address"], 16)
                count = row["execution_count"]
                size = row["code_bytes"]
                score = row["weighted_score"]
            except (KeyError, TypeError, ValueError) as exc:
                raise ValueError(f"execution rank has malformed weight fields for {name}") from exc
            if (address < 0 or isinstance(count, bool) or not isinstance(count, int) or count < 0
                    or isinstance(size, bool) or not isinstance(size, int) or size <= 0
                    or isinstance(score, bool) or not isinstance(score, int) or score != count * size):
                raise ValueError(f"execution rank has inconsistent weights for {name}")
            if address in weights:
                raise ValueError(f"execution rank repeats a function address in {name}")
            weights[address] = {"execution_count": count, "weighted_score": score}
        result[name] = weights
    bringup = capture.get("bringup") if isinstance(capture.get("bringup"), dict) else {}
    presentation = bringup.get("presentation")
    frame_submissions = presentation.get("frame_submissions") if isinstance(presentation, dict) else None
    if (isinstance(frame_submissions, bool) or not isinstance(frame_submissions, int)
            or frame_submissions <= 0):
        raise ValueError("execution rank has no rendered frame submissions")
    capture_summary = {
        key: capture.get(key)
        for key in ("source_commit", "source_branch", "trace_kind", "trace_sha256",
                    "scope", "record_count", "record_limit", "unseen_is_not_zero_usage")
    }
    capture_summary["bringup_failure_class"] = bringup.get("failure_class")
    capture_summary["bringup_reached_stage"] = bringup.get("reached_stage")
    presentation = bringup.get("presentation")
    capture_summary["frame_submissions"] = (
        presentation.get("frame_submissions") if isinstance(presentation, dict) else None
    )
    return result, capture_summary


def _execution_queue_key(row: dict, enabled: bool) -> tuple:
    """Observed entry-weighted rows lead; unseen rows keep their legacy order."""
    legacy = row["legacy_priority"]
    tie_size = row["tie_size"]
    if not enabled:
        return (0, legacy, tie_size)
    if row["execution_count"] > 0:
        return (0, -row["execution_score"], legacy, tie_size)
    return (1, legacy, tie_size)


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--name", required=True)
    ap.add_argument("--module", default="EBOOT.BIN")
    ap.add_argument("--kind", choices=("families", "singles"), default="families")
    ap.add_argument("--per-batch", type=int, default=8)
    ap.add_argument("--batches", type=int, default=4)
    ap.add_argument("--min-size", type=int, default=64)
    ap.add_argument("--max-size", type=int, default=1600)
    ap.add_argument("--min-start", type=lambda s: int(s, 0), default=0x88000)
    ap.add_argument("--exclude", default="", help="comma-separated addresses (and their families) to skip")
    ap.add_argument("--execution-rank", type=Path, default=None,
                    help="private hstexec JSON; observed entry hits x code bytes lead, unseen functions keep the legacy order")
    args = ap.parse_args()
    try:
        if args.execution_rank:
            execution_ranks, execution_capture = load_execution_rank(args.execution_rank)
        else:
            execution_ranks, execution_capture = {}, None
    except ValueError as exc:
        raise SystemExit(f"execution rank refused: {exc}") from exc
    if args.execution_rank:
        selected_rank = execution_ranks.get(args.module, {})
        observed = sum(1 for weight in selected_rank.values() if weight["execution_count"] > 0)
        print(f"execution rank: module={args.module} observed_functions={observed}; unseen functions retain legacy order")
    else:
        selected_rank = {}
    queue_dir = M.ROOT / "try" / "agent-queue"
    queue_dir.mkdir(parents=True, exist_ok=True)
    if list(queue_dir.glob(f"{args.name}-*.json")):
        raise SystemExit(f"queue {args.name} exists; use a new name")
    queued = set()
    for q in queue_dir.glob("*.json"):
        for item in json.loads(q.read_text(encoding="utf-8"))["items"]:
            queued.update(int(a, 16) for a in [item["address"], *item.get("family", [])])
    ledger = json.loads((M.CAMPAIGN / "ledger" / "campaign.json").read_text(encoding="utf-8-sig"))
    module = next(m for m in ledger["modules"] if m["name"] == args.module)
    data, seg = M.module_bytes({}, args.module)
    have = set()
    for root in ("src", "wip"):
        for p in (M.ROOT / root).rglob("*"):
            if p.suffix in (".c", ".cpp"):
                h = M.parse_header(p)
                if h["module"] == args.module:
                    have.add(h["start"])
    exclude = {int(a, 16) for a in args.exclude.split(",") if a}
    pseudo, _ = G.load_pseudocode(M.CAMPAIGN, args.module.replace(".", "_"))
    families = defaultdict(list)
    ends = {}
    for f in module["functions"]:
        if f.get("boundary_status") != "reviewed" or f["start"] < args.min_start:
            continue
        ends[f["start"]] = f["end"]
        off = seg["file_offset"] + f["start"] - seg["start"]
        sig, _refs = C.analyse(C.words(data[off:off + f["end"] - f["start"]]))
        families[sig].append(f["start"])
    # twins in the other game module (EBOOT <-> Sharing) are cloned across by hstclone.py --from-module
    other_name = "hstp_trans_main.prx" if args.module == "EBOOT.BIN" else "EBOOT.BIN"
    other = next(m for m in ledger["modules"] if m["name"] == other_name)
    odata, oseg = M.module_bytes({}, other_name)
    twins = defaultdict(list)
    for f in other["functions"]:
        if f.get("boundary_status") == "reviewed":
            off = oseg["file_offset"] + f["start"] - oseg["start"]
            signature = C.analyse(C.words(odata[off:off + f["end"] - f["start"]]))[0]
            twins[signature].append((f["start"], f["end"]))
    other_rank = execution_ranks.get(other_name, {})
    best_path = M.ROOT / "try" / "best-mismatch.json"
    best = json.loads(best_path.read_text(encoding="utf-8")) if best_path.exists() else {}
    rows = []
    for sig, starts in families.items():
        starts = sorted(starts)
        size = 4 * len(sig)
        if any(s in have or s in queued or s in exclude for s in starts):
            continue
        if not args.min_size <= size <= args.max_size:
            continue
        twin_functions = twins.get(sig, [])
        n_twins = len(twin_functions)
        execution_count = 0
        execution_score = 0
        for start in starts:
            weight = selected_rank.get(start)
            if weight and weight["execution_count"] > 0:
                execution_count += weight["execution_count"]
                execution_score += weight["weighted_score"]
        for start, _end in twin_functions:
            weight = other_rank.get(start)
            if weight and weight["execution_count"] > 0:
                execution_count += weight["execution_count"]
                execution_score += weight["weighted_score"]
        if args.kind == "families" and len(starts) >= 2:
            legacy_priority = -size * (len(starts) + n_twins)
            rows.append({
                "legacy_priority": legacy_priority, "tie_size": ends[starts[0]] - starts[0],
                "starts": starts, "n_twins": n_twins,
                "execution_count": execution_count, "execution_score": execution_score,
            })
        elif args.kind == "singles" and len(starts) == 1:
            b = best.get(f"{args.module}:0x{starts[0]:08x}")
            # functions with twins first (their match counts twice), then by generated-candidate distance
            legacy_priority = (0 if n_twins else 1, (b[0] / max(b[1], 1)) if b else 1.0)
            rows.append({
                "legacy_priority": legacy_priority, "tie_size": ends[starts[0]] - starts[0],
                "starts": starts, "n_twins": n_twins,
                "execution_count": execution_count, "execution_score": execution_score,
            })
    rows.sort(key=lambda row: _execution_queue_key(row, args.execution_rank is not None))
    batches = [rows[i:i + args.per_batch] for i in range(0, len(rows), args.per_batch)][:args.batches]
    for n, batch in enumerate(batches):
        items = []
        for row in batch:
            starts, n_twins = row["starts"], row["n_twins"]
            rep = starts[0]
            b = best.get(f"{args.module}:0x{rep:08x}")
            item = {
                "address": f"0x{rep:08x}", "end": f"0x{ends[rep]:08x}", "size": ends[rep] - rep,
                "family": [f"0x{s:08x}" for s in starts[1:]],
                "twins_in_other_module": n_twins,
                "pseudocode": str(pseudo[rep][1]) if rep in pseudo else None,
                "ghidra_name": pseudo[rep][0] if rep in pseudo else f"FUN_{rep:08x}",
                "best_generated": ({"source": b[2], "differing_words": b[0], "words": b[1]} if b else None),
            }
            if args.execution_rank:
                item["execution_weight"] = (
                    {"entry_hits_in_window": row["execution_count"],
                     "weighted_code_bytes": row["execution_score"]}
                    if row["execution_count"] > 0 else None
                )
            items.append(item)
        out = queue_dir / f"{args.name}-{n:02d}.json"
        queue_document = {"module": args.module, "kind": args.kind, "items": items}
        if execution_capture is not None:
            queue_document["execution_capture"] = execution_capture
        out.write_text(json.dumps(queue_document, indent=1) + "\n", encoding="utf-8")
        print(f"{out.relative_to(M.ROOT).as_posix()}: {len(items)} items, "
              f"{sum(i['size'] * (1 + len(i['family']) + i['twins_in_other_module']) for i in items)} bytes "
              "incl. family members and twins" +
              (f", {sum(1 for row in batch if row['execution_count'] > 0)} observed execution-weighted"
               if args.execution_rank else ""))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
