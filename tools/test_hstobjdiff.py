#!/usr/bin/env python3
"""Tests for objdiff project generator (hstobjdiff.py)."""
from __future__ import annotations

import argparse
import json
import struct
import sys
import tempfile
import unittest
from pathlib import Path
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parent))
import hstobjdiff as O


class ELF32Tests(unittest.TestCase):
    def test_elf32_header_and_sections(self) -> None:
        text = b"\x00\x00\x00\x00\x08\x00\xe0\x03"
        symbols = [("FUN_00001000", 0x1000, 8)]
        elf = O.elf32(0x1000, text, symbols, e_flags=0x10970001)

        # Magic header: \x7fELF, 32-bit, Little Endian, ELF Version 1
        self.assertTrue(elf.startswith(b"\x7fELF\x01\x01\x01\x00"))
        # Check e_flags in header at offset 0x24 (36)
        e_flags, = struct.unpack_from("<I", elf, 0x24)
        self.assertEqual(e_flags, 0x10970001)

        # Check section extraction works with elf_text helper
        with tempfile.NamedTemporaryFile(delete=False) as f:
            f.write(elf)
            tmp_path = Path(f.name)
        try:
            addr, extracted_text = O.elf_text(tmp_path)
            self.assertEqual(addr, 0x1000)
            self.assertEqual(extracted_text, text)
        finally:
            tmp_path.unlink(missing_ok=True)

    def test_e_flags_of(self) -> None:
        with tempfile.TemporaryDirectory() as tmp:
            tmp_dir = Path(tmp)
            non_existent = tmp_dir / "missing.o"
            self.assertEqual(O.e_flags_of(non_existent), O.DEFAULT_E_FLAGS)

            obj_path = tmp_dir / "valid.o"
            # Write elf header with specific e_flags (0x12345678)
            header = bytearray(0x28)
            header[:4] = b"\x7fELF"
            struct.pack_into("<I", header, 0x24, 0x12345678)
            obj_path.write_bytes(bytes(header))
            self.assertEqual(O.e_flags_of(obj_path), 0x12345678)


class HelperFunctionTests(unittest.TestCase):
    def test_clamp_symbols(self) -> None:
        symbols = [("FUN_1", 0x1000, 32), ("FUN_2", 0x1020, 32)]
        # Length 40 covers all of FUN_1 (0x1000..0x1020) and 8 bytes of FUN_2 (0x1020..0x1028)
        clamped = O.clamp_symbols(symbols, 0x1000, 40)
        self.assertEqual(clamped, [("FUN_1", 0x1000, 32), ("FUN_2", 0x1020, 8)])

        # Length 16 clamps FUN_1 to 16 bytes and excludes FUN_2
        clamped_short = O.clamp_symbols(symbols, 0x1000, 16)
        self.assertEqual(clamped_short, [("FUN_1", 0x1000, 16)])

    def test_function_name(self) -> None:
        self.assertEqual(O.function_name(0x0006f644), "FUN_0006f644")
        self.assertEqual(O.function_name(0x0), "FUN_00000000")

    def test_unit_paths_and_name(self) -> None:
        src_path = O.ROOT / "src" / "foo" / "bar.c"
        base, target = O.unit_paths(src_path)
        self.assertEqual(base, O.OUT_DIR / "units" / "src" / "foo" / "bar.base.o")
        self.assertEqual(target, O.OUT_DIR / "units" / "src" / "foo" / "bar.target.o")
        self.assertEqual(O.unit_name(src_path), "src/foo/bar")

    def test_differing_instructions(self) -> None:
        diff_data = {
            "left": {
                "symbols": [
                    {
                        "name": "FUN_1",
                        "instructions": [
                            {"diff_kind": "DIFF_NONE", "instruction": {"address": 0x1000}},
                            {"diff_kind": "DIFF_VALUE", "instruction": {"address": 0x1004}},
                            {"diff_kind": "DIFF_INSERT", "instruction": {"address": 0x1008}},
                        ]
                    }
                ]
            },
            "right": {
                "symbols": [
                    {
                        "name": "FUN_1",
                        "instructions": [
                            {"diff_kind": "DIFF_DELETE", "instruction": {"address": 0x100C}},
                        ]
                    }
                ]
            }
        }
        value, structural = O.differing_instructions(diff_data)
        self.assertEqual(value, {0x1004})
        self.assertEqual(structural, {0x1008, 0x100C})

    def test_differing_words(self) -> None:
        with tempfile.TemporaryDirectory() as tmp:
            tmp_dir = Path(tmp)
            base_o = tmp_dir / "test.base.o"
            target_o = tmp_dir / "test.target.o"

            # 8 bytes text vs 8 bytes text with 2nd word different
            text1 = struct.pack("<II", 0x00000000, 0x11111111)
            text2 = struct.pack("<II", 0x00000000, 0x22222222)

            base_o.write_bytes(O.elf32(0x1000, text1, [("FUN_1", 0x1000, 8)]))
            target_o.write_bytes(O.elf32(0x1000, text2, [("FUN_1", 0x1000, 8)]))

            unit = {"path": base_o, "target_path": target_o}
            diffing = O.differing_words(unit)
            self.assertEqual(diffing, {0x1004})

    def test_unexplained_differences(self) -> None:
        with tempfile.TemporaryDirectory() as tmp:
            tmp_dir = Path(tmp)
            base_o = tmp_dir / "test.base.o"
            target_o = tmp_dir / "test.target.o"

            text = bytes(16)
            base_o.write_bytes(O.elf32(0x1000, text, [("FUN_1", 0x1000, 16)]))
            target_o.write_bytes(O.elf32(0x1000, text, [("FUN_1", 0x1000, 16)]))

            unit = {"path": base_o, "target_path": target_o}

            # 0x1004 is inside [0x1000, 0x1010)
            # 0x2000 is outside
            outside, rest = O.unexplained_differences(unit, {0x1004, 0x2000})
            self.assertEqual(outside, 1)
            self.assertEqual(rest, [0x1004])


class GenerateIntegrationTests(unittest.TestCase):
    def test_generate_project(self) -> None:
        with tempfile.TemporaryDirectory() as tmp:
            tmp_root = Path(tmp)
            out_file = tmp_root / "objdiff.json"

            # Mock ROOT, OUT_DIR, PROJECT_FILE, SUMMARY_FILE in hstobjdiff
            out_dir = tmp_root / "build" / "objdiff"
            summary_file = out_dir / "hstobjdiff.json"

            mock_ledger = {
                "TEST.BIN": [(0x1000, 0x1020)]
            }

            src_file = tmp_root / "src" / "test.c"
            src_file.parent.mkdir(parents=True, exist_ok=True)
            src_file.write_text("/* HSTMATCH module=TEST.BIN start=0x00001000 end=0x00001020 symbol=FUN_00001000 lang=c99 */\n")

            # Mock hstmatch build output
            build_dir = tmp_root / "build" / "TEST.BIN" / O.M.build_key(src_file)
            build_dir.mkdir(parents=True, exist_ok=True)
            (build_dir / "text.bin").write_bytes(bytes(32))
            (build_dir / "obj.o").write_bytes(O.elf32(0x1000, bytes(32), [("FUN_00001000", 0x1000, 32)]))

            # Mock retail module bytes: data, segment
            retail_data = bytes(0x2000)
            retail_seg = {"start": 0x0, "file_offset": 0x0}

            with patch.object(O, "ROOT", tmp_root), \
                 patch.object(O, "OUT_DIR", out_dir), \
                 patch.object(O, "PROJECT_FILE", out_file), \
                 patch.object(O, "SUMMARY_FILE", summary_file), \
                 patch.object(O, "ledger", return_value=mock_ledger), \
                 patch.object(O.M, "module_bytes", return_value=(retail_data, retail_seg)):

                args = argparse.Namespace(
                    no_wip=False,
                    only=None,
                    out=str(out_file),
                    quiet=True,
                )
                ret = O.generate(args)
                self.assertEqual(ret, 0)
                self.assertTrue(out_file.exists())
                self.assertTrue(summary_file.exists())

                project_data = json.loads(out_file.read_text(encoding="utf-8"))
                self.assertEqual(project_data["min_version"], "2.0.0")
                self.assertEqual(len(project_data["units"]), 1)
                self.assertEqual(project_data["units"][0]["name"], "src/test")

                summary_data = json.loads(summary_file.read_text(encoding="utf-8"))
                self.assertEqual(summary_data["units"], 1)
                self.assertEqual(summary_data["source_units"], 1)

    def test_main_arg_parsing(self) -> None:
        with patch.object(sys, "argv", ["hstobjdiff.py", "generate", "--quiet"]), \
             patch.object(O, "generate", return_value=0) as mock_gen:
            ret = O.main()
            self.assertEqual(ret, 0)
            mock_gen.assert_called_once()


if __name__ == "__main__":
    unittest.main()
