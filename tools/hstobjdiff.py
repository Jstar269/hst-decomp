#!/usr/bin/env python3
"""objdiff project generator for the HST decompilation: objdiff.json plus the objects objdiff reads.

    python tools/hstobjdiff.py [generate] [--no-wip] [--only GLOB] [--out FILE] [--quiet]
    python tools/hstobjdiff.py check [--random N] [--wip] [--objdiff-cli PATH] [--out FILE]

objdiff (https://github.com/encounter/objdiff) diffs two object files per *unit*: `path` is our
compiled code, `target_path` is retail. hstmatch.py already produces both sides fully resolved at the
retail address (our linked bytes in `text.bin`, retail in the module image), so this tool only has to
repack those bytes into minimal ELF32-little-endian MIPS objects - no relocation reconstruction.

`generate` writes, all under `build/objdiff/` (generated, never committed):

    units/<source>.base.o    our bytes of one source's range, at their retail address
    units/<source>.target.o  the retail bytes of the same range, at the same address
    unmatched/<module>.o     target-only unit: every retail function that no source covers
    empty.base.o             the empty base object the unmatched units use
    hstobjdiff.json          what was generated (counts and warnings), for STATUS.md

and `objdiff.json` in the repository root, which the GUI and `objdiff-cli report generate` read.
Function boundaries and names on both sides come from the campaign ledger (`FUN_<address>`), which is
also what hstmatch.py and hstcov.py measure against; a unit carries the ledger function of its header
`start=`. Sources under `wip/` become units too (they are near misses, so they report <100%).

`check` runs objdiff-cli over the generated project and verifies it against the rest of the toolchain:

    * `objdiff-cli report generate` totals agree with `python tools/hstcov.py --json`, per module: the
      sum of every ledger function's size and the byte total of the sources in `src/` must match,
    * every `src/` unit reports 100% (a random sample by default, `--random 0` for all of them),
    * every `wip/` near miss reports <100%, and its differences check out: every instruction
      `tools/hstdiff.py <file>` marks must sit on a word that really differs between the generated
      objects, and every instruction objdiff reports must sit on or next to one.

objdiff compares *aligned* instruction streams and resolves branch targets to the instruction they
point at, so for a reordered near miss it reports fewer, more meaningful differences than hstdiff.py's
fixed-stride view; `check` verifies the differences both can see rather than pretending the two
models agree (see docs/OBJDIFF.md).

Every source needs hstmatch.py's build products in `build/<module>/<parent>__<stem>/`; run
`python tools/hstmatch.py --all` (plus the `wip/` files) first. Sources whose artifacts are missing are
reported and skipped, never guessed at.

The ledger is `ledger/campaign.json` under `campaign_root` (hst-config.json), read the same way `hstcov.py`
does (through hstmatch.py's helpers), never by walking the campaign directory.

The project sets objdiff's MIPS instruction category to `r4000allegrex` (OPTIONS below), so the PSP's Allegrex
instructions (ext/ins, seb/seh, min/max, the VFPU) are decoded and compared like any other; objdiff's
default category renders them `INVALID` and compares every `INVALID` word as equal.
"""
from __future__ import annotations

import argparse
import json
import random
import struct
import subprocess
import sys
from bisect import bisect_left
from collections import defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(Path(__file__).resolve().parent))
import hstmatch as M  # noqa: E402

OUT_DIR = ROOT / "build" / "objdiff"
PROJECT_FILE = ROOT / "objdiff.json"
SUMMARY_FILE = OUT_DIR / "hstobjdiff.json"
# objdiff configuration properties: written to the project's "options" and passed to every one-shot
# `objdiff-cli diff` (which does not read the project file).
OPTIONS = {"mips_instr_category": "r4000allegrex"}
CLI_CANDIDATES = ("try/objdiff-bin/objdiff-cli.exe", "try/objdiff-bin/objdiff-cli", "objdiff-cli")
# e_flags of the retail toolchain's objects; every generated object copies them from the hstmatch object
# when that exists (MWCC and the GCC kits emit 0x10970001, psp-ld links with the same value).
DEFAULT_E_FLAGS = 0x10000001


def elf32(text_addr: int, text: bytes, symbols: list[tuple[str, int, int]],
          e_flags: int = DEFAULT_E_FLAGS) -> bytes:
    """A minimal ELF32 (little-endian, EM_MIPS, ET_EXEC) holding one code section.

    `text` is placed at `text_addr`, and `symbols` are (name, address, size) global function symbols
    inside it. objdiff needs nothing else for a fully resolved comparison: both sides of a unit are
    linked images, so no relocations and no other section exist.
    """
    shstr = b"\0.text\0.symtab\0.strtab\0.shstrtab\0"
    name_off = {b"\0": 0}
    for name in (b".text", b".symtab", b".strtab", b".shstrtab"):
        name_off[name] = shstr.index(name)
    strtab = bytearray(b"\0")
    symtab = bytearray(16)  # the null symbol
    for name, addr, size in symbols:
        off = len(strtab)
        strtab += name.encode() + b"\0"
        symtab += struct.pack("<IIIBBH", off, addr, size, 0x12, 0, 1)  # GLOBAL FUNC, .text
    text_off = 52
    sym_off = text_off + len(text)
    str_off = sym_off + len(symtab)
    shstr_off = str_off + len(strtab)
    shoff = shstr_off + len(shstr)
    shdrs: list[bytes] = []

    def sh(name: bytes, typ: int, flags: int, addr: int, off: int, size: int,
           link: int = 0, info: int = 0, align: int = 1, entsize: int = 0) -> None:
        shdrs.append(struct.pack("<IIIIIIIIII", name_off[name], typ, flags, addr, off, size, link, info,
                                 align, entsize))

    sh(b"\0", 0, 0, 0, 0, 0)
    sh(b".text", 1, 0x6, text_addr, text_off, len(text), align=4)
    sh(b".symtab", 2, 0, 0, sym_off, len(symtab), link=3, info=1, align=4, entsize=16)
    sh(b".strtab", 3, 0, 0, str_off, len(strtab))
    sh(b".shstrtab", 3, 0, 0, shstr_off, len(shstr))
    ehdr = b"\x7fELF" + bytes([1, 1, 1, 0, 0]) + bytes(7)
    ehdr += struct.pack("<HHIIIIIHHHHHH", 2, 8, 1, text_addr, 0, shoff, e_flags, 52, 0, 0, 40, 5, 4)
    return ehdr + text + bytes(symtab) + bytes(strtab) + shstr + b"".join(shdrs)


_ledger: dict[str, list[tuple[int, int]]] | None = None


def ledger() -> dict[str, list[tuple[int, int]]]:
    """Per module, the (start, end) of every function the campaign ledger lists, sorted by address.

    Which function exists, and where it begins and ends, is the ledger's decision (hstcov.py measures
    against the same list); the tools never use their own idea of a boundary.
    """
    global _ledger
    if _ledger is None:
        data = json.loads((M.CAMPAIGN / "ledger" / "campaign.json").read_text(encoding="utf-8-sig"))
        _ledger = {m["name"]: sorted((f["start"], f["end"]) for f in m.get("functions", []))
                   for m in data["modules"]}
    return _ledger


def function_name(start: int) -> str:
    return f"FUN_{start:08x}"


def build_dir(src: Path, module: str) -> Path:
    """hstmatch.py's output directory for one source (its unique parent-name + stem directory)."""
    return ROOT / "build" / module / M.build_key(src)


def object_symbol(src: Path, module: str, symbol: str) -> tuple[int, int] | None:
    """(offset, size) of the compiled function inside the object's .text, as hstmatch.py sees it.

    hstmatch.py links with `.text` starting at `start - offset` and extracts the whole section, so
    `text.bin[offset:]` is the compared range. A source that is part of a file compiled as a whole (a
    library file) is the only case where the offset is not 0; the size matters for a near miss whose
    compiled function is longer than the ledger's function, which hstmatch.py compares in full.
    """
    obj_path = build_dir(src, module) / "obj.o"
    if not obj_path.exists():
        return None
    obj = obj_path.read_bytes()
    sections = [name for name, _ in M.elf_sections(obj)]
    if ".text" not in sections:
        return None
    text_index = sections.index(".text")
    for name, value, size, _info, shndx in M.elf_symbols(obj):
        if name == symbol and shndx == text_index:
            return value, size
    return None


def e_flags_of(obj_path: Path) -> int:
    """The toolchain's own ELF header flags, so objdiff sees the same object header we do."""
    if not obj_path.exists():
        return DEFAULT_E_FLAGS
    with obj_path.open("rb") as f:
        header = f.read(0x28)
    return struct.unpack_from("<I", header, 0x24)[0] if len(header) >= 0x28 else DEFAULT_E_FLAGS


def clamp_symbols(symbols: list[tuple[str, int, int]], start: int, length: int) -> list[tuple[str, int, int]]:
    """Drop the part of a symbol that the object does not hold (objdiff rejects out-of-bounds data).

    A near miss whose compiled function is shorter than the ledger function has fewer bytes on the base
    side than the symbol the ledger describes, so the base symbol is clamped to what exists.
    """
    end = start + length
    out = []
    for name, address, size in symbols:
        size = min(size, max(0, end - address))
        if size > 0:
            out.append((name, address, size))
    return out


def write_object(path: Path, data: bytes) -> None:
    """Write one generated object. Unconditionally: on this machine a write costs ~1 ms and the
    read-compare that would avoid it costs ~10 ms, so regenerating the whole project stays quick."""
    path.write_bytes(data)


def unit_paths(src: Path) -> tuple[Path, Path]:
    """Where the base and target object of one source's unit live (mirrors the source tree)."""
    rel = src.relative_to(ROOT)
    stem = rel.parent / rel.stem
    return OUT_DIR / "units" / stem.with_suffix(".base.o"), OUT_DIR / "units" / stem.with_suffix(".target.o")


def unit_name(src: Path) -> str:
    rel = src.relative_to(ROOT)
    return (rel.parent / rel.stem).as_posix()


def source_files(include_wip: bool) -> list[Path]:
    roots = ["src"] + (["wip"] if include_wip else [])
    return sorted(p for r in roots for p in (ROOT / r).rglob("*") if p.suffix in (".c", ".cpp"))


def generate(args: argparse.Namespace) -> int:
    modules = ledger()
    cache: dict = {}
    sources = source_files(not args.no_wip)
    if args.only:
        sources = [p for p in sources if any(p.match(g) for g in args.only)]
    units: list[dict] = []
    covered: dict[str, set[int]] = defaultdict(set)
    warnings: list[str] = []
    skipped: list[str] = []
    superseded: list[str] = []
    categories: dict[str, int] = defaultdict(int)
    made_dirs: set[Path] = set()
    (OUT_DIR / "unmatched").mkdir(parents=True, exist_ok=True)
    for src in sources:
        try:
            header = M.parse_header(src)
        except ValueError as e:
            skipped.append(f"{src.relative_to(ROOT)}: {e}")
            continue
        module, start, end = header["module"], header["start"], header["end"]
        if module not in modules:
            skipped.append(f"{src.relative_to(ROOT)}: unknown module {module}")
            continue
        span = end - start
        wip = src.is_relative_to(ROOT / "wip")
        # The ledger functions this header covers (hstcov.py's rule: it starts at the header, or lies
        # inside its span). Computed first because a wip/ draft can be superseded by the installed src/
        # source of the same function, and then it must not become a unit at all: two units for one
        # ledger function would count its bytes twice in the report.
        functions = modules[module]
        starts = [f[0] for f in functions]
        window = functions[bisect_left(starts, start):]
        covers = [a for a, b in window if a <= end and (a == start or b <= end)]
        if wip and any(a in covered[module] for a in covers):
            superseded.append(f"{src.relative_to(ROOT)}: same function as an installed src/ source")
            continue
        inside = [(a, b) for a, b in window if a <= end and b <= end]
        artifact = build_dir(src, module) / "text.bin"
        if not artifact.exists():
            skipped.append(f"{src.relative_to(ROOT)}: no {artifact.relative_to(ROOT)} (run hstmatch.py)")
            continue
        text = artifact.read_bytes()
        if len(text) == span:  # the usual case: the object is this one function, hstmatch compares it whole
            offset, size = 0, span
        else:
            compiled = object_symbol(src, module, header["symbol"])
            if compiled is None:
                offset, size = len(text) - span, span
                warnings.append(f"{src.relative_to(ROOT)}: no obj.o, assuming the header symbol starts .text")
            else:
                offset, size = compiled
        # Exactly what hstmatch.py compares: the header span, or the whole compiled function when that is
        # longer. A near miss whose function is shorter than the span is compared as far as it goes.
        base_len = min(len(text) - offset, max(span, size))
        if base_len != span:
            warnings.append(f"{src.relative_to(ROOT)}: compiled function is {size} B, header span {span} B "
                            f"(a near miss); the unit compares {base_len} B")
        base = text[offset:offset + base_len]
        if not inside:
            warnings.append(f"{src.relative_to(ROOT)}: header start=0x{start:08x} is not a ledger function "
                            f"start; using the header symbol name")
        elif len(inside) == 1 and inside[0] != (start, end):
            warnings.append(f"{src.relative_to(ROOT)}: header span 0x{start:08x}-0x{end:08x} is not the "
                            f"ledger function 0x{inside[0][0]:08x}-0x{inside[0][1]:08x}")
        # Both sides name the ledger function(s) of the span; a longer base (near miss) keeps its extra
        # bytes unattributed, exactly the bytes hstmatch.py found unmatched.
        symbols = [(function_name(a), a, b - a) for a, b in inside] or \
                  [(header["symbol"], start, span)]
        base_path, target_path = unit_paths(src)
        if base_path.parent not in made_dirs:
            base_path.parent.mkdir(parents=True, exist_ok=True)
            made_dirs.add(base_path.parent)
        retail = M.module_bytes(cache, module)
        file_offset = retail[1]["file_offset"] + start - retail[1]["start"]
        target = retail[0][file_offset:file_offset + span]
        e_flags = e_flags_of(build_dir(src, module) / "obj.o")
        base_symbols = clamp_symbols(symbols, start, base_len) or [(header["symbol"], start, base_len)]
        write_object(base_path, elf32(start, base, base_symbols, e_flags))
        write_object(target_path, elf32(start, target, clamp_symbols(symbols, start, len(target)), e_flags))
        units.append({
            "name": unit_name(src),
            "path": base_path.relative_to(ROOT).as_posix(),
            "target_path": target_path.relative_to(ROOT).as_posix(),
            "metadata": {"complete": not wip, "module_name": module, "module_id": module,
                         "progress_categories": [module]},
        })
        covered[module].update(covers)
        categories[module] += 1
    # Phase 2: the functions no source covers, as one target-only unit per module, so that the report
    # totals cover the whole ledger. The base side is an empty object, so each function is unmatched.
    empty = OUT_DIR / "empty.base.o"
    empty.parent.mkdir(parents=True, exist_ok=True)
    write_object(empty, elf32(0, b"", []))
    unmatched_counts: dict[str, int] = {}
    # A subset run must not touch `unmatched/*.o`: those objects depend on which sources were generated,
    # so writing them from a subset would corrupt the full project's report (its unmatched unit would
    # then hold almost the whole module) until the next full `generate`. The subset project simply has no
    # unmatched units, and `check` therefore cannot compare its totals with hstcov.
    subset = bool(args.only)
    for module, functions in ([] if subset else sorted(modules.items())):
        missing = [f for f in functions if f[0] not in covered[module]]
        if not missing:
            continue
        lo, hi = missing[0][0], max(f[1] for f in missing)
        data, segment = M.module_bytes(cache, module)
        offset = segment["file_offset"] + lo - segment["start"]
        text = data[offset:offset + hi - lo]
        symbols = [(function_name(f[0]), f[0], f[1] - f[0]) for f in missing]
        path = OUT_DIR / "unmatched" / f"{module}.target.o"
        write_object(path, elf32(lo, text, symbols))
        units.append({
            "name": f"unmatched/{module}",
            "path": empty.relative_to(ROOT).as_posix(),
            "target_path": path.relative_to(ROOT).as_posix(),
            "metadata": {"auto_generated": True, "module_name": module, "module_id": module,
                         "progress_categories": [module]},
        })
        unmatched_counts[module] = len(missing)
    project = {
        "min_version": "2.0.0",
        # Every object already exists: objdiff must not try to run a build system of ours.
        "build_base": False,
        "build_target": False,
        "watch_patterns": ["src/**/*.c", "src/**/*.cpp", "wip/**/*.c", "wip/**/*.cpp", "include/**/*.h"],
        "progress_categories": [{"id": name, "name": name} for name in sorted(modules)],
        "options": OPTIONS,
        "units": units,
    }
    if not subset:  # a debug subset must not delete the other units' objects
        keep = {ROOT / u["path"] for u in units} | {ROOT / u["target_path"] for u in units} | {empty}
        for stale in OUT_DIR.rglob("*.o"):
            if stale not in keep:
                stale.unlink()
    out = Path(args.out)
    if not out.is_absolute():
        out = ROOT / out
    out.write_text(json.dumps(project, indent=1) + "\n", encoding="utf-8")
    SUMMARY_FILE.write_text(json.dumps({
        "project": out.relative_to(ROOT).as_posix() if out.is_relative_to(ROOT) else str(out),
        "units": len(units),
        "source_units": sum(categories.values()),
        "unmatched_units": 0 if subset else len(unmatched_counts),
        "sources_by_module": dict(sorted(categories.items())),
        "unmatched_functions_by_module": unmatched_counts,
        "superseded_wip": superseded,
        "warnings": warnings,
        "skipped": skipped,
    }, indent=1) + "\n", encoding="utf-8")
    print(f"{out.relative_to(ROOT)}: {len(units)} units "
          f"({sum(categories.values())} sources, {len(unmatched_counts)} unmatched-function units)")
    for module, n in sorted(categories.items()):
        print(f"  {module:28} {n:6} source units, {unmatched_counts.get(module, 0):6} unmatched functions")
    if warnings and not args.quiet:
        print(f"{len(warnings)} warning(s):")
        for w in warnings[:20]:
            print(f"  {w}")
        if len(warnings) > 20:
            print(f"  ... and {len(warnings) - 20} more (see {SUMMARY_FILE.relative_to(ROOT)})")
    for note in superseded:
        print(f"  superseded: {note}")
    if skipped:
        print(f"{len(skipped)} source(s) skipped:", file=sys.stderr)
        for s in skipped[:10]:
            print(f"  {s}", file=sys.stderr)
        if len(skipped) > 10:
            print(f"  ... and {len(skipped) - 10} more (see {SUMMARY_FILE.relative_to(ROOT)})",
                  file=sys.stderr)
    return 0


def objdiff_cli(configured: str | None) -> Path:
    for candidate in ([configured] if configured else CLI_CANDIDATES):
        path = Path(candidate)
        if not path.is_absolute():
            path = ROOT / path
        if path.exists():
            return path
    raise SystemExit("no objdiff-cli found: install a release into try/objdiff-bin/ (see docs/OBJDIFF.md) "
                     "or pass --objdiff-cli")


def run_cli(cli: Path, argv: list[str]) -> str:
    result = subprocess.run([str(cli), *argv], capture_output=True, text=True, encoding="utf-8",
                            errors="replace")
    if result.returncode != 0:
        raise SystemExit(f"{cli.name} {' '.join(argv)} failed ({result.returncode}):\n{result.stderr[-2000:]}")
    return result.stdout


def report(cli: Path, project: Path) -> dict:
    text = run_cli(cli, ["report", "generate", "-p", str(project), "-o", "-", "--format", "json"])
    return json.loads(text[text.index("{"):])


def unit_diff(cli: Path, unit: dict, symbol: str) -> dict:
    """`diff -1 <target> -2 <base>` returns 'left' = retail and 'right' = our object."""
    config = [arg for key, value in OPTIONS.items() for arg in ("-c", f"{key}={value}")]
    text = run_cli(cli, ["diff", "-1", str(unit["target_path"]), "-2", str(unit["path"]), "-o", "-",
                         "--format", "json", *config, symbol])
    return json.loads(text[text.index("{"):])


def unit_differences(cli: Path, unit: dict) -> tuple[set[int], set[int], set[int]]:
    """(addresses objdiff finds different, addresses it aligns as added or removed, addresses it cannot
    compare because our function is shorter).

    A near miss whose compiled function is shorter than the ledger function has no instructions for the
    remaining words, while hstdiff.py still prints them against a missing counterpart.
    """
    found: set[int] = set()
    structural: set[int] = set()
    absent: set[int] = set()
    for function in unit["functions"]:
        diff = unit_diff(cli, unit, function["name"])
        value, extra = differing_instructions(diff)
        found |= value
        structural |= extra
        ours = {s["name"]: s for s in diff["right"]["symbols"] if s.get("kind") == "SYMBOL_FUNCTION"}
        for target in diff["left"]["symbols"]:
            if target.get("kind") != "SYMBOL_FUNCTION" or target.get("address") is None:
                continue
            have = int(ours.get(target["name"], {}).get("size") or 0)
            want = int(target.get("size") or 0)
            address = int(target["address"])
            absent |= {address + 4 * i for i in range((have + 3) // 4, (want + 3) // 4)}
    return found, structural, absent


def differing_instructions(diff: dict) -> tuple[set[int], set[int]]:
    """Addresses objdiff reports as different, as (instructions whose contents differ, instructions it
    aligns as extra or missing).

    objdiff aligns the two streams, so an instruction it marks as inserted (or deleted) sits at the
    address where it was inserted, which can be a position whose bytes happen to equal the other side's:
    only the first group is a claim about the bytes themselves. Addresses come from the symbols both
    sides share, so they are comparable with the fixed-stride objdump output.
    """
    value: set[int] = set()
    structural: set[int] = set()
    for side in ("left", "right"):
        for symbol in diff.get(side, {}).get("symbols", []):
            for row in symbol.get("instructions", []):
                kind = row.get("diff_kind")
                if kind in (None, "DIFF_NONE"):
                    continue
                address = row.get("instruction", {}).get("address")
                if address is None:
                    continue
                (structural if kind in ("DIFF_INSERT", "DIFF_DELETE") else value).add(int(address))
    return value, structural


def elf_text(path: Path) -> tuple[int, bytes]:
    """(address, bytes) of a generated object's code section."""
    blob = path.read_bytes()
    section = {name: s for name, s in M.elf_sections(blob)}[".text"]
    return section[3], blob[section[4]:section[4] + section[5]]


def differing_words(unit: dict) -> set[int]:
    """Addresses where our object's bytes and retail's differ, compared word by word (the fixed-stride
    view hstdiff.py and hstmatch.py use). Words only one side has count as differing too."""
    our_address, our_text = elf_text(unit["path"])
    target_address, target_text = elf_text(unit["target_path"])
    words = max(len(our_text), len(target_text)) // 4
    differing = set()
    for index in range(words):
        offset = 4 * index
        ours = our_text[offset:offset + 4]
        theirs = target_text[offset:offset + 4]
        if ours != theirs:
            differing.add(target_address + offset)
    return differing


def unexplained_differences(unit: dict, addresses: set[int]) -> tuple[int, list[int]]:
    """Split hstdiff.py's differences objdiff did not report into (outside one of the objects, the rest).

    The rest are words whose bytes differ where objdiff, which aligns the two instruction streams and
    compares branches by the instruction they reach, sees the same instruction: a shifted branch target
    or a realignment. They are reported as a count, not as a failure.
    """
    our_address, our_text = elf_text(unit["path"])
    target_address, target_text = elf_text(unit["target_path"])
    outside = 0
    rest = []
    for address in sorted(addresses):
        if not (0 <= address - our_address <= len(our_text) - 4 and
                0 <= address - target_address <= len(target_text) - 4):
            outside += 1
        else:
            rest.append(address)
    return outside, rest


def hstdiff_differences(source: Path) -> set[int]:
    """Retail addresses hstdiff.py marks as different (its '**' lines), at a fixed 4-byte stride."""
    result = subprocess.run([sys.executable, str(ROOT / "tools" / "hstdiff.py"), str(source)],
                            capture_output=True, text=True, encoding="utf-8", errors="replace")
    if result.returncode != 0:
        raise SystemExit(f"hstdiff.py failed on {source}:\n{result.stdout[-1000:]}{result.stderr[-1000:]}")
    out = set()
    for line in result.stdout.splitlines():
        parts = line.split()
        if line.startswith("**") and len(parts) >= 2:
            try:
                out.add(int(parts[1], 16))
            except ValueError:
                pass
    return out


def hstcov_totals(cli_out: Path) -> dict:
    subprocess.run([sys.executable, str(ROOT / "tools" / "hstcov.py"), "--json", str(cli_out)],
                   capture_output=True, text=True, check=True)
    rows = json.loads(cli_out.read_text(encoding="utf-8"))
    return {row["module"]: row for row in rows}


def check(args: argparse.Namespace) -> int:
    cli = objdiff_cli(args.objdiff_cli)
    project = Path(args.out)
    if not project.is_absolute():
        project = ROOT / project
    if not project.exists():
        raise SystemExit(f"{project} does not exist: run `python tools/hstobjdiff.py` first")
    data = report(cli, project.parent)
    units = {u["name"]: u for u in data["units"]}
    # The per-unit diff needs the objects themselves (a symbol argument too); the project file has them.
    project_units = {}
    for entry in json.loads(project.read_text(encoding="utf-8"))["units"]:
        project_units[entry["name"]] = {
            "name": entry["name"],
            "path": (ROOT / entry["path"]).resolve(),
            "target_path": (ROOT / entry["target_path"]).resolve(),
            "functions": units.get(entry["name"], {}).get("functions", []),
        }
    failures: list[str] = []
    # 1. totals against hstcov.py (the same ledger functions, counted per module). The comparison is
    # structural: total_code is the sum of every ledger function's size, and complete_code is the sum
    # over the units marked complete, i.e. the sources installed in src/. matched_code counts the bytes
    # of fully matched functions in every unit; a wip/ near miss is never fully matched, so the two are
    # equal unless something outside src/ reports a full match.
    cov = hstcov_totals(OUT_DIR / "hstcov.json")
    categories = {c["id"]: c for c in data.get("categories", [])}
    mismatch = 0
    for module, row in sorted(cov.items()):
        if module == "ALL":
            continue
        category = categories.get(module)
        if category is None:
            continue
        measures = category["measures"]
        complete = int(measures.get("complete_code", 0))
        total = int(measures.get("total_code", 0))
        if (complete, total) != (row["exact_bytes"], row["code_bytes"]):
            mismatch += 1
            failures.append(f"{module}: objdiff complete {complete}/{total} B, hstcov "
                            f"{row['exact_bytes']}/{row['code_bytes']} B")
    all_row = cov["ALL"]
    overall = data["measures"]
    complete = int(overall.get("complete_code", 0))
    total = int(overall["total_code"])
    matched = int(overall.get("matched_code", 0))
    print(f"totals: complete {complete}/{total} B, matched {matched}/{total} B, "
          f"hstcov {all_row['exact_bytes']}/{all_row['code_bytes']} B ({all_row['pct_bytes']}%)")
    if matched != complete:
        print(f"  ({matched - complete} B are matched in units outside src/, which hstcov.py does not count; "
              f"complete_code is the hstcov-comparable figure)")
    if complete != all_row["exact_bytes"] or total != all_row["code_bytes"]:
        failures.append(f"totals: objdiff complete {complete}/{total} B, hstcov "
                        f"{all_row['exact_bytes']}/{all_row['code_bytes']} B")
    print(f"functions: matched {overall.get('matched_functions')}/{overall.get('total_functions')}, "
          f"hstcov {all_row['exact']}/{all_row['functions']}")
    if int(overall.get("matched_functions", -1)) != all_row["exact"]:
        failures.append(f"matched functions {overall.get('matched_functions')} != hstcov {all_row['exact']}")
    # 2. every src/ unit is a full match
    src_units = [name for name in units if name.startswith("src/")]
    wip_units = [name for name in units if name.startswith("wip/")]
    sample = src_units if args.random == 0 else random.Random(0).sample(
        src_units, min(args.random, len(src_units)))
    bad = [name for name in sample
           if units[name]["measures"].get("matched_code") != units[name]["measures"].get("total_code")]
    print(f"src units: {len(sample)} checked, {len(bad)} not 100%")
    for name in bad[:10]:
        failures.append(f"{name}: {units[name]['measures'].get('matched_code')}/"
                        f"{units[name]['measures'].get('total_code')} B matched")
    # 3. wip/ near misses are below 100%, and their differing instructions match hstdiff.py
    if args.wip:
        for name in wip_units:
            measures = units[name]["measures"]
            if int(measures.get("matched_code") or 0) == int(measures.get("total_code") or 0):
                failures.append(f"{name}: wip near miss reports 100% (hstmatch.py says it differs; see "
                                f"docs/OBJDIFF.md)")
                continue
            objdiff_diffs, structural, absent = unit_differences(cli, project_units[name])
            hstdiff_diffs = hstdiff_differences(ROOT / f"{name}.cpp" if (ROOT / f"{name}.cpp").exists()
                                                else ROOT / f"{name}.c")
            unit = project_units[name]
            raw = differing_words(unit)
            # hstdiff.py disassembles the whole of hstmatch's text.bin and the whole retail span and
            # prints the longer of the two, so bytes our object holds beyond the ledger function show up
            # as marks with nothing opposite them. They are outside the compared range: ignore them.
            target_address, target_text = elf_text(unit["target_path"])
            beyond = {a for a in hstdiff_diffs if a >= target_address + len(target_text)}
            hstdiff_diffs = hstdiff_diffs - beyond
            outside, missing = unexplained_differences(unit, (hstdiff_diffs - absent) - objdiff_diffs)
            print(f"  {name}: objdiff {measures.get('matched_code') or 0}/{measures.get('total_code')} B, "
                  f"{len(objdiff_diffs)} differing and {len(structural)} added/removed instructions, "
                  f"hstdiff {len(hstdiff_diffs)} of {len(raw)} differing words"
                  f"{f' ({len(beyond)} hstdiff marks are beyond the compared range)' if beyond else ''}"
                  f"{f', {outside} lie outside one of the objects' if outside else ''}"
                  f"{f', {len(missing)} differ only in a branch target or alignment' if missing else ''}")
            if not objdiff_diffs and not structural:
                failures.append(f"{name}: objdiff reports no differing instruction at all")
            if not raw:
                failures.append(f"{name}: the generated objects do not differ at all")
            # Every instruction objdiff reports as different must sit on a word that really differs or
            # immediately next to one (it aligns the two instruction streams, so a reordered block puts
            # a mark one instruction away), and hstdiff.py must be looking at the bytes the generator
            # wrote: a mark from either that is nowhere near a difference is a bug in the units.
            for address in sorted(objdiff_diffs):
                if min(abs(address - a) for a in raw) > 4:
                    failures.append(f"{name}: objdiff marks 0x{address:08x}, far from any differing word")
            for address in sorted((hstdiff_diffs - absent) - raw):
                failures.append(f"{name}: hstdiff.py marks 0x{address:08x}, where the objects are equal")
    if mismatch:
        failures.append(f"{mismatch} module(s) disagree with hstcov.py")
    if failures:
        print(f"FAIL: {len(failures)} problem(s)", file=sys.stderr)
        for f in failures[:20]:
            print(f"  {f}", file=sys.stderr)
        return 1
    print("OK: objdiff agrees with hstmatch.py and hstcov.py")
    return 0


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="command")
    gen = sub.add_parser("generate", help="write objdiff.json and build/objdiff/")
    gen.add_argument("--only", action="append", metavar="GLOB",
                     help="restrict to sources matching this glob (repeatable; for debugging)")
    gen.add_argument("--no-wip", action="store_true", help="leave wip/ near misses out of the project")
    gen.add_argument("--quiet", action="store_true")
    chk = sub.add_parser("check", help="verify the project with objdiff-cli against hstmatch/hstcov")
    chk.add_argument("--random", type=int, default=30,
                     help="how many random src/ units to check (0 = all of them)")
    chk.add_argument("--wip", action="store_true", help="also check every wip/ unit (runs hstdiff.py)")
    chk.add_argument("--objdiff-cli", help="path to objdiff-cli (default: try/objdiff-bin/objdiff-cli.exe)")
    # --out is accepted before and after the subcommand: the subparser copies use SUPPRESS so that they
    # only override the top-level value when the option is actually given.
    ap.add_argument("--out", default="objdiff.json", metavar="FILE",
                    help="project file to write or check (default: objdiff.json)")
    gen.add_argument("--out", default=argparse.SUPPRESS, metavar="FILE",
                     help="project file to write (default: objdiff.json)")
    chk.add_argument("--out", default=argparse.SUPPRESS, metavar="FILE",
                     help="project file to check (default: objdiff.json)")
    args = ap.parse_args()
    if args.command == "check":
        return check(args)
    args.only = getattr(args, "only", None)
    args.no_wip = getattr(args, "no_wip", False)
    args.quiet = getattr(args, "quiet", False)
    return generate(args)


if __name__ == "__main__":
    raise SystemExit(main())
