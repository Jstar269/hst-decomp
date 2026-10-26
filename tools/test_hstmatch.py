#!/usr/bin/env python3
"""Unit checks of tools/hstmatch.py's same-file helper support (helpers=) that need no toolchain: the header syntax,
the section rename of the placed object copy, and the function-to-section mapping. The end-to-end placement (compile,
link, compare, promotion, refusal of a mismatching helper) is in tools/test_hstpromote.py (HelperPlacement).

    python tools/test_hstmatch.py [-v]
"""
from __future__ import annotations

import os
import struct
import sys
import tempfile
import unittest
from pathlib import Path
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parent))
import hstmatch as M  # noqa: E402


def tiny_object(funcs: list[tuple[str, bytes]], extra_in_first: str | None = None) -> bytes:
    """A little-endian ELF32 relocatable object shaped like mwccpsp output: one `.text` section per function, a symtab
    with one FUNC symbol at offset 0 of each (and optionally a second FUNC symbol in the first section)."""
    names = b"\0.text\0.symtab\0.strtab\0.shstrtab\0"
    n_text, n_sym, n_str, n_shs = 1, 7, 15, 23
    strtab = b"\0"
    syms = [struct.pack("<IIIBBH", 0, 0, 0, 0, 0, 0)]
    blobs, sections = [], [(0, 0, 0, 0, 0, 0, 0, 0, 0, 0)]
    off = 52
    for i, (name, code) in enumerate(funcs):
        blobs.append(code)
        sections.append((n_text, 1, 6, 0, off, len(code), 0, 0, 4, 0))
        off += len(code)
        syms.append(struct.pack("<IIIBBH", len(strtab), 0, len(code), 0x12, 0, i + 1))
        strtab += name.encode() + b"\0"
    if extra_in_first:
        syms.append(struct.pack("<IIIBBH", len(strtab), 4, 4, 0x12, 0, 1))
        strtab += extra_in_first.encode() + b"\0"
    symdata = b"".join(syms)
    for data, sec in ((symdata, (n_sym, 2, 0, 0, 0, len(symdata), len(funcs) + 2, 1, 4, 16)),
                      (strtab, (n_str, 3, 0, 0, 0, len(strtab), 0, 0, 1, 0)),
                      (names, (n_shs, 3, 0, 0, 0, len(names), 0, 0, 1, 0))):
        blobs.append(data)
        sections.append(sec[:4] + (off,) + sec[5:])
        off += len(data)
    off += -off % 4
    body = b"".join(blobs)
    body += b"\0" * (off - 52 - len(body))
    ehdr = struct.pack("<16sHHIIIIIHHHHHH", b"\x7fELF\x01\x01\x01" + b"\0" * 9, 1, 8, 1, 0, 0, off, 0, 52, 0, 0, 40,
                       len(sections), len(sections) - 1)
    return ehdr + body + b"".join(struct.pack("<10I", *s) for s in sections)


class HelperHeader(unittest.TestCase):
    def header(self, extra: str) -> dict:
        with tempfile.TemporaryDirectory() as d:
            p = Path(d) / "f.c"
            p.write_text(f"/* HSTMATCH module=EBOOT.BIN start=0x00291434 end=0x002914c0 symbol=FUN_00291434 "
                         f"lang=c99 {extra} */\n", encoding="utf-8")
            return M.parse_header(p)

    def test_parsed_and_ordered_target_first(self) -> None:
        h = self.header("helpers=Log@0x0028fb44-0x0028fb70,FUN_0028fb70@0x0028fb70-0x0028fb80")
        self.assertEqual(h["helpers"], [("Log", 0x28fb44, 0x28fb70), ("FUN_0028fb70", 0x28fb70, 0x28fb80)])
        self.assertEqual(M.placed_functions(h)[0], ("FUN_00291434", 0x291434, 0x2914c0))
        self.assertEqual(M.placed_functions(self.header("")), [("FUN_00291434", 0x291434, 0x2914c0)])

    def test_bad_entries_are_rejected(self) -> None:
        for bad in ("helpers=Log", "helpers=Log@0x0028fb44", "helpers=Log@0x0028fb46-0x0028fb70",
                    "helpers=Log@0x0028fb70-0x0028fb44",
                    "helpers=Log@0x00291430-0x00291440",                                   # overlaps the target
                    "helpers=A@0x0028fb44-0x0028fb70,B@0x0028fb60-0x0028fb80",              # helpers overlap
                    "helpers=FUN_00291434@0x0028fb44-0x0028fb70",                           # the target's own name
                    "helpers=A@0x0028fb44-0x0028fb70,A@0x0028fb70-0x0028fb80"):             # a name twice
            with self.subTest(bad=bad), self.assertRaises(ValueError):
                self.header(bad)


class SectionPlacement(unittest.TestCase):
    def test_rename_changes_only_section_names(self) -> None:
        obj = tiny_object([("Log", b"\x08\x00\xe0\x03" b"\0\0\0\0"), ("Target", b"\x01\x02\x03\x04")])
        out = M.rename_sections(obj, {1: ".hst_fn0", 2: ".hst_fn1"})
        before, after = M.elf_sections(obj), M.elf_sections(out)
        self.assertEqual([n for n, _ in before][1:3], [".text", ".text"])
        self.assertEqual([n for n, _ in after][1:3], [".hst_fn0", ".hst_fn1"])
        self.assertEqual([n for n, _ in after][3:], [n for n, _ in before][3:])
        for (_, a), (_, b) in zip(before, after):
            if a[1] != 3:   # every section but the string tables: same header fields apart from the name
                self.assertEqual(a[1:], b[1:])
                self.assertEqual(obj[a[4]:a[4] + a[5]], out[b[4]:b[4] + b[5]])
        self.assertEqual(list(M.elf_symbols(obj)), list(M.elf_symbols(out)))
        shoff = struct.unpack_from("<I", obj, 0x20)[0]
        self.assertEqual(out[:shoff], obj[:shoff])   # every byte before the section headers is untouched (the new name
                                                     # table is appended after them)

    def test_function_sections(self) -> None:
        obj = tiny_object([("Log", b"\0" * 8), ("Target", b"\0" * 4)])
        got, why = M.function_sections(obj, [("Target", 0x100, 0x104), ("Log", 0x40, 0x48)])
        self.assertEqual((got, why), ({2: ("Target", 0x100, 0x104), 1: ("Log", 0x40, 0x48)}, ""))

    def test_function_sections_refusals(self) -> None:
        obj = tiny_object([("Log", b"\0" * 8), ("Target", b"\0" * 4)])
        _, why = M.function_sections(obj, [("Target", 0x100, 0x104)])
        self.assertIn("Log defined but not placed", why)                 # every function must be placed
        _, why = M.function_sections(obj, [("Target", 0x100, 0x104), ("Missing", 0x40, 0x48)])
        self.assertIn("Missing is not defined", why)
        shared = tiny_object([("Log", b"\0" * 8), ("Target", b"\0" * 4)], extra_in_first="Other")
        _, why = M.function_sections(shared, [("Target", 0x100, 0x104), ("Log", 0x40, 0x48)])
        self.assertIn("shares its .text section with Other", why)        # one function per section only

    def test_word_diffs(self) -> None:
        self.assertEqual(M.word_diffs(b"\0" * 8, b"\0" * 8), [])
        self.assertEqual(M.word_diffs(b"\0" * 8, b"\0\0\0\0\1\0\0\0"), [1])
        self.assertEqual(M.word_diffs(b"\0" * 4, b"\0" * 8), [1])          # a shorter body differs in the rest




class WSLRunner(unittest.TestCase):
    def test_run_wsl_cleanup_on_subprocess_failure(self) -> None:
        build_dir = M.ROOT / "build"
        build_dir.mkdir(parents=True, exist_ok=True)
        script_path = build_dir / f"test_runner.{os.getpid()}.sh"

        with patch("subprocess.run", side_effect=RuntimeError("wsl execution failed")) as mock_run:
            with self.assertRaises(RuntimeError):
                M.run_wsl(["echo test"], "test_runner")

            mock_run.assert_called_once()
            self.assertFalse(script_path.exists(), "Script file should be unlinked/cleaned up even if subprocess.run raises an error")


if __name__ == "__main__":
    unittest.main()
