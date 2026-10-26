#!/usr/bin/env python3
"""Synthetic unit tests for hstclone.py (code clone retargeting tools)."""
from __future__ import annotations

import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import hstclone as C


class TestHstClone(unittest.TestCase):
    def test_words(self) -> None:
        b = b"\x01\x02\x03\x04\x05\x06\x07\x08\x09"
        self.assertEqual(C.words(b), [0x04030201, 0x08070605])

    def test_analyse_and_mapping(self) -> None:
        # Instruction 1: JAL 0x0001000 -> op 3, target 0x00004000
        # Instruction 2: LUI t0, 0x0001 -> op 0x0F, rt=8, val=0x00010000
        # Instruction 3: ADDIU t0, t0, 0x0100 -> op 0x09, rs=8, rt=8, imm=0x0100 -> data addr 0x00010100
        e_words = [
            (3 << 26) | (0x00001000 >> 2),
            (0x0F << 26) | (8 << 16) | 0x0001,
            (0x09 << 26) | (8 << 21) | (8 << 16) | 0x0100,
        ]
        t_words = [
            (3 << 26) | (0x00002000 >> 2),
            (0x0F << 26) | (8 << 16) | 0x0002,
            (0x09 << 26) | (8 << 21) | (8 << 16) | 0x0200,
        ]
        e_sig, e_refs = C.analyse(e_words)
        t_sig, t_refs = C.analyse(t_words)

        self.assertEqual(e_sig, t_sig)
        maps = C.mapping(e_refs, t_refs)
        self.assertIsNotNone(maps)
        calls, data, his = maps  # type: ignore
        self.assertEqual(calls, {0x00001000: 0x00002000})
        self.assertEqual(his, {0x00010000: 0x00020000})
        self.assertEqual(data, {0x00010100: 0x00020200})

    def test_mapping_mismatches(self) -> None:
        e_refs = [("call", 0, 0x100)]
        t_refs_len = [("call", 0, 0x200), ("call", 1, 0x300)]
        self.assertIsNone(C.mapping(e_refs, t_refs_len))

        t_refs_kind = [("data", 0, 0x200)]
        self.assertIsNone(C.mapping(e_refs, t_refs_kind))

        # Inconsistent target mapping for same source
        e_refs_dup = [("call", 0, 0x100), ("call", 1, 0x100)]
        t_refs_inconsistent = [("call", 0, 0x200), ("call", 1, 0x300)]
        self.assertIsNone(C.mapping(e_refs_dup, t_refs_inconsistent))

    def test_map_value(self) -> None:
        calls = {0x00001000: 0x00002000}
        data = {0x00010100: 0x00020100}  # Shift of +0x00010000

        # Exact matches
        self.assertEqual(C.map_value("FUN", 0x00000100, 0x00000100, 0x00000200, calls, data), 0x00000200)
        self.assertEqual(C.map_value("FUN", 0x00001000, 0x00000100, 0x00000200, calls, data), 0x00002000)
        self.assertEqual(C.map_value("DAT", 0x00010100, 0x00000100, 0x00000200, calls, data), 0x00020100)

        # Shifted match in data (e.g. DAT_00010050 where data has 0x00010100)
        # ev - value = 0x00010100 - 0x00010050 = 0x000000B0 (< MAX_DATA_SHIFT)
        # tv - ev = 0x00010000
        # Result: 0x00010050 + 0x00010000 = 0x00020050
        self.assertEqual(C.map_value("DAT", 0x00010050, 0x00000100, 0x00000200, calls, data), 0x00020050)

        # Unmapped ADDRESS_KINDS raises KeyError
        with self.assertRaises(KeyError):
            C.map_value("DAT", 0x00090000, 0x00000100, 0x00000200, calls, data)

        # Unmapped non-ADDRESS_KINDS returns None
        self.assertIsNone(C.map_value("OTHER", 0x00090000, 0x00000100, 0x00000200, calls, data))

    def test_retarget_names(self) -> None:
        text = "void FUN_00001000(void) { DAT_00010100 = 1; UNK_00090000 = 2; }"
        calls = {0x00001000: 0x00002000}
        data = {0x00010100: 0x00020100}

        out = C.retarget_names(text, 0x00000100, 0x00000200, calls, data)
        self.assertIn("FUN_00002000", out)
        self.assertIn("DAT_00020100", out)
        self.assertIn("UNK_00090000", out)

    def test_symbol_entries(self) -> None:
        base = {
            "FUN_00000100": 0x00000100,
            "DAT_00010100": 0x00010100,
            "UNMAPPED": 0x00090000,
        }
        calls = {}
        data = {0x00010100: 0x00020100}

        entries = C.symbol_entries(base, 0x00000100, 0x00000200, calls, data)
        self.assertEqual(entries, {
            "FUN_00000200": 0x00000200,
            "DAT_00020100": 0x00020100,
        })

    def test_retarget(self) -> None:
        source_code = (
            "/* start=0x00000100 end=0x00000200 rodata=0x00010100 module=EBOOT.BIN */\n"
            "void FUN_00000100(void) {\n"
            "    int w[1];\n"
            "    u32 val = 0x00010100;\n"
            "}\n"
        )
        calls = {}
        data = {
            0x00010100: 0x00020100,
            0x3FFFFFFF: 0x1FFFFFFF,  # max_size for int w[1] (4 bytes elem -> max_size = 0xFFFFFFFF // 4 = 0x3FFFFFFF)
        }
        his = {}

        retargeted = C.retarget(source_code, 0x00000100, 0x00000200, 0x00000300, calls, data, his)
        self.assertIsNotNone(retargeted)
        assert retargeted is not None
        self.assertIn("start=0x00000200", retargeted)
        self.assertIn("end=0x00000300", retargeted)
        self.assertIn("rodata=0x00020100", retargeted)
        self.assertIn("FUN_00000200", retargeted)
        self.assertIn("int w[2]", retargeted)  # 0x1FFFFFFF -> max_t = 0x1FFFFFFF -> size_t = 0xFFFFFFFF // max_t = 8 -> int w[2]
        self.assertIn("0x20100", retargeted)

    def test_retarget_keyerror_returns_none(self) -> None:
        source_code = "/* start=0x100 end=0x200 */\nvoid FUN_00090000(void);"
        retargeted = C.retarget(source_code, 0x100, 0x200, 0x300, {}, {})
        self.assertIsNone(retargeted)


if __name__ == "__main__":
    unittest.main()
