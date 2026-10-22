#!/usr/bin/env python3
"""Write the public objdiff progress report (docs/objdiff-report.json) from the same figures as the README table.

    python tools/hstreport.py            write docs/objdiff-report.json (also done by `hstprogress.py --write`)
    python tools/hstreport.py --check    exit 1 when the committed report differs from the figures measured now
    python tools/hstreport.py --proofs   measure from the accepted ledger (like hstprogress.py --proofs)

WHY. recomp.fyi shows a decomp's share of matched code when the repository's default-branch workflow uploads an
objdiff progress report (`build/report.json`) as the artifact `<version>_report`. Public CI cannot build (no game, no
keys, no Metrowerks compiler), so the maintainers generate the report here, from the public progress figures
(`tools/hstprogress.py`: matched functions and code bytes of the two game modules), commit it as
docs/objdiff-report.json, and .github/workflows/progress-report.yml copies it to build/report.json and uploads it.

FORMAT. objdiff-core's report (objdiff-core/protos/report.proto, REPORT_VERSION 2) in its JSON form (pbjson with
`preserve_proto_field_names`): snake_case names, 64-bit counters as decimal strings, 32-bit counters and percentages as
numbers. One unit and one category per module (the ids of the progress categories in objdiff.json).

WHAT THE NUMBERS MEAN (honest by construction).
  total_code / matched_code      the reviewed functions' code bytes of the module / the bytes of the functions with an
                                 exact source (tools/hstprogress.py `measure`, the README's figure)
  fuzzy_match_percent            equal to matched_code_percent: partial matches ("near misses") are not counted
  total_data / matched_data      total_data is every byte of the decrypted module image outside the reviewed functions;
                                 matched_data is 0: data is not reproduced yet, so a report never reads as complete
  complete_*                     0: nothing is linked from the decompiled sources yet
The report carries counts and percentages only: no game bytes, no function names, no paths.
"""
from __future__ import annotations

import argparse
import json
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
REPORT_PATH = ROOT / "docs" / "objdiff-report.json"
REPORT_VERSION = 2


def pct(part: int, whole: int) -> float:
    return round(100 * part / whole, 3) if whole else 0.0


def measures(code: int, matched_code: int, data: int, functions: int, matched_functions: int, units: int) -> dict:
    """One objdiff `Measures` message (JSON form): u64 as strings, u32 and floats as numbers."""
    matched_pct = pct(matched_code, code)
    return {"fuzzy_match_percent": matched_pct,
            "total_code": str(code), "matched_code": str(matched_code), "matched_code_percent": matched_pct,
            "total_data": str(data), "matched_data": "0", "matched_data_percent": 0.0,
            "total_functions": functions, "matched_functions": matched_functions,
            "matched_functions_percent": pct(matched_functions, functions),
            "complete_code": "0", "complete_code_percent": 0.0, "complete_data": "0", "complete_data_percent": 0.0,
            "total_units": units, "complete_units": 0}


def build_report(fig: dict, sc: dict) -> dict:
    """The report for `fig` (hstprogress.measure over the public modules) and `sc` (hstprogress.scope)."""
    rows = fig["modules"]
    units, categories = [], []
    sums = {"code": 0, "matched": 0, "data": 0, "functions": 0, "matched_functions": 0}
    for name, r in rows.items():
        data = sc["modules"][name]["image_bytes"] - r["code_bytes"]
        if data < 0:
            raise ValueError(f"{name}: the reviewed functions ({r['code_bytes']} B) exceed the image")
        m = measures(r["code_bytes"], r["matched_code_bytes"], data, r["functions"], r["matched_functions"], 1)
        units.append({"name": name, "measures": m,
                      "metadata": {"module_name": name, "progress_categories": [name]}})
        categories.append({"id": name, "name": name, "measures": dict(m)})
        sums["code"] += r["code_bytes"]
        sums["matched"] += r["matched_code_bytes"]
        sums["data"] += data
        sums["functions"] += r["functions"]
        sums["matched_functions"] += r["matched_functions"]
    total = measures(sums["code"], sums["matched"], sums["data"], sums["functions"], sums["matched_functions"], len(units))
    return {"measures": total, "units": units, "version": REPORT_VERSION, "categories": categories}


def render(report: dict) -> str:
    return json.dumps(report, indent=1) + "\n"


def write(fig: dict, sc: dict, path: Path = REPORT_PATH) -> Path:
    path.write_text(render(build_report(fig, sc)), encoding="utf-8", newline="\n")
    return path


def differences(fig: dict, sc: dict, path: Path = REPORT_PATH) -> list[str]:
    """Why the committed report does not match the measured figures ('' list when it does)."""
    if not path.exists():
        return [f"{path.name} does not exist"]
    want = build_report(fig, sc)
    try:
        have = json.loads(path.read_text(encoding="utf-8"))
    except ValueError as exc:
        return [f"{path.name} is not valid JSON: {exc}"]
    if have == want:
        return []
    h, w = have.get("measures", {}), want["measures"]
    out = [f"{path.name} {k}: {h.get(k)}, measured {w[k]}" for k in ("total_code", "matched_code", "total_functions",
                                                                    "matched_functions", "total_data") if h.get(k) != w[k]]
    return out or [f"{path.name} differs from the measured figures (run tools/hstreport.py)"]


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--check", action="store_true")
    ap.add_argument("--proofs", action="store_true", help="measure from the accepted ledger, like hstprogress.py --proofs")
    args = ap.parse_args()
    sys.path.insert(0, str(Path(__file__).resolve().parent))
    import hstorigin
    import hstprogress as P
    led = P.ledger()
    classes, _warnings = hstorigin.classify(P.ROOT)
    fig = P.measure(classes=classes, led=led, from_proofs=args.proofs)
    sc = P.scope(led)
    if args.check:
        diffs = differences(fig, sc)
        print("objdiff report: " + ("agrees" if not diffs else "DIFFERS"))
        for d in diffs:
            print("  " + d)
        return 1 if diffs else 0
    t = build_report(fig, sc)["measures"]
    print(f"wrote {write(fig, sc).relative_to(ROOT).as_posix()}: {t['matched_functions']}/{t['total_functions']} functions, "
          f"{t['matched_code']}/{t['total_code']} code bytes ({t['matched_code_percent']:.3f} %)")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
