#!/usr/bin/env python3
"""Progress against docs/COMPLETION.md: the tier ladder T1-T4, the strict headline, and the public-eligible figures.

    python tools/hstprogress.py                  print the figures (nothing is written)
    python tools/hstprogress.py --write          write progress.json, today's row of docs/progress.csv and the visuals
                                                 (docs/progress*.svg, drawn by tools/hstviz.py) and
                                                 docs/objdiff-report.json (tools/hstreport.py: the objdiff report recomp.fyi reads)
    python tools/hstprogress.py --check-readme   compare the public code figure with the table in README.md and with
                                                 docs/objdiff-report.json (exit 1 on a difference)
    python tools/hstprogress.py --private        also print the all-sources figures (they include unpublished Sony SDK
                                                 reconstructions and are never written to a file)
    python tools/hstprogress.py --proofs         count tier 1 from the accepted ledger (tools/hstproof.py) instead of
                                                 the sources present in src/

SCOPE (the denominator; it never shrinks). Every byte of the decrypted image of every module the campaign ledger tracks
(six modules): `scope_bytes`. Two smaller views of the same modules are printed for reference: the file-backed bytes of
the load segments (the part of the image that is mapped, what docs/COMPLETION.md's "about 20.6 %" was measured against)
and the bytes of the ledger's reviewed functions (what the README table counts). Functions that the toolchain cannot
reproduce (data/blocked_functions.json) stay in the denominator; they are shown as their own count.

TIERS (each a share of `scope_bytes`):

  T1  code bytes of functions with an exact source in src/ (isolation match, tools/hstmatch.py): a function counts when
      a source covers its start or a multi-function source's span, like tools/hstcov.py. Data is not matched yet, so T1
      is code only. Public files show the public-eligible T1 (origin classes tools/hstpublish.py keeps); the all-sources
      T1 includes the Sony SDK reconstructions and is printed with --private only.
  T2  bytes reproduced by the whole-module build from source: read from try/build/<module>-report.json written by
      tools/hstbuild.py (only bytes of compiled sources whose in-place link bytes equal retail count; scaffolding never
      counts). 0 while no such report exists.
  T3  T2 and the shifted build passes (gate 5): t3_source_bytes of build reports whose shifted build passed.
  T4  = STRICT headline: T3 and the source is human reviewed (gate 7): 0 until T3 exists. Nothing is estimated.

docs/progress.csv keeps one row per day and source. The first rows were seeded from the figures the README showed
("readme:<commit>"); they are tier-1, public-eligible, code-byte figures over the two game modules' functions and stay
as they were (the columns up to `blocked_code_bytes`); newer rows add the scope and tier columns.
"""
from __future__ import annotations

import argparse
import csv
import datetime
import hashlib
import json
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import hstattempts as A
import hstmatch as M
import hstorigin
import hstpublish

ROOT = M.ROOT
CSV_PATH = ROOT / "docs" / "progress.csv"
JSON_PATH = ROOT / "progress.json"
BUILD_DIR = ROOT / "try" / "build"
COLUMNS = ["date", "source", "matched_functions", "total_functions", "matched_code_bytes", "total_code_bytes",
           "percent_code_bytes", "near_misses", "blocked_functions", "blocked_code_bytes",
           "scope_bytes", "t1_public_bytes", "t1_public_percent", "t2_bytes", "t3_bytes", "t4_bytes", "strict_percent"]
AWAITING = re.compile(r"await human review", re.I)


def public_modules() -> list[str]:
    doc = json.loads((ROOT / "data" / "modules.json").read_text(encoding="utf-8"))
    return [m["name"] for m in doc["modules"]]


def ledger() -> dict:
    return json.loads((M.CAMPAIGN / "ledger" / "campaign.json").read_text(encoding="utf-8-sig"))


def scope(led: dict | None = None) -> dict:
    """Denominators of the six ledger modules: decrypted image bytes (the strict scope), file-backed load-segment bytes,
    reviewed-function code bytes."""
    led = led or ledger()
    cache: dict = {}
    out = {"modules": {}, "scope_bytes": 0, "segment_bytes": 0, "function_bytes": 0}
    for m in led["modules"]:
        data, _seg = M.module_bytes(cache, m["name"])
        row = {"image_bytes": len(data),
               "segment_bytes": sum(s["file_end"] - s["file_offset"] for s in m["load_segments"]),
               "function_bytes": sum(f["end"] - f["start"] for f in m["functions"]),
               "functions": len(m["functions"])}
        out["modules"][m["name"]] = row
        out["scope_bytes"] += row["image_bytes"]
        out["segment_bytes"] += row["segment_bytes"]
        out["function_bytes"] += row["function_bytes"]
    return out


def measure(modules: list[str] | None = None, root: Path = ROOT, include_excluded: bool = False,
            classes: dict[str, str] | None = None, led: dict | None = None, from_proofs: bool = False) -> dict:
    """Matched functions and code bytes over `modules` (default: the two game modules of data/modules.json).
    `include_excluded` also counts the origin classes the public tree leaves out. `from_proofs` counts only the ranges
    of the accepted ledger (tools/hstproof.py: proofs from verification runs, each byte once) instead of every source
    present in src/."""
    modules = modules or public_modules()
    led = led or ledger()
    if classes is None:
        classes, _warnings = hstorigin.classify(root)
    keep = lambda cls: include_excluded or cls not in hstpublish.EXCLUDED_CLASSES      # noqa: E731
    src: dict[tuple[str, int], dict] = {}
    wip_public = 0
    awaiting = 0
    for rel, cls in classes.items():
        if not keep(cls):
            continue
        path = root / rel
        h = M.parse_header(path)
        if rel.startswith("wip/"):
            wip_public += 1
            continue
        if h["module"] not in modules:
            continue
        src[(h["module"], h["start"])] = {"path": rel, "start": h["start"], "end": h["end"], "module": h["module"]}
        head = path.read_text(encoding="utf-8", errors="replace")[:1500].split("\n", 2)
        if len(head) > 1 and AWAITING.search(head[1]):
            awaiting += 1
    if from_proofs:
        import hstproof
        src = {(p["module"], int(p["start"], 16)): {"path": p["source"], "start": int(p["start"], 16),
                                                    "end": int(p["end"], 16), "module": p["module"]}
               for p in hstproof.accepted_proofs(root=root)
               if p["module"] in modules and p["source"] in classes and keep(classes[p["source"]])}
    blocked = A.load_blocked(root / "data" / "blocked_functions.json")
    per_module = {}
    total = {"functions": 0, "matched_functions": 0, "code_bytes": 0, "matched_code_bytes": 0,
             "blocked_functions": 0, "blocked_code_bytes": 0}
    for m in led["modules"]:
        if m["name"] not in modules:
            continue
        starts, maxend = A.exact_spans(src, m["name"])
        exact_starts = {s for (mod, s) in src if mod == m["name"]}
        row = {"functions": 0, "matched_functions": 0, "code_bytes": 0, "matched_code_bytes": 0,
               "blocked_functions": 0, "blocked_code_bytes": 0, "blocked_matched": 0}
        for f in m["functions"]:
            size = f["end"] - f["start"]
            hit = f["start"] in exact_starts or A.covered_by_span(starts, maxend, f["start"], f["end"])
            row["functions"] += 1
            row["code_bytes"] += size
            if hit:
                row["matched_functions"] += 1
                row["matched_code_bytes"] += size
            if (m["name"], f["start"]) in blocked:
                if hit:
                    row["blocked_matched"] += 1     # a blocked entry that has a source: the list is stale
                else:
                    row["blocked_functions"] += 1
                    row["blocked_code_bytes"] += size
        per_module[m["name"]] = row
        for k in total:
            total[k] += row[k]
    total["percent_code_bytes"] = round(100 * total["matched_code_bytes"] / total["code_bytes"], 3) if total["code_bytes"] else 0.0
    return {"modules": per_module, "total": total, "sources": len(src), "near_misses": wip_public,
            "provenance_notes_awaiting_review": awaiting, "human_reviewed": reviewed_count(src, root),
            "blocked_entries": len(blocked), "source_rows": src}


def reviewed_count(src: dict, root: Path) -> int | None:
    """Sources with an accepted decision that still matches their text; None when no decision log exists."""
    log = root / "reviews" / "decisions.jsonl"
    if not log.exists():
        return None
    latest: dict[str, dict] = {}
    for line in log.read_text(encoding="utf-8").splitlines():
        if line.strip():
            d = json.loads(line)
            latest[d["path"]] = d
    n = 0
    for row in src.values():
        d = latest.get(row["path"])
        text = (root / row["path"]).read_text(encoding="utf-8")
        if d and d.get("decision") == "accepted" and d.get("sha256") == hashlib.sha256(text.encode("utf-8")).hexdigest():
            n += 1
    return n


def build_reports(build_dir: Path = BUILD_DIR, mode: str = "public") -> dict[str, dict]:
    """{module: report} from tools/hstbuild.py (try/build/<module>[-private]-report.json) of one build mode, "public" (the
    default: the Sony SDK origin classes are supplied from the owner's executable) or "private"; {} when none exists."""
    out = {}
    if build_dir.is_dir():
        for p in sorted(build_dir.glob("*-report.json")):
            try:
                doc = json.loads(p.read_text(encoding="utf-8"))
            except ValueError:
                continue
            if isinstance(doc, dict) and "module" in doc and isinstance(doc.get("t2_source_bytes"), dict)                     and doc.get("build_mode", "private") == mode:
                out[doc["module"]] = doc
    return out


def tier_ladder(scope_bytes: int, t1_bytes: int, reports: dict[str, dict], public_paths: set[str] | None,
                review_all: bool = False) -> dict:
    """The ladder over one denominator. `public_paths` restricts T2 to those sources (None = every source)."""
    t2 = t3 = 0
    for report in reports.values():
        for path, nbytes in report["t2_source_bytes"].items():
            if path.startswith("src/") and (public_paths is None or path in public_paths):   # accepted sources only
                t2 += nbytes
        if report.get("shifted_build_passes") is True:          # T3: only from a shifted build that passed
            for path, nbytes in (report.get("t3_source_bytes") or {}).items():
                if path.startswith("src/") and (public_paths is None or path in public_paths):
                    t3 += nbytes
    return {"scope_bytes": scope_bytes, "t1_bytes": t1_bytes, "t2_bytes": t2, "t3_bytes": t3, "t4_bytes": 0,
            "t1_percent": round(100 * t1_bytes / scope_bytes, 3), "t2_percent": round(100 * t2 / scope_bytes, 3),
            "t3_percent": round(100 * t3 / scope_bytes, 3), "t4_percent": 0.0, "strict_percent": 0.0}


# --------------------------------------------------------------------------------------------------------------
# history and public files

def csv_rows() -> list[dict]:
    if not CSV_PATH.exists():
        return []
    with CSV_PATH.open(encoding="utf-8", newline="") as fh:
        return list(csv.DictReader(fh))


def row_order(r: dict) -> tuple:
    return (r["date"], 0 if r["source"].startswith("readme") else 1)


def write_csv(rows: list[dict]) -> None:
    with CSV_PATH.open("w", encoding="utf-8", newline="") as fh:
        w = csv.DictWriter(fh, fieldnames=COLUMNS, lineterminator="\n")
        w.writeheader()
        for r in sorted(rows, key=row_order):
            w.writerow({k: r.get(k, "") for k in COLUMNS})


def today_row(fig: dict, ladder: dict, date: str) -> dict:
    t = fig["total"]
    return {"date": date, "source": "hstprogress", "matched_functions": t["matched_functions"],
            "total_functions": t["functions"], "matched_code_bytes": t["matched_code_bytes"],
            "total_code_bytes": t["code_bytes"], "percent_code_bytes": f"{t['percent_code_bytes']:.3f}",
            "near_misses": fig["near_misses"], "blocked_functions": t["blocked_functions"],
            "blocked_code_bytes": t["blocked_code_bytes"], "scope_bytes": ladder["scope_bytes"],
            "t1_public_bytes": ladder["t1_bytes"], "t1_public_percent": f"{ladder['t1_percent']:.3f}",
            "t2_bytes": ladder["t2_bytes"], "t3_bytes": ladder["t3_bytes"], "t4_bytes": ladder["t4_bytes"],
            "strict_percent": f"{ladder['strict_percent']:.3f}"}


def badge(ladder: dict) -> dict:
    s = ladder["strict_percent"]
    color = "red" if s < 10 else "orange" if s < 25 else "yellow" if s < 50 else "yellowgreen" if s < 75 else "brightgreen"
    return {"schemaVersion": 1, "label": "strict match",
            "message": f"{s:.1f}% (tier 1: {ladder['t1_percent']:.1f}%)", "color": color}


def compare_readme(fig: dict) -> list[str]:
    """Differences between the public code figure and the README's progress table ('' list when they agree)."""
    text = (ROOT / "README.md").read_text(encoding="utf-8")
    m = re.search(r"\*\*Both\*\* \| ([\d,]+) / ([\d,]+) \| ([\d,]+) / ([\d,]+) \| ([\d.]+) %", text)
    if not m:
        return ["README.md has no '**Both**' progress row"]
    num = lambda s: int(s.replace(",", ""))    # noqa: E731
    t = fig["total"]
    want = (t["matched_functions"], t["functions"], t["matched_code_bytes"], t["code_bytes"])
    got = (num(m.group(1)), num(m.group(2)), num(m.group(3)), num(m.group(4)))
    out = [f"README {name}: {g:,}, measured {w:,}" for name, g, w in zip(
        ("matched functions", "functions", "matched code bytes", "code bytes"), got, want) if g != w]
    if f"{t['percent_code_bytes']:.3f}" != m.group(5):
        out.append(f"README share {m.group(5)} %, measured {t['percent_code_bytes']:.3f} %")
    return out


def print_figures(fig: dict, sc: dict, ladder: dict, reports: dict) -> None:
    print("Public code figure (what the README table shows: public-eligible sources, the two game modules' reviewed functions)")
    for name, r in fig["modules"].items():
        print(f"  {name:22} {r['matched_functions']:6,} / {r['functions']:<6,} fns  {r['matched_code_bytes']:9,} / {r['code_bytes']:<9,} B  "
              f"{100 * r['matched_code_bytes'] / r['code_bytes']:7.3f} %   blocked {r['blocked_functions']} fns / {r['blocked_code_bytes']:,} B"
              + (f"   STALE blocked entries with a source: {r['blocked_matched']}" if r["blocked_matched"] else ""))
    t = fig["total"]
    print(f"  {'Both':22} {t['matched_functions']:6,} / {t['functions']:<6,} fns  {t['matched_code_bytes']:9,} / {t['code_bytes']:<9,} B  "
          f"{t['percent_code_bytes']:7.3f} %   blocked {t['blocked_functions']} fns / {t['blocked_code_bytes']:,} B")
    print(f"  public sources {fig['sources']:,}; near misses {fig['near_misses']}; notes awaiting review "
          f"{fig['provenance_notes_awaiting_review']:,}; human reviewed "
          f"{'not available (no reviews/decisions.jsonl)' if fig['human_reviewed'] is None else fig['human_reviewed']}")
    print("Scope (docs/COMPLETION.md): six modules")
    for name, r in sc["modules"].items():
        print(f"  {name:32} image {r['image_bytes']:>9,} B   load segments {r['segment_bytes']:>9,} B   reviewed functions {r['function_bytes']:>9,} B ({r['functions']:,})")
    print(f"  {'total':32} image {sc['scope_bytes']:>9,} B   load segments {sc['segment_bytes']:>9,} B   reviewed functions {sc['function_bytes']:>9,} B")
    print(f"Tier ladder, public sources, share of the {ladder['scope_bytes']:,} scope bytes:")
    print(f"  T1 function matches (code only)  {ladder['t1_bytes']:>9,} B  {ladder['t1_percent']:7.3f} %"
          f"   ({100 * ladder['t1_bytes'] / sc['segment_bytes']:.3f} % of the load-segment bytes)")
    note = "" if reports else "   (no try/build/*-report.json: no whole-module build yet)"
    print(f"  T2 whole-module build from source {ladder['t2_bytes']:>8,} B  {ladder['t2_percent']:7.3f} %{note}")
    print(f"  T3 shifted build                  {ladder['t3_bytes']:>9,} B  {ladder['t3_percent']:7.3f} %")
    print(f"  T4 STRICT (reviewed)              {ladder['t4_bytes']:>9,} B  {ladder['t4_percent']:7.3f} %   <- headline")


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--write", action="store_true")
    ap.add_argument("--check-readme", action="store_true")
    ap.add_argument("--private", action="store_true", help="also print the all-sources figures (not written anywhere)")
    ap.add_argument("--date", default=datetime.date.today().isoformat(), help="date of the CSV row (default today)")
    ap.add_argument("--proofs", action="store_true", help="count tier 1 from the accepted ledger only (tools/hstproof.py: "
                    "proofs from verification runs), not from the sources present in src/")
    args = ap.parse_args()
    led = ledger()
    classes, _warnings = hstorigin.classify(ROOT)
    fig = measure(classes=classes, led=led, from_proofs=args.proofs)
    sc = scope(led)
    all_modules = [m["name"] for m in led["modules"]]
    public6 = measure(all_modules, classes=classes, led=led, from_proofs=args.proofs)
    reports = build_reports()
    public_paths = {p for p in (v["path"] for v in public6["source_rows"].values())}
    ladder = tier_ladder(sc["scope_bytes"], public6["total"]["matched_code_bytes"], reports, public_paths)
    print("Tier 1 counted from: " + ("the accepted ledger (proofs; tools/hstproof.py)" if args.proofs else
                                     "the sources present in src/ (presence; --proofs counts the accepted ledger)"))
    print_figures(fig, sc, ladder, reports)
    status = 0
    if args.check_readme:
        diffs = compare_readme(fig)
        print("README table: " + ("agrees" if not diffs else "DIFFERS"))
        for d in diffs:
            print("  " + d)
        import hstreport
        report_diffs = hstreport.differences(fig, sc)
        print("objdiff report (docs/objdiff-report.json): " + ("agrees" if not report_diffs else "DIFFERS"))
        for d in report_diffs:
            print("  " + d)
        status = 1 if diffs or report_diffs else 0
    if args.private:
        full = measure(all_modules, include_excluded=True, classes=classes, led=led, from_proofs=args.proofs)
        t = full["total"]
        priv = tier_ladder(sc["scope_bytes"], t["matched_code_bytes"], build_reports(mode="private"), None)
        print("PRIVATE (all sources incl. unpublished SDK reconstructions; do not publish): "
              f"T1 {t['matched_functions']:,} fns, {t['matched_code_bytes']:,} B = {priv['t1_percent']:.3f} % of scope "
              f"({100 * t['matched_code_bytes'] / sc['segment_bytes']:.3f} % of load-segment bytes); "
              f"{100 * t['matched_code_bytes'] / t['code_bytes']:.3f} % of the six modules' reviewed-function bytes")
    if args.write:
        rows = [r for r in csv_rows() if not (r["date"] == args.date and r["source"] == "hstprogress")]
        rows.append(today_row(fig, ladder, args.date))
        write_csv(rows)
        JSON_PATH.write_text(json.dumps(badge(ladder), indent=1) + "\n", encoding="utf-8", newline="\n")
        import hstviz  # the visuals read the CSV just written
        drawn = [p.relative_to(ROOT).as_posix() for p in hstviz.write()]
        import hstreport  # the objdiff report recomp.fyi reads, from the same figures
        report = hstreport.write(fig, sc).relative_to(ROOT).as_posix()
        print(f"wrote {JSON_PATH.name}, {CSV_PATH.relative_to(ROOT).as_posix()} ({len(rows)} rows), {', '.join(drawn)}, {report}")
    return status


if __name__ == "__main__":
    raise SystemExit(main())
