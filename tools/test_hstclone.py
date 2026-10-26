#!/usr/bin/env python3
"""Tests for the clone propagation tool (hstclone.py)."""
from __future__ import annotations

import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import hstclone as C


class CloneContextTests(unittest.TestCase):
    def setUp(self) -> None:
        self.ctx = C.CloneContext(
            e_start=0x00010000,
            t_start=0x00020000,
            calls={0x00010100: 0x00020100},
            data={0x00080000: 0x00090000, 0x00080010: 0x00090010},
            his={0x00080000: 0x00090000},
        )

    def test_map_value_exemplar_start(self) -> None:
        self.assertEqual(C.map_value("FUN", 0x00010000, self.ctx), 0x00020000)

    def test_map_value_calls_and_data(self) -> None:
        self.assertEqual(C.map_value("FUN", 0x00010100, self.ctx), 0x00020100)
        self.assertEqual(C.map_value("DAT", 0x00080000, self.ctx), 0x00090000)

    def test_map_value_data_shift(self) -> None:
        # 0x00080004 is offset 4 from known 0x00080000 (shift 0x10000)
        self.assertEqual(C.map_value("DAT", 0x00080004, self.ctx), 0x00090004)

    def test_map_value_unmapped_kind_returns_none(self) -> None:
        self.assertIsNone(C.map_value("OTHER", 0x12345678, self.ctx))

    def test_map_value_address_kind_raises_key_error_when_unmapped(self) -> None:
        with self.assertRaises(KeyError):
            C.map_value("FUN", 0x00001000, self.ctx)

    def test_retarget_names(self) -> None:
        text = "FUN_00010000(); DAT_00080000 = 1;"
        retargeted = C.retarget_names(text, self.ctx)
        self.assertIn("FUN_00020000()", retargeted)
        self.assertIn("DAT_00090000", retargeted)

    def test_symbol_entries(self) -> None:
        base = {
            "FUN_00010000": 0x00010000,
            "DAT_00080000": 0x00080000,
            "FUN_00010100": 0x00010100,
            "UNKNOWN": 0x00000100,
        }
        entries = C.symbol_entries(base, self.ctx)
        self.assertEqual(entries.get("FUN_00020000"), 0x00020000)
        self.assertEqual(entries.get("DAT_00090000"), 0x00090000)
        self.assertEqual(entries.get("FUN_00020100"), 0x00020100)
        self.assertNotIn("UNKNOWN", entries)

    def test_retarget_header_and_body(self) -> None:
        text = (
            "/* HSTMATCH module=EBOOT.BIN start=0x00010000 end=0x00010080 symbol=FUN_00010000 */\n"
            "void FUN_00010000(void) {\n"
            "    FUN_00010100();\n"
            "}\n"
        )
        res = C.retarget(text, 0x00020080, self.ctx)
        self.assertIsNotNone(res)
        self.assertIn("start=0x00020000", res)
        self.assertIn("end=0x00020080", res)
        self.assertIn("FUN_00020000", res)
        self.assertIn("FUN_00020100", res)


if __name__ == "__main__":
    unittest.main()
