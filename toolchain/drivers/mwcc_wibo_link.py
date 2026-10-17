#!/usr/bin/env python3
"""Campaign build driver: one reconstructed function -> its exact linked bytes.

Run by the pinned Python runtime from a function build profile, never through a shell:

    python -I mwcc_wibo_link.py --source <src> --output <bin> --build-dir <dir> --start 0x.. --end 0x..
        --symbol-map <map or ""> --cflags "<flags>"
        --wibo <path> --wibo-sha256 <hex> --compiler <path> --compiler-sha256 <hex>
        --ld <path> --ld-sha256 <hex> --objcopy <path> --objcopy-sha256 <hex>

Steps (each fails closed with a named code on stderr and a non-zero exit):
1. Rehash every component against the digest in argv.
2. Read the source's HSTMATCH header (symbol, start, end, optional lang and section placements). Its start
   and end must equal the runner's; experimental `extra=` flags are refused.
3. Compile in WSL: wibo runs mwccpsp.exe with the profile's flags; MWCIncludes is a directory of the two
   project-authored headers below, written into the build directory.
4. Every undefined symbol of the object must resolve through the symbol map or an address-bearing name
   (FUN_/DAT_/LAB_/PTR_/jtbl_<8 hex>); the two must never disagree.
5. Link with psp-ld at the start address (non-empty data sections need placements), then extract .text
   with psp-objcopy.
6. The function symbol must be defined at the start address with size end - start; write exactly those
   bytes to the output.

Host evidence (not pins): the wsl.exe digest and the distribution's /etc/os-release digest are printed on
stdout, which the build receipt binds by digest.
"""
from __future__ import annotations

import argparse
import hashlib
import os
import re
import struct
import subprocess
import sys
from pathlib import Path

HEADER = re.compile(r"/\*\s*HSTMATCH\s+(.*?)\*/", re.S)
ADDRESS_NAME = re.compile(r"(?:FUN|DAT|LAB|PTR|jtbl)_([0-9a-fA-F]{8})")
MAP_LINE = re.compile(r"(\S+)\s*=\s*(0x[0-9A-Fa-f]+)\s*;?")
PLACEABLE_SECTIONS = (".rodata", ".data", ".sdata", ".sbss", ".bss")
LANGUAGES = {".c": "c99", ".cpp": "c++"}
STEP_TIMEOUT_SECONDS = 120

# Project-authored headers (the compiler packages ship none). Hash-bound with this driver.
HEADERS = {
    "stdint.h": """/* Minimal project-authored stdint.h for 32-bit PSP (Allegrex) probes. */
#ifndef PROBE_STDINT_H
#define PROBE_STDINT_H
typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef short int16_t;
typedef unsigned short uint16_t;
typedef int int32_t;
typedef unsigned int uint32_t;
typedef long long int64_t;
typedef unsigned long long uint64_t;
typedef int intptr_t;
typedef unsigned int uintptr_t;
#endif
""",
    "stddef.h": """/* Minimal project-authored stddef.h for 32-bit PSP (Allegrex) probes. */
#ifndef PROBE_STDDEF_H
#define PROBE_STDDEF_H
typedef unsigned int size_t;
typedef int ptrdiff_t;
#define NULL ((void *)0)
#define offsetof(type, member) ((size_t)&((type *)0)->member)
#endif
""",
}


class DriverError(RuntimeError):
    pass


def fail(code: str, detail: str = "") -> None:
    raise DriverError(f"{code}{': ' + detail if detail else ''}")


def sha256_file(path: Path) -> str:
    digest = hashlib.sha256()
    with path.open("rb") as stream:
        for block in iter(lambda: stream.read(1 << 20), b""):
            digest.update(block)
    return digest.hexdigest()


def to_wsl(path: Path) -> str:
    text = str(path.resolve())
    if not re.fullmatch(r"[A-Za-z]:\\.*", text):
        fail("PATH_NOT_ON_A_DRIVE", text)
    return "/mnt/" + text[0].lower() + text[2:].replace("\\", "/")


def wsl_exe() -> Path:
    system_root = os.environ.get("SystemRoot")
    if not system_root:
        fail("SYSTEMROOT_MISSING")
    path = Path(system_root) / "System32" / "wsl.exe"
    if not path.is_file():
        fail("WSL_UNAVAILABLE")
    return path


def run_wsl(argv: list[str], cwd: Path, log: Path, extra_env: dict[str, str] | None = None) -> int:
    env = {"SystemRoot": os.environ["SystemRoot"], **(extra_env or {})}
    command = [str(wsl_exe()), "--cd", to_wsl(cwd), "-e", *argv]
    try:
        process = subprocess.run(command, env=env, capture_output=True, timeout=STEP_TIMEOUT_SECONDS, check=False)
    except (OSError, subprocess.TimeoutExpired) as exc:
        fail("WSL_STEP_FAILED", type(exc).__name__)
    log.write_bytes(process.stdout + process.stderr)
    return process.returncode


def parse_header(source: Path) -> dict[str, str]:
    match = HEADER.search(source.read_text(encoding="utf-8", errors="strict")[:2000])
    if not match:
        fail("SOURCE_HEADER_MISSING")
    fields = {key: value.strip('"') for key, value in re.findall(r'(\w+)=("[^"]*"|\S+)', match.group(1))}
    for key in ("module", "start", "end", "symbol"):
        if key not in fields:
            fail("SOURCE_HEADER_INCOMPLETE", key)
    if "extra" in fields:
        fail("SOURCE_HEADER_EXTRA_FLAGS_REFUSED")
    return fields


def elf_sections(obj: bytes) -> list[tuple[str, tuple[int, ...]]]:
    if obj[:4] != b"\x7fELF" or obj[4] != 1 or obj[5] != 1:
        fail("NOT_ELF32_LE")
    shoff, = struct.unpack_from("<I", obj, 0x20)
    shentsize, shnum, shstrndx = struct.unpack_from("<HHH", obj, 0x2E)
    sections = [struct.unpack_from("<IIIIIIIIII", obj, shoff + index * shentsize) for index in range(shnum)]
    names = sections[shstrndx]
    named = []
    for section in sections:
        start = names[4] + section[0]
        named.append((obj[start:obj.index(b"\0", start)].decode("ascii"), section))
    return named


def elf_symbols(obj: bytes):
    sections = [section for _name, section in elf_sections(obj)]
    symtabs = [section for section in sections if section[1] == 2]
    if len(symtabs) != 1:
        fail("ELF_SYMTAB_NOT_UNIQUE")
    symtab = symtabs[0]
    strtab = sections[symtab[6]]
    for index in range(symtab[5] // 16):
        st_name, value, size, info, _other, shndx = struct.unpack_from("<IIIBBH", obj, symtab[4] + index * 16)
        start = strtab[4] + st_name
        yield obj[start:obj.index(b"\0", start)].decode("ascii"), value, size, info, shndx


def read_symbol_map(path_text: str) -> dict[str, int]:
    symbols: dict[str, int] = {}
    if not path_text:
        return symbols
    for line in Path(path_text).read_text(encoding="utf-8").splitlines():
        line = line.split("#", 1)[0].strip()
        if not line:
            continue
        match = MAP_LINE.fullmatch(line)
        if not match:
            fail("SYMBOL_MAP_LINE_INVALID", line)
        name, address = match.group(1), int(match.group(2), 16)
        if symbols.get(name, address) != address:
            fail("SYMBOL_MAP_CONFLICT", name)
        implied = ADDRESS_NAME.fullmatch(name)
        if implied and int(implied.group(1), 16) != address:
            fail("SYMBOL_MAP_CONTRADICTS_NAME", name)
        symbols[name] = address
    return symbols


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__.split("\n", 1)[0])
    for name in ("source", "output", "build-dir", "start", "end", "symbol-map", "cflags",
                 "wibo", "wibo-sha256", "compiler", "compiler-sha256",
                 "ld", "ld-sha256", "objcopy", "objcopy-sha256"):
        parser.add_argument(f"--{name}", required=True)
    args = parser.parse_args(argv)
    try:
        build_dir = Path(args.build_dir).resolve(strict=True)
        source = Path(args.source).resolve(strict=True)
        output = Path(args.output).resolve(strict=False)
        start, end = int(args.start, 16), int(args.end, 16)
        if not (0 <= start < end) or start % 4 or end % 4:
            fail("FUNCTION_INTERVAL_INVALID")
        components = {}
        for role in ("wibo", "compiler", "ld", "objcopy"):
            path = Path(getattr(args, role)).resolve(strict=True)
            if sha256_file(path) != getattr(args, f"{role}_sha256"):
                fail("COMPONENT_HASH_MISMATCH", role)
            components[role] = path

        header = parse_header(source)
        if int(header["start"], 16) != start or int(header["end"], 16) != end:
            fail("SOURCE_HEADER_INTERVAL_MISMATCH")
        language = LANGUAGES.get(source.suffix)
        if language is None or header.get("lang", language) != language:
            fail("SOURCE_LANGUAGE_UNSUPPORTED", source.suffix)
        symbol_map = read_symbol_map(args.symbol_map)

        include_dir = build_dir / "include"
        include_dir.mkdir(exist_ok=False)
        for name, text in HEADERS.items():
            (include_dir / name).write_text(text, encoding="ascii", newline="\n")

        obj_path = build_dir / "obj.o"
        status = run_wsl(
            [to_wsl(components["wibo"]), to_wsl(components["compiler"]), *args.cflags.split(),
             "-lang", language, "-o", to_wsl(obj_path), to_wsl(source)],
            build_dir, build_dir / "compile.log",
            {"WSLENV": "MWCIncludes/p", "MWCIncludes": str(include_dir)},
        )
        if status != 0 or not obj_path.is_file():
            fail("COMPILE_FAILED", f"exit {status}")
        obj = obj_path.read_bytes()

        definitions, missing = [], []
        for name in sorted({name for name, _v, _s, _i, shndx in elf_symbols(obj) if shndx == 0 and name}):
            implied = ADDRESS_NAME.fullmatch(name)
            address = symbol_map.get(name, int(implied.group(1), 16) if implied else None)
            if address is None:
                missing.append(name)
            else:
                definitions.append(f"{name} = 0x{address:08x};")
        if missing:
            fail("UNRESOLVED_SYMBOLS", " ".join(missing))
        placements = [f"-Ttext=0x{start:08x}"]
        for name, section in elf_sections(obj):
            if name in PLACEABLE_SECTIONS and section[5]:
                key = name.strip(".")
                if key not in header:
                    fail("UNPLACED_SECTION", name)
                placements += ["--section-start", f"{name}=0x{int(header[key], 16):08x}"]
        script = build_dir / "symbols.ld"
        script.write_text("".join(line + "\n" for line in definitions), encoding="ascii", newline="\n")

        linked = build_dir / "linked.elf"
        status = run_wsl(
            [to_wsl(components["ld"]), "-EL", "-e", f"0x{start:08x}", *placements,
             "-o", to_wsl(linked), to_wsl(obj_path), to_wsl(script)],
            build_dir, build_dir / "link.log",
        )
        if status != 0 or not linked.is_file():
            fail("LINK_FAILED", f"exit {status}")
        text_bin = build_dir / "text.bin"
        status = run_wsl(
            [to_wsl(components["objcopy"]), "-O", "binary", "-j", ".text", to_wsl(linked), to_wsl(text_bin)],
            build_dir, build_dir / "objcopy.log",
        )
        if status != 0 or not text_bin.is_file():
            fail("OBJCOPY_FAILED", f"exit {status}")

        defined = [(value, size) for name, value, size, _i, shndx in elf_symbols(linked.read_bytes())
                   if name == header["symbol"] and shndx != 0]
        if len(defined) != 1:
            fail("FUNCTION_SYMBOL_NOT_UNIQUE", header["symbol"])
        value, size = defined[0]
        if value != start:
            fail("FUNCTION_NOT_AT_START", f"0x{value:08x}")
        if size != end - start:
            fail("FUNCTION_SIZE_MISMATCH", f"{size} != {end - start}")
        body = text_bin.read_bytes()[:size]
        if len(body) != size:
            fail("TEXT_TRUNCATED")
        output.write_bytes(body)

        release = subprocess.run([str(wsl_exe()), "-e", "cat", "/etc/os-release"],
                                 env={"SystemRoot": os.environ["SystemRoot"]}, capture_output=True,
                                 timeout=STEP_TIMEOUT_SECONDS, check=False)
        print(f"HOST_WSL_EXE_SHA256={sha256_file(wsl_exe())}")
        print(f"HOST_WSL_OS_RELEASE_SHA256={hashlib.sha256(release.stdout).hexdigest() if release.returncode == 0 else 'unavailable'}")
        print(f"OBJECT_SHA256={hashlib.sha256(obj).hexdigest()}")
        print(f"RESOLVED_SYMBOLS={len(definitions)}")
        print(f"OUTPUT_BYTES={size}")
        return 0
    except DriverError as exc:
        print(f"BUILD_DRIVER_FAILED={exc}", file=sys.stderr)
        return 2


if __name__ == "__main__":
    raise SystemExit(main())
