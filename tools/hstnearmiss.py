#!/usr/bin/env python3
"""Measure and classify the near misses in wip/ (the sources that are close to exact but are not).

    python tools/hstnearmiss.py [--parallel 6] [--no-compile] [wip/file ...]
    python tools/hstnearmiss.py --self-test

Re-runs tools/hstmatch.py on every wip/ source (or on the files named; their rows are merged into the last report),
then labels each one with exactly ONE class from the words it still gets wrong and writes
try/nearmiss-report.json and try/nearmiss-report.md. tools/hstattempts.py reads the JSON for today's words left.
--no-compile reuses the last hstmatch run (try/nearmiss-match.json and the build/ directories) and only re-labels.

"words left" is hstmatch's own count: the number of word positions that differ between our linked bytes and the
retail bytes (a function of the wrong length counts the surplus words too). Rank = code bytes per word left, so a
big function that is two words off comes first; an exact-now file ranks above everything.

Classes (first rule that applies; the rules look at registers, opcodes and immediates only, so a label is a hint
about where to look, not a diagnosis):

  exact_now              hstmatch reports EXACT: install it (header, provenance note, re-run)
  superseded             src/ already has a source for this function: the wip file is stale
  blocked                the function is in data/blocked_functions.json
  tool_state             COMPILE_FAILED / MISSING_SYMBOLS / LINK_FAILED / NO_SYMBOL / MISPLACED: the file does not
                         reach the comparison (a missing symbol line, a static helper hstmatch cannot place, ...)
  jump_table_rodata      UNPLACED_SECTION / SECTION_MISMATCH: the code matches or the table/data is not placed
  frame_layout           only the frame size (first addiu sp) and sp-relative slots differ
  type_signedness        only lb/lbu, lh/lhu, slt/sltu, sra/srl, mult/multu, div/divu style pairs differ
  register_colouring     same words with different register fields (same opcodes, same immediates)
  constant_materialisation  the differing words are lui/ori/addiu-from-zero/hi-lo immediates, or the surplus
                         words are exactly such constants (folded vs unfolded lui/addiu, wrong literal)
  instruction_schedule   the same words (registers aside) in a different order
  branch_shape           only branch words differ (likely vs normal, polarity, offsets)
  missing_extra_insn     our function has more or fewer words than retail and the surplus is not constants
  unknown                a mixture the rules above do not separate (the JSON lists "facets")
"""
from __future__ import annotations

import argparse
import datetime
import difflib
import json
import re
import subprocess
import sys
from collections import Counter, defaultdict
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import hstattempts as A
import hstmatch as M
import hstpublish

ROOT = M.ROOT
MATCH_JSON = ROOT / "try" / "nearmiss-match.json"
REPORT_JSON = ROOT / "try" / "nearmiss-report.json"
REPORT_MD = ROOT / "try" / "nearmiss-report.md"
CLASSES = ("exact_now", "superseded", "blocked", "tool_state", "jump_table_rodata", "frame_layout", "type_signedness",
           "register_colouring", "constant_materialisation", "instruction_schedule", "branch_shape",
           "missing_extra_insn", "unknown")
SP = 29
EXCLUDED = tuple(hstpublish.EXCLUDED_CLASSES)   # origin classes the public tree leaves out


# --------------------------------------------------------------------------------------------------------------
# word-level classification (pure functions)

def words(data: bytes) -> list[int]:
    return [int.from_bytes(data[i:i + 4], "little") for i in range(0, len(data) - len(data) % 4, 4)]


def regmask(w: int) -> int:
    """The word with its general and floating-point register fields cleared (opcode and immediates kept)."""
    op = w >> 26
    if op == 0:                                   # SPECIAL: rs, rt, rd
        return w & ~((31 << 21) | (31 << 16) | (31 << 11))
    if op == 1:                                   # REGIMM: rs; rt is the branch kind
        return w & ~(31 << 21)
    if op in (2, 3):                              # j, jal: a target, no registers
        return w
    if op == 0x11:                                # COP1
        fmt = (w >> 21) & 31
        if fmt in (0x10, 0x11, 0x14):             # s/d/w arithmetic: ft, fs, fd
            return w & ~((31 << 16) | (31 << 11) | (31 << 6))
        if fmt in (0, 2, 4, 6):                   # mfc1/cfc1/mtc1/ctc1: rt and fs
            return w & ~((31 << 16) | (31 << 11))
        return w                                  # bc1x: condition bits and an offset
    if op in (0x18, 0x19, 0x1a, 0x1b, 0x34, 0x35, 0x36, 0x37, 0x3c, 0x3d, 0x3e, 0x3f, 0x32, 0x3a):
        return w                                  # VFPU: not decoded, a difference is a plain difference
    return w & ~((31 << 21) | (31 << 16))         # I-type, loads/stores, SPECIAL3 (ext/ins/seb/seh), lwc1/swc1


def loosekey(w: int) -> int:
    """regmask(), and for loads/stores also without the displacement (a folded and an unfolded access differ in it)."""
    op = w >> 26
    if 0x20 <= op <= 0x2F or op in (0x31, 0x39):
        return op << 26
    return regmask(w)


def is_branch(w: int) -> bool:
    op = w >> 26
    return op in (4, 5, 6, 7, 0x14, 0x15, 0x16, 0x17, 1) or (op == 0x11 and (w >> 21) & 31 == 8)


def is_constant_word(w: int) -> bool:
    """lui, or ori/addiu/addiu-from-zero that completes or loads a constant."""
    op = w >> 26
    rs, rt = (w >> 21) & 31, (w >> 16) & 31
    if op == 0x0F:
        return True
    if op in (0x09, 0x0D, 0x0C, 0x08):            # addiu, ori, andi, addi
        return rs == 0 or rs == rt
    return False


def is_sp_word(w: int) -> bool:
    """addiu/addi sp or a sp-relative load/store/addiu-address, the instructions a frame change touches."""
    op = w >> 26
    rs = (w >> 21) & 31
    if op in (0x08, 0x09):
        return rs == SP or ((w >> 16) & 31) == SP
    return (0x20 <= op <= 0x2F or op in (0x31, 0x35, 0x39, 0x3d, 0x32, 0x36, 0x3a, 0x3e)) and rs == SP


SIGN_OPS = {(0x20, 0x24), (0x24, 0x20), (0x21, 0x25), (0x25, 0x21), (0x0A, 0x0B), (0x0B, 0x0A)}
SIGN_FUNCT = {(0x2A, 0x2B), (0x2B, 0x2A), (2, 3), (3, 2), (6, 7), (7, 6), (0x18, 0x19), (0x19, 0x18), (0x1A, 0x1B), (0x1B, 0x1A)}


def sign_pair(a: int, b: int) -> bool:
    oa, ob = a >> 26, b >> 26
    if oa == 0 and ob == 0:
        return (a & 63, b & 63) in SIGN_FUNCT and (a >> 6) == (b >> 6) or \
               ((a & 63, b & 63) in SIGN_FUNCT and regmask(a & ~63) == regmask(b & ~63))
    return (oa, ob) in SIGN_OPS and (a & 0x03FFFFFF) == (b & 0x03FFFFFF)


def classify_words(ours: list[int], theirs: list[int]) -> tuple[str, list[str]]:
    """(class, facets) for a function whose bytes differ."""
    facets: list[str] = []
    if len(ours) == len(theirs):
        pairs = [(a, b) for a, b in zip(ours, theirs) if a != b]
        if not pairs:
            return "exact_now", []
        if all(regmask(a) == regmask(b) for a, b in pairs):
            return "register_colouring", ["reg"]
        if all(is_sp_word(a) and is_sp_word(b) for a, b in pairs):
            return "frame_layout", ["sp"]
        if all(sign_pair(a, b) or regmask(a) == regmask(b) for a, b in pairs):
            return "type_signedness", ["sign"]
        if all(is_constant_word(a) and is_constant_word(b) for a, b in pairs):
            return "constant_materialisation", ["const"]
        if sorted(regmask(w) for w in ours) == sorted(regmask(w) for w in theirs):
            return "instruction_schedule", ["order"] + (["reg"] if any(regmask(a) == regmask(b) for a, b in pairs) else [])
        if all(is_branch(a) and is_branch(b) for a, b in pairs):
            return "branch_shape", ["branch"]
        if any(is_branch(a) or is_branch(b) for a, b in pairs):
            facets.append("branch")
        if any(regmask(a) == regmask(b) for a, b in pairs):
            facets.append("reg")
        if any(is_constant_word(a) or is_constant_word(b) for a, b in pairs):
            facets.append("const")
        if any(is_sp_word(a) or is_sp_word(b) for a, b in pairs):
            facets.append("sp")
        return "unknown", facets or ["mixed"]
    # different lengths: align the register-masked words and look at what only one side has
    sm = difflib.SequenceMatcher(None, [loosekey(w) for w in ours], [loosekey(w) for w in theirs], autojunk=False)
    only_ours: list[int] = []
    only_theirs: list[int] = []
    replaced: list[tuple[int, int]] = []
    for tag, i1, i2, j1, j2 in sm.get_opcodes():
        if tag == "delete":
            only_ours += ours[i1:i2]
        elif tag == "insert":
            only_theirs += theirs[j1:j2]
        elif tag == "replace":
            only_ours += ours[i1:i2]
            only_theirs += theirs[j1:j2]
            replaced += list(zip(ours[i1:i2], theirs[j1:j2]))
    surplus = only_ours + only_theirs
    if ours and theirs and ours[0] != theirs[0] and (ours[0] >> 16) == 0x27BD and (theirs[0] >> 16) == 0x27BD \
            and all(is_sp_word(w) for w in surplus):
        return "frame_layout", ["sp", "length"]
    if surplus and all(is_constant_word(w) for w in surplus):
        return "constant_materialisation", ["const", "length"]
    return "missing_extra_insn", ["length"] + (["const"] if any(is_constant_word(w) for w in surplus) else [])


def words_left_of(ours: list[int], theirs: list[int]) -> int:
    n = max(len(ours), len(theirs))
    return sum(1 for i in range(n) if (ours[i] if i < len(ours) else None) != (theirs[i] if i < len(theirs) else None))


# --------------------------------------------------------------------------------------------------------------
# measuring

def our_body(out: Path, h: dict) -> bytes | None:
    """Our linked function bytes exactly as hstmatch compares them, or None when there is no link output."""
    text, obj = out / "text.bin", out / "obj.o"
    if not text.exists() or not obj.exists():
        return None
    objbytes = obj.read_bytes()
    names = [n for n, _ in M.elf_sections(objbytes)]
    ti = names.index(".text") if ".text" in names else -1
    sym = [(v, s) for n, v, s, i, sh in M.elf_symbols(objbytes) if n == h["symbol"] and sh == ti]
    text_off, size = (sym[0] if sym else (0, 0))
    linked = text.read_bytes()[text_off:]
    span = h["end"] - h["start"]
    return linked[:span] if size < span else linked[:size]


def run_match(files: list[Path], parallel: int, out_json: Path) -> list[dict]:
    out_json.parent.mkdir(parents=True, exist_ok=True)
    results = []
    # chunks of 80 files: one call over every wip file exceeds the Windows command-line limit (WinError 206)
    for i in range(0, len(files), 80):
        cmd = [sys.executable, str(Path(M.__file__)), "--quiet", "--parallel", str(parallel), "--json", str(out_json)]
        subprocess.run(cmd + [str(f) for f in files[i:i + 80]], stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
        results += json.loads(out_json.read_text(encoding="utf-8"))
    out_json.write_text(json.dumps(results), encoding="utf-8")
    return results


def measure(path: Path, status: str, detail: str, origin: dict[str, str], src_index: dict, blocked: set,
            data_cache: dict) -> dict:
    h = M.parse_header(path)
    rel = path.relative_to(ROOT).as_posix()
    size = h["end"] - h["start"]
    row = {"wip": rel, "module": h["module"], "start": f"0x{h['start']:08x}", "end": f"0x{h['end']:08x}", "size": size,
           "cc": h.get("cc", "mwcc219"), "status": status, "detail": detail, "words": size // 4, "words_left": None,
           "class": "unknown", "facets": [], "origin": origin.get(rel, "?"), "superseded_by": None}
    src_row = src_index.get((h["module"], h["start"]))
    ours = theirs = None
    if status in ("MISMATCH",):
        out = ROOT / "build" / h["module"] / f"{path.resolve().parent.name}__{path.stem}"
        body = our_body(out, h)
        data, seg = M.module_bytes(data_cache, h["module"])
        off = seg["file_offset"] + h["start"] - seg["start"]
        retail = data[off:off + size]
        if body is not None:
            ours, theirs = words(body), words(retail)
            row["words_left"] = words_left_of(ours, theirs)
            row["class"], row["facets"] = classify_words(ours, theirs)
            row["ours_words"] = len(ours)
    elif status == "EXACT":
        row.update({"words_left": 0, "class": "exact_now"})
    elif status in ("UNPLACED_SECTION", "SECTION_MISMATCH"):
        row["class"] = "jump_table_rodata"
    else:
        row["class"] = "tool_state"
    if src_row is not None:
        row["superseded_by"] = src_row["path"]
        row["class_if_live"] = row["class"]
        row["class"] = "superseded"
    elif (h["module"], h["start"]) in blocked:
        row["class_if_live"] = row["class"]
        row["class"] = "blocked"
    # rank: code bytes per word left; an exact-now file is the cheapest of all, an unmeasured one the last
    left = row["words_left"]
    row["yield"] = round(size / max(left, 1), 2) if left is not None else 0.0
    return row


# --------------------------------------------------------------------------------------------------------------
# report

def example_diff(row: dict, context: int = 2, limit: int = 40) -> list[str]:
    """Side-by-side disassembly lines (ours | retail) around the differing words of one measured file."""
    import hstdiff as D
    path = ROOT / row["wip"]
    h = M.parse_header(path)
    out = ROOT / "build" / h["module"] / f"{path.resolve().parent.name}__{path.stem}"
    body = our_body(out, h)
    if body is None:
        return []
    cache: dict = {}
    data, seg = M.module_bytes(cache, h["module"])
    off = seg["file_offset"] + h["start"] - seg["start"]
    scratch = ROOT / "build" / "nearmiss"
    scratch.mkdir(parents=True, exist_ok=True)
    (scratch / "ours.bin").write_bytes(body)
    (scratch / "retail.bin").write_bytes(data[off:off + (h["end"] - h["start"])])
    a, b = D.disasm(scratch / "ours.bin", h["start"]), D.disasm(scratch / "retail.bin", h["start"])
    n = max(len(a), len(b))
    flags = [(a[i] if i < len(a) else "") .split(" ")[0] != (b[i] if i < len(b) else "").split(" ")[0] for i in range(n)]
    keep = set()
    for i, f in enumerate(flags):
        if f:
            keep.update(range(max(0, i - context), min(n, i + context + 1)))
    lines, last = [], -2
    for i in sorted(keep):
        if i != last + 1:
            lines.append("   ...")
        x, y = (a[i] if i < len(a) else ""), (b[i] if i < len(b) else "")
        lines.append(f"{'**' if flags[i] else '  '} {h['start'] + 4 * i:08x}  {x:<44.44} | {y}")
        last = i
        if len(lines) >= limit:
            lines.append("   ... (truncated)")
            break
    return lines


def class_table(rows: list[dict]) -> list[dict]:
    out = []
    for cls in CLASSES:
        mine = [r for r in rows if r["class"] == cls]
        if not mine:
            continue
        measured = [r for r in mine if r["words_left"] is not None]
        out.append({"class": cls, "files": len(mine), "code_bytes": sum(r["size"] for r in mine),
                    "words_left": sum(r["words_left"] for r in measured),
                    "median_words_left": sorted(r["words_left"] for r in measured)[len(measured) // 2] if measured else None,
                    "cheapest_yield": max((r["yield"] for r in mine), default=0.0),
                    "public_files": sum(1 for r in mine if r["origin"] not in EXCLUDED)})
    return out


def write_reports(rows: list[dict], generated: str, examples: dict[str, list[str]]) -> None:
    rows = sorted(rows, key=lambda r: (-r["yield"], r["wip"]))
    table = class_table(rows)
    live = [t for t in table if t["class"] not in ("exact_now", "superseded", "blocked", "tool_state", "jump_table_rodata")]
    biggest = max(live, key=lambda t: t["code_bytes"]) if live else None
    doc = {"schema": "hst-decomp.nearmiss.v1", "generated": generated, "files": rows, "classes": table,
           "biggest_class_by_code_bytes": biggest["class"] if biggest else None,
           "public_eligible": sum(1 for r in rows if r["origin"] not in EXCLUDED)}
    REPORT_JSON.write_text(json.dumps(doc, indent=1) + "\n", encoding="utf-8")
    md = [f"# Near-miss report, {generated}", "",
          f"{len(rows)} files in `wip/` ({doc['public_eligible']} of them in origin classes the public tree keeps). "
          "Each was re-run with `tools/hstmatch.py` and given exactly one class from the words it still gets wrong "
          "(see the docstring of `tools/hstnearmiss.py` for the rules). Words left = differing word positions; rank = "
          "code bytes per word left.", "",
          "## Classes", "",
          "| Class | Files | Code bytes | Words left | Median left | Best bytes/word | Public files |", "|---|---:|---:|---:|---:|---:|---:|"]
    for t in table:
        md.append(f"| `{t['class']}` | {t['files']} | {t['code_bytes']} | {t['words_left']} | "
                  f"{t['median_words_left'] if t['median_words_left'] is not None else '-'} | {t['cheapest_yield']} | {t['public_files']} |")
    if biggest:
        md += ["", f"Class that most code bytes depend on (live near misses only): `{biggest['class']}` with "
                   f"{biggest['code_bytes']} bytes in {biggest['files']} files.", ""]
    md += ["## One example per class", ""]
    for t in table:
        ex = examples.get(t["class"])
        if not ex:
            continue
        md += [f"### `{t['class']}`", "", "```", *ex, "```", ""]
    md += ["## All files, ranked by code bytes per word left", "",
           "| Rank | File | Module | Start | Bytes | Words left | Bytes/word | Class | Facets | Origin | Note |",
           "|---:|---|---|---|---:|---:|---:|---|---|---|---|"]
    for i, r in enumerate(rows, 1):
        note = r["superseded_by"] or (r["detail"][:60] if r["class"] in ("tool_state", "jump_table_rodata") else "")
        left = r["words_left"] if r["words_left"] is not None else "-"
        md.append(f"| {i} | `{r['wip']}` | {r['module'].split('.')[0]} | {r['start']} | {r['size']} | {left} | {r['yield']} | "
                  f"`{r['class']}` | {','.join(r['facets'])} | {r['origin']} | {note} |")
    REPORT_MD.write_text("\n".join(md) + "\n", encoding="utf-8")


def self_test() -> int:
    """A few synthetic word sequences with known classes."""
    addiu_sp = 0x27BDFFE0
    lw = lambda rt, base, imm: (0x23 << 26) | (base << 21) | (rt << 16) | (imm & 0xFFFF)
    addu = lambda rd, rs, rt: (rs << 21) | (rt << 16) | (rd << 11) | 0x21
    lui = lambda rt, imm: (0x0F << 26) | (rt << 16) | imm
    addiu = lambda rt, rs, imm: (9 << 26) | (rs << 21) | (rt << 16) | (imm & 0xFFFF)
    lb, lbu = (0x20 << 26), (0x24 << 26)
    cases = [
        ("register_colouring", [addiu_sp, addu(2, 4, 5), lw(3, 4, 8)], [addiu_sp, addu(3, 4, 5), lw(2, 4, 8)]),
        ("instruction_schedule", [addiu_sp, addu(2, 4, 5), lw(3, 4, 8)], [addiu_sp, lw(3, 4, 8), addu(2, 4, 5)]),
        ("type_signedness", [addiu_sp, lb | (4 << 21) | (2 << 16) | 3], [addiu_sp, lbu | (4 << 21) | (2 << 16) | 3]),
        ("constant_materialisation", [addiu_sp, lui(2, 0x3b), addiu(2, 2, 0x10), lw(3, 2, 0)], [addiu_sp, lui(2, 0x3b), lw(3, 2, 0x10)]),
        ("frame_layout", [addiu_sp, lw(3, SP, 16)], [0x27BDFFD0, lw(3, SP, 32)]),
        ("missing_extra_insn", [addiu_sp, addu(2, 4, 5), addu(3, 4, 5)], [addiu_sp, addu(2, 4, 5)]),
    ]
    bad = 0
    for want, ours, theirs in cases:
        got, _facets = classify_words(ours, theirs)
        if got != want:
            print(f"FAIL {want}: got {got}")
            bad += 1
    print("self-test " + ("FAILED" if bad else f"ok ({len(cases)} cases)"))
    return 1 if bad else 0


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("files", nargs="*", type=Path, help="wip files to re-measure (default: all; rows merge into the last report)")
    ap.add_argument("--parallel", type=int, default=6)
    ap.add_argument("--no-compile", action="store_true")
    ap.add_argument("--self-test", action="store_true")
    ap.add_argument("--examples", type=int, default=1)
    args = ap.parse_args()
    if args.self_test:
        return self_test()
    import hstorigin
    wip_files = sorted(p for p in (ROOT / "wip").iterdir() if p.suffix in (".c", ".cpp"))
    chosen = [p if p.is_absolute() else ROOT / p for p in args.files] or wip_files
    origin, _warn = hstorigin.classify()
    src_index, _wip = A.scan_sources()
    blocked = A.blocked_keys()
    cache: dict = {}
    # hstmatch builds into build/<module>/wip__<stem>: a .c and a .cpp with one stem would overwrite each other, so
    # such files are compiled and read back in separate waves (the k-th file of every stem per wave)
    by_stem: dict = defaultdict(list)
    for p in chosen:
        by_stem[(M.parse_header(p)["module"], p.stem)].append(p)
    waves = [[v[k] for v in by_stem.values() if len(v) > k] for k in range(max((len(v) for v in by_stem.values()), default=0))]
    all_results: dict = {}
    if args.no_compile:
        all_results = {r["source"]: r for r in json.loads(MATCH_JSON.read_text(encoding="utf-8"))}
    rows = []
    for n, wave in enumerate(waves):
        if not args.no_compile:
            part = ROOT / "try" / f"nearmiss-match-part{n}.json"
            all_results.update({r["source"]: r for r in run_match(wave, args.parallel, part)})
        for p in wave:
            r = all_results.get(p.relative_to(ROOT).as_posix())
            if r is not None:
                rows.append(measure(p, r["status"], r["detail"], origin, src_index, blocked, cache))
    if not args.no_compile:
        merged = {}
        if args.files and MATCH_JSON.exists():
            merged = {r["source"]: r for r in json.loads(MATCH_JSON.read_text(encoding="utf-8"))}
        merged.update(all_results)
        MATCH_JSON.write_text(json.dumps(list(merged.values()), indent=1) + "\n", encoding="utf-8")
    if args.files and REPORT_JSON.exists():
        old = {r["wip"]: r for r in json.loads(REPORT_JSON.read_text(encoding="utf-8"))["files"]}
        old.update({r["wip"]: r for r in rows})
        rows = [r for r in old.values() if (ROOT / r["wip"]).exists()]
    examples: dict[str, list[str]] = {}
    for cls in CLASSES:
        usable = [r for r in rows if r["class"] == cls and r["words_left"] is not None
                  and len(by_stem.get((r["module"], Path(r["wip"]).stem), [])) < 2]     # build dir not shared
        pool = [r for r in usable if r["words"] <= 90] or usable
        if pool and cls not in ("superseded", "blocked"):
            best = max(pool, key=lambda r: (r["yield"], -r["size"]))
            lines = example_diff(best)
            if lines:
                examples[cls] = [f"{best['wip']}  ({best['words_left']} of {best['words']} words left)", *lines]
    write_reports(rows, datetime.date.today().isoformat(), examples)
    print(f"{len(rows)} files measured")
    for t in class_table(rows):
        print(f"  {t['class']:26} {t['files']:4} files {t['code_bytes']:7} B  {t['words_left']:5} words left")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
