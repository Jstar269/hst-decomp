#!/usr/bin/env python3
"""Build hand-matching batches for matching agents.

    python tools/hstqueue.py --name fam1 [--module EBOOT.BIN] [--kind families|singles] [--per-batch 8]
                             [--max-size 1600] [--min-size 64] [--batches 4] [--exclude 0xb49ec,...]

families: one representative per unmatched clone family (same masked code as hstclone.py), largest total
bytes first; a match is propagated to the other members by hstclone.py. singles: unmatched reviewed
functions that are not in any family, smallest alignment distance first when a generated candidate exists
(try/best-mismatch.json), then by size. Writes try/agent-queue/<name>-NN.json; a function already
covered by a source in src/ or wip/, or listed in an earlier queue file, is never queued twice.
"""
from __future__ import annotations

import argparse
import glob
import json
import sys
from collections import defaultdict
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import hstclone as C
import hstgen as G
import hstmatch as M


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
    args = ap.parse_args()
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
    twins = defaultdict(int)
    for f in other["functions"]:
        if f.get("boundary_status") == "reviewed":
            off = oseg["file_offset"] + f["start"] - oseg["start"]
            twins[C.analyse(C.words(odata[off:off + f["end"] - f["start"]]))[0]] += 1
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
        n_twins = twins.get(sig, 0)
        if args.kind == "families" and len(starts) >= 2:
            rows.append((-size * (len(starts) + n_twins), starts, n_twins))
        elif args.kind == "singles" and len(starts) == 1:
            b = best.get(f"{args.module}:0x{starts[0]:08x}")
            # functions with twins first (their match counts twice), then by generated-candidate distance
            rows.append(((0 if n_twins else 1, (b[0] / max(b[1], 1)) if b else 1.0), starts, n_twins))
    rows.sort(key=lambda r: (r[0], ends[r[1][0]] - r[1][0]))
    batches = [rows[i:i + args.per_batch] for i in range(0, len(rows), args.per_batch)][:args.batches]
    for n, batch in enumerate(batches):
        items = []
        for _, starts, n_twins in batch:
            rep = starts[0]
            b = best.get(f"{args.module}:0x{rep:08x}")
            items.append({
                "address": f"0x{rep:08x}", "end": f"0x{ends[rep]:08x}", "size": ends[rep] - rep,
                "family": [f"0x{s:08x}" for s in starts[1:]],
                "twins_in_other_module": n_twins,
                "pseudocode": str(pseudo[rep][1]) if rep in pseudo else None,
                "ghidra_name": pseudo[rep][0] if rep in pseudo else f"FUN_{rep:08x}",
                "best_generated": ({"source": b[2], "differing_words": b[0], "words": b[1]} if b else None),
            })
        out = queue_dir / f"{args.name}-{n:02d}.json"
        out.write_text(json.dumps({"module": args.module, "kind": args.kind, "items": items}, indent=1) + "\n",
                       encoding="utf-8")
        print(f"{out.relative_to(M.ROOT).as_posix()}: {len(items)} items, "
              f"{sum(i['size'] * (1 + len(i['family']) + i['twins_in_other_module']) for i in items)} bytes "
              "incl. family members and twins")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
