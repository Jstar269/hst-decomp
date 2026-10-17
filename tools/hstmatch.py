#!/usr/bin/env python3
"""Private HST decomp matcher: compile, link at the retail address, compare bytes exactly.

Each source file starts with a header comment:
    /* HSTMATCH module=EBOOT.BIN start=0x001a4bc8 end=0x001a4c1c symbol=FUN_001a4bc8 lang=c99 */
Optional keys: rodata=0xADDR (place .rodata), extra="..." (experimental extra compiler flags;
a source that needs extra flags is reported as such, never as a profile match).

Build: mwccpsp (decomp.me build, run with wibo in WSL) -> object; PSPDEV psp-ld links the object
with .text at `start` and defines only the object's undefined symbols from symbols/<module>.txt;
psp-objcopy extracts the bytes. The linked bytes must equal the retail bytes [start, end) exactly.
No masking: every relocated field is produced by the linker from the symbol map.

Usage: hstmatch.py [paths...]   (default: every source under src/)
"""
from __future__ import annotations

import argparse
import json
import os
import re
import shlex
import struct
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(Path(__file__).resolve().parent))
import hstconfig as CFG  # noqa: E402

# Machine-specific locations (campaign root, PSPDEV binutils, compiler kits) come from hst-config.json
# (see tools/hstconfig.py). They are looked up when first used, so `--help` and the local tools work
# without a configuration; `M.CAMPAIGN`, `M.PSPDEV_BIN`, `M.NATIVE`, `M.GCC_HOME` and `M.GCC_PROFILES` stay
# available to the other tools as lazy attributes.
PROFILE = {
    "build": "219",
    # Strength reduction is a per-object setting in the retail build (index-recompute loops cluster
    # in address runs, 3:1 minority): sources from those objects carry
    # `#pragma opt_strength_reduction off` themselves.
    "flags": '-c -O4,p -sdatathreshold 0',
}
HEADER = re.compile(r"/\*\s*HSTMATCH\s+(.*?)\*/", re.S)
# SDK objects are GCC output: the decomp.me Sony psp-gcc kits (i386 Linux, native WSL copies under the
# configured gcc_home). Header `cc=<profile>` selects one; flags are provisional until the SDK profile is settled.
# -fno-merge-constants: GCC's mergeable literal sections (.rodata.cst4/8, .rodata.str1.4) become plain
# .rodata, which `rodata=` places; it changes section layout only, never the code (all GCC matches were
# re-verified with it).
GCC_PROFILE_NAMES = frozenset(f"gcc{v}{x}-{o}" for v in ("131", "171") for o in ("O1", "O2", "O3", "Os")
                              for x in ("", "x"))  # gcc171x-*: Allegrex ext/ins enabled
_gcc_profiles: dict | None = None


def campaign_root() -> Path:
    return CFG.host_path("campaign_root")


def pspdev_bin() -> str:
    return CFG.wsl_path("pspdev_bin")


def native_dir() -> str:
    """WSL directory with the native-filesystem copy of wibo + builds/<build>/mwccpsp.exe."""
    return CFG.wsl_path("mwcc_native")


def gcc_home() -> str:
    return CFG.wsl_path("gcc_home")


def gcc_profiles() -> dict:
    global _gcc_profiles
    if _gcc_profiles is None:
        home = gcc_home()
        driver = f"{home}/psp-gcc-1.3.1/bin/psp-gcc"
        b = {"131": None, "171": f"{home}/psp-gcc-1.7.1/lib/gcc-lib/psp/3.3.3+allegrex-2.2.2-psp-1.7.1/"}
        _gcc_profiles = {f"gcc{v}{x}-{o}": {"driver": driver, "B": b[v], "flags": f"-{o} -G0 -fno-merge-constants{xf}"}
                         for v in b for o in ("O1", "O2", "O3", "Os") for x, xf in (("", ""), ("x", " -mext"))}
        assert set(_gcc_profiles) == GCC_PROFILE_NAMES
    return _gcc_profiles


def __getattr__(name: str):  # PEP 562: lazy module attributes (the old constants)
    getters = {"CAMPAIGN": campaign_root, "PSPDEV_BIN": pspdev_bin, "NATIVE": native_dir, "GCC_HOME": gcc_home,
               "GCC_PROFILES": gcc_profiles}
    if name in getters:
        return getters[name]()
    raise AttributeError(f"module {__name__!r} has no attribute {name!r}")


def to_wsl(path: Path) -> str:
    p = str(path.resolve()).replace("\\", "/")
    return f"/mnt/{p[0].lower()}{p[2:]}"


def parse_header(path: Path) -> dict:
    m = HEADER.search(path.read_text(encoding="utf-8", errors="replace")[:2000])
    if not m:
        raise ValueError(f"{path}: missing HSTMATCH header")
    fields = dict(re.findall(r'(\w+)=("[^"]*"|\S+)', m.group(1)))
    fields = {k: v.strip('"') for k, v in fields.items()}
    for key in ("module", "start", "end", "symbol"):
        if key not in fields:
            raise ValueError(f"{path}: header lacks {key}")
    fields["start"] = int(fields["start"], 16)
    fields["end"] = int(fields["end"], 16)
    fields.setdefault("lang", "c++" if path.suffix == ".cpp" else "c99")
    return fields


EXTRA_SYMBOLS: list[Path] = []  # --symbols-extra: candidate entries tried for one run only


def load_symbols(module: str) -> dict[str, int]:
    out: dict[str, int] = {}
    for path in [ROOT / "symbols" / f"{module}.txt", *EXTRA_SYMBOLS]:
        if not path.exists():
            continue
        for line in path.read_text(encoding="utf-8").splitlines():
            line = line.split("#", 1)[0].strip()
            if not line:
                continue
            m = re.fullmatch(r"(\S+)\s*=\s*(0x[0-9A-Fa-f]+)\s*;?", line)
            if not m:
                raise ValueError(f"bad symbol line in {path}: {line}")
            if m.group(1) in out and out[m.group(1)] != int(m.group(2), 16):
                raise ValueError(f"conflicting symbol {m.group(1)} in {path}")
            out[m.group(1)] = int(m.group(2), 16)
    return out


def default_address(name: str) -> int | None:
    """FUN_/DAT_/LAB_ names carry their address; everything else must be in the symbol map."""
    m = re.fullmatch(r"(?:FUN|DAT|LAB|PTR|jtbl)_([0-9a-fA-F]{8})", name)
    return int(m.group(1), 16) if m else None


def elf_sections(obj: bytes):
    shoff, = struct.unpack_from("<I", obj, 0x20)
    shentsize, shnum, shstrndx = struct.unpack_from("<HHH", obj, 0x2E)
    secs = [struct.unpack_from("<IIIIIIIIII", obj, shoff + i * shentsize) for i in range(shnum)]
    names = secs[shstrndx]
    named = []
    for s in secs:
        n = obj[names[4] + s[0]:obj.index(b"\0", names[4] + s[0])].decode()
        named.append((n, s))
    return named


def elf_symbols(obj: bytes):
    secs = [s for _, s in elf_sections(obj)]
    symtab = next(s for s in secs if s[1] == 2)
    strtab = secs[symtab[6]]
    for i in range(symtab[5] // 16):
        st_name, value, size, info, other, shndx = struct.unpack_from("<IIIBBH", obj, symtab[4] + i * 16)
        name = obj[strtab[4] + st_name:obj.index(b"\0", strtab[4] + st_name)].decode()
        yield name, value, size, info, shndx


def module_bytes(cache: dict, module: str):
    if module not in cache:
        if "_ledger" not in cache:
            campaign = campaign_root()
            cache["_ledger"] = json.loads((campaign / "ledger" / "campaign.json").read_text(encoding="utf-8-sig"))
            cache["_selection"] = json.loads((campaign / "inputs" / "revision-selection.json").read_text(encoding="utf-8-sig"))
        mod = next(m for m in cache["_ledger"]["modules"] if m["name"] == module)
        data = (Path(cache["_selection"]["roots"][mod["input"]["root"]]) / mod["input"]["path"]).read_bytes()
        seg = next(s for s in mod["load_segments"] if s["flags"] & 1)
        cache[module] = (data, seg)
    return cache[module]


PLACED_WITH_CONTENTS = (".rodata", ".data", ".sdata")


def target_references(obj: bytes, h: dict):
    """(undefined names, section names) that relocations INSIDE the compared function refer to, or
    (None, None) when that cannot be determined (then every name and section is required, as before).
    The compared function is the header symbol, over max(its size, the header span)."""
    sections = elf_sections(obj)
    names = [n for n, _ in sections]
    if ".text" not in names:
        return None, None
    ti = names.index(".text")
    symbols = list(elf_symbols(obj))
    sym = next(((v, s) for n, v, s, i, sh in symbols if n == h["symbol"] and sh == ti), None)
    if sym is None:
        return None, None
    lo, hi = sym[0], sym[0] + max(sym[1], h["end"] - h["start"])
    ref_names, ref_sections = set(), set()
    for n, s in sections:
        if s[1] != 9 or s[7] != ti:  # SHT_REL applying to .text
            continue
        for k in range(s[5] // 8):
            off, info = struct.unpack_from("<II", obj, s[4] + k * 8)
            if not lo <= off < hi:
                continue
            name, value, size, sinfo, shndx = symbols[info >> 8]
            if shndx == 0:
                ref_names.add(name)
            elif 0 < shndx < len(names):
                ref_sections.add(names[shndx])
    if any(s[1] == 4 and s[7] == ti for _, s in sections):  # SHT_RELA: not produced by these compilers
        return None, None
    return ref_names, ref_sections


def placed_section_differs(h: dict, out: Path, data: bytes, seg: dict, expected: list[str]) -> str:
    """'' when every placed section with contents equals the retail bytes at its header address."""
    for sec in expected:
        key = sec.strip(".")
        blob = out / f"{key}.bin"
        if not blob.exists():
            return f"{sec} was not extracted"
        ours = blob.read_bytes()
        addr = int(h[key], 16)
        off = seg["file_offset"] + addr - seg["start"]
        if data[off:off + len(ours)] != ours:
            return f"{sec} ({len(ours)} bytes at 0x{addr:08x}) differs from retail"
    return ""


def run_wsl(lines: list[str], name: str, native: str | None = None) -> None:
    # Per-process script names, so independent runs (on different sources) can overlap. `native` is exported
    # as $N for the MWCC command lines.
    script = ROOT / "build" / f"{name}.{os.getpid()}.sh"
    prologue = ["#!/bin/sh"] + (["export N=" + native] if native else [])
    script.write_text("\n".join(prologue + lines) + "\n", encoding="utf-8", newline="\n")
    try:
        subprocess.run(["wsl.exe", "-e", "sh", to_wsl(script)], check=False)
    finally:
        script.unlink(missing_ok=True)


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("paths", nargs="*", type=Path)
    ap.add_argument("--parallel", type=int, default=6)
    ap.add_argument("--quiet", action="store_true")
    ap.add_argument("--json", type=Path)
    ap.add_argument("--all", action="store_true", help="rebuild every source under src/")
    ap.add_argument("--flags", help="experimental: override the profile flags (results are not profile matches)")
    ap.add_argument("--symbols-extra", type=Path, action="append", default=[],
                    help="extra 'name = 0xaddr;' entries for this run (results are not committed symbols)")
    args = ap.parse_args()
    EXTRA_SYMBOLS.extend(args.symbols_extra)
    flags = args.flags if args.flags is not None else PROFILE["flags"]
    if not args.paths and not args.all:
        raise SystemExit("no sources given: pass files, or --all to rebuild every source under src/ "
                         "(a full rebuild shares build/ with any concurrent run)")
    paths = args.paths or sorted(p for p in (ROOT / "src").rglob("*") if p.suffix in (".c", ".cpp"))
    jobs = []
    for p in paths:
        h = parse_header(p)
        out = ROOT / "build" / h["module"] / f"{p.resolve().parent.name}__{p.stem}"
        out.mkdir(parents=True, exist_ok=True)
        for f in out.glob("*"):
            f.unlink()
        jobs.append((p, h, out))
    # 1. compile (parallel)
    cmds = []
    native = None
    for p, h, out in jobs:
        extra = h.get("extra", "")
        log = shlex.quote(to_wsl(out / 'compile.log'))
        obj = shlex.quote(to_wsl(out / 'obj.o'))
        cc = h.get("cc", "mwcc219")
        if cc in GCC_PROFILE_NAMES:
            g = gcc_profiles()[cc]
            gflags = args.flags if args.flags is not None else g["flags"]
            lang = "-x c++" if h["lang"] == "c++" else "-x c"
            bprefix = f"-B {g['B']} " if g["B"] else ""
            # the i386 compiler cannot stat files on /mnt/c (64-bit inode numbers: EOVERFLOW), so it
            # compiles a copy in a native temporary directory
            cmds.append(f"t=$(mktemp -d /tmp/hstgcc.XXXXXX) && cp {shlex.quote(to_wsl(p))} $t/ && cd $t && "
                        f"{g['driver']} {bprefix}-c {gflags} {lang} {extra} -o obj.o {shlex.quote(p.name)} "
                        f"> log 2>&1; cp log {log}; [ -f obj.o ] && cp obj.o {obj}; cd / && rm -rf $t")
            continue
        if cc != "mwcc219":
            raise SystemExit(f"{p}: unknown compiler profile cc={cc}")
        native = native_dir()
        cmds.append(f"cd {shlex.quote(to_wsl(p.parent))} && MWCIncludes={shlex.quote(to_wsl(ROOT / 'include'))} "
                    f"$N/wibo $N/builds/{PROFILE['build']}/mwccpsp.exe {flags} -lang {h['lang']} {extra} "
                    f"-o {obj} {shlex.quote(p.name)} > {log} 2>&1")
    jobfile = ROOT / "build" / f"compile.{os.getpid()}.jobs"
    jobfile.write_text("\n".join(cmds) + "\n", encoding="utf-8", newline="\n")
    try:
        run_wsl([f"tr '\\n' '\\0' < {shlex.quote(to_wsl(jobfile))} | xargs -0 -P {args.parallel} -n 1 sh -c"], "compile", native)
    finally:
        jobfile.unlink(missing_ok=True)
    # 2. link each object at its retail address with only the symbols it needs
    symcache: dict[str, dict[str, int]] = {}
    link = []
    results = {}
    expected_sections: dict = {}
    text_off: dict = {}
    for p, h, out in jobs:
        obj_path = out / "obj.o"
        if not obj_path.exists():
            results[p] = ("COMPILE_FAILED", (out / "compile.log").read_text(errors="replace")[-600:])
            continue
        obj = obj_path.read_bytes()
        syms = symcache.setdefault(h["module"], load_symbols(h["module"]))
        undefined = sorted({n for n, v, s, i, sh in elf_symbols(obj) if sh == 0 and n})
        # Names and sections reached only by OTHER functions of the object (a library file compiled whole)
        # cannot change the compared bytes: such names get a placeholder and such sections stay unplaced.
        ref_names, ref_sections = target_references(obj, h)
        defs, missing = [], []
        for n in undefined:
            addr = syms.get(n, default_address(n))
            if addr is None and ref_names is not None and n not in ref_names:
                defs.append(f"{n} = 0x00000000;   /* not referenced by the compared function */")
                continue
            (defs.append(f"{n} = 0x{addr:08x};") if addr is not None else missing.append(n))
        if missing:
            results[p] = ("MISSING_SYMBOLS", " ".join(missing))
            continue
        sections = {n: s for n, s in elf_sections(obj)}
        # the target need not be the object's first function (a library file compiled whole): .text is
        # placed so that the target lands at its retail address, and the rest of the object around it
        names = [n for n, _ in elf_sections(obj)]
        text_idx = names.index(".text") if ".text" in names else -1
        text_off[p] = next((v for n, v, s, i, sh in elf_symbols(obj) if n == h["symbol"] and sh == text_idx), 0)
        placed = [f"-Ttext=0x{h['start'] - text_off[p]:08x}"]
        for sec in (".rodata", ".data", ".sdata", ".sbss", ".bss"):
            if sec in sections and sections[sec][5]:
                key = sec.strip(".")
                if key not in h and ref_sections is not None and sec not in ref_sections:
                    continue  # unreferenced by the compared function: left where ld puts it, not compared
                if key not in h:
                    results[p] = ("UNPLACED_SECTION", f"{sec} ({sections[sec][5]} bytes) needs {key}=0x... in the header")
                    break
                placed.append(f"--section-start {sec}=0x{int(h[key], 16):08x}")
        if p in results:
            continue
        (out / "syms.ld").write_text("\n".join(defs) + "\n", encoding="utf-8", newline="\n")
        # placed sections with contents are extracted too and must equal the retail bytes at their address
        expected_sections[p] = [sec for sec in PLACED_WITH_CONTENTS if sec in sections and sections[sec][5]
                                and sec.strip(".") in h]
        pspdev = pspdev_bin()
        extract = "".join(f" && {pspdev}/psp-objcopy -O binary -j {sec} {to_wsl(out / 'linked.elf')} "
                          f"{to_wsl(out / (sec.strip('.') + '.bin'))}" for sec in expected_sections[p])
        link.append(f"{pspdev}/psp-ld -EL -e 0x{h['start']:08x} {' '.join(placed)} -o {to_wsl(out / 'linked.elf')} "
                    f"{to_wsl(obj_path)} {to_wsl(out / 'syms.ld')} > {to_wsl(out / 'link.log')} 2>&1 && "
                    f"{pspdev}/psp-objcopy -O binary -j .text {to_wsl(out / 'linked.elf')} {to_wsl(out / 'text.bin')}"
                    + extract)
    if link:
        run_wsl(link, "link")
    # 3. compare
    cache: dict = {}
    summary = []
    for p, h, out in jobs:
        rel = p.relative_to(ROOT).as_posix() if p.is_relative_to(ROOT) else str(p)
        if p in results:
            status, detail = results[p]
        else:
            data, seg = module_bytes(cache, h["module"])
            off = seg["file_offset"] + h["start"] - seg["start"]
            target = data[off:off + h["end"] - h["start"]]
            text = out / "text.bin"
            if not text.exists():
                status, detail = "LINK_FAILED", (out / "link.log").read_text(errors="replace")[-600:]
            else:
                linked = text.read_bytes()
                elf = (out / "linked.elf").read_bytes()
                sym = [(v, s) for n, v, s, i, sh in elf_symbols(elf) if n == h["symbol"] and sh != 0]
                if not sym:
                    status, detail = "NO_SYMBOL", h["symbol"]
                elif sym[0][0] != h["start"]:
                    status, detail = "MISPLACED", f"{h['symbol']} linked at 0x{sym[0][0]:x}, not at its retail address"
                else:
                    span = h["end"] - h["start"]
                    linked = linked[text_off.get(p, 0):]
                    # a multi-function run (same-file static helpers) compares the whole header span
                    body = linked[:span] if sym[0][1] < span else linked[:sym[0][1]]
                    section_diff = placed_section_differs(h, out, data, seg, expected_sections.get(p, []))
                    if body == target and section_diff:
                        status, detail = "SECTION_MISMATCH", section_diff
                    elif body == target:
                        status, detail = ("EXACT_EXTRA_FLAGS" if h.get("extra") or args.flags is not None else "EXACT"), ""
                    else:
                        n = len(target) // 4
                        diffs = [i for i in range(max(len(body), len(target)) // 4)
                                 if body[i * 4:i * 4 + 4] != target[i * 4:i * 4 + 4]]
                        status = "MISMATCH"
                        detail = f"{len(body)//4}/{n} words; {len(diffs)} differ; first at +0x{diffs[0]*4:x}" if diffs else "size differs"
                        (out / "target.bin").write_bytes(target)
        summary.append({"source": rel, "module": h["module"], "start": f"0x{h['start']:08x}", "status": status, "detail": detail})
        if not args.quiet or status != "EXACT":
            print(f"{status:18s} {h['module']} 0x{h['start']:08x} {rel} {detail}")
    exact = sum(1 for s in summary if s["status"] == "EXACT")
    print(f"EXACT {exact}/{len(summary)}" + (f" (EXACT_EXTRA_FLAGS {sum(1 for s in summary if s['status'] == 'EXACT_EXTRA_FLAGS')} under --flags {flags})" if args.flags is not None else ""))
    if args.json:
        args.json.write_text(json.dumps(summary, indent=1) + "\n", encoding="utf-8")
    return 0 if exact == len(summary) else 1


if __name__ == "__main__":
    raise SystemExit(main())
