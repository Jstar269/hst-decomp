#!/usr/bin/env python3
"""Tests for clone code propagation and retargeting (hstclone.py)."""
from __future__ import annotations

import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import hstclone as C


class WordsTests(unittest.TestCase):
    def test_words_converts_little_endian_bytes(self) -> None:
        data = b"\x01\x02\x03\x04\x05\x06\x07\x08"
        self.assertEqual(C.words(data), [0x04030201, 0x08070605])

    def test_words_truncates_unaligned_trailing_bytes(self) -> None:
        data = b"\x01\x02\x03\x04\x05\x06\x07"
        self.assertEqual(C.words(data), [0x04030201])

    def test_words_empty_input(self) -> None:
        self.assertEqual(C.words(b""), [])


class AnalyseTests(unittest.TestCase):
    def test_jal_instruction(self) -> None:
        # jal target 0x00400000 -> imm = 0x00100000, opcode = 3 -> w = (3 << 26) | 0x100000
        w = (3 << 26) | 0x00100000
        sig, refs = C.analyse([w])
        self.assertEqual(sig, (3 << 26,))
        self.assertEqual(refs, [("call", 0, 0x00400000)])

    def test_lui_and_lw_data_reference(self) -> None:
        # lui $v0, 0x0880 ($v0 is reg 2) -> op=0x0F, rt=2, imm=0x0880
        w_lui = (0x0F << 26) | (0 << 21) | (2 << 16) | 0x0880
        # lw $v1, 0x10($v0) -> op=0x23, rs=2, rt=3, imm=0x0010
        w_lw = (0x23 << 26) | (2 << 21) | (3 << 16) | 0x0010
        sig, refs = C.analyse([w_lui, w_lw])
        # Masked signature masks upper 16 bits (retaining op, rs, rt)
        self.assertEqual(sig, ((0x0F << 26) | (2 << 16), (0x23 << 26) | (2 << 21) | (3 << 16)))
        self.assertEqual(refs, [("hi", 0, 0x08800000), ("data", 1, 0x08800010)])

    def test_lui_and_addiu_negative_offset(self) -> None:
        # lui $v0, 0x0880
        w_lui = (0x0F << 26) | (0 << 21) | (2 << 16) | 0x0880
        # addiu $v0, $v0, -0x1000 (0xF000) -> op=0x09, rs=2, rt=2, imm=0xF000
        w_addiu = (0x09 << 26) | (2 << 21) | (2 << 16) | 0xF000
        sig, refs = C.analyse([w_lui, w_addiu])
        self.assertEqual(refs, [("hi", 0, 0x08800000), ("data", 1, 0x087FF000)])

    def test_register_clearing_erases_hi_state(self) -> None:
        # lui $v0, 0x0880 (reg 2)
        w_lui = (0x0F << 26) | (0 << 21) | (2 << 16) | 0x0880
        # addu $v0, $zero, $zero -> op=0, rs=0, rt=0, rd=2, funct=0x21
        w_cleared = (0x00 << 26) | (0 << 21) | (0 << 16) | (2 << 11) | 0x21
        # lw $v1, 0x10($v0) -> rs=2 has been overwritten, so not tracked as data ref
        w_lw = (0x23 << 26) | (2 << 21) | (3 << 16) | 0x0010
        sig, refs = C.analyse([w_lui, w_cleared, w_lw])
        self.assertEqual(refs, [("hi", 0, 0x08800000)])


class MappingTests(unittest.TestCase):
    def test_matching_references(self) -> None:
        e_refs = [("call", 0, 0x00400000), ("data", 1, 0x08801000)]
        t_refs = [("call", 0, 0x00500000), ("data", 1, 0x08901000)]
        res = C.mapping(e_refs, t_refs)
        self.assertIsNotNone(res)
        calls, data, his = res
        self.assertEqual(calls, {0x00400000: 0x00500000})
        self.assertEqual(data, {0x08801000: 0x08901000})
        self.assertEqual(his, {})

    def test_mismatched_length(self) -> None:
        e_refs = [("call", 0, 0x00400000)]
        t_refs = [("call", 0, 0x00500000), ("data", 1, 0x08901000)]
        self.assertIsNone(C.mapping(e_refs, t_refs))

    def test_mismatched_kind_or_index(self) -> None:
        e_refs = [("call", 0, 0x00400000)]
        t_refs = [("data", 0, 0x08901000)]
        self.assertIsNone(C.mapping(e_refs, t_refs))

        e_refs2 = [("call", 0, 0x00400000)]
        t_refs2 = [("call", 1, 0x00500000)]
        self.assertIsNone(C.mapping(e_refs2, t_refs2))

    def test_inconsistent_target_mapping(self) -> None:
        e_refs = [("call", 0, 0x00400000), ("call", 2, 0x00400000)]
        t_refs = [("call", 0, 0x00500000), ("call", 2, 0x00600000)]
        self.assertIsNone(C.mapping(e_refs, t_refs))


class MapValueTests(unittest.TestCase):
    def test_start_address(self) -> None:
        self.assertEqual(C.map_value("FUN", 0x1000, 0x1000, 0x2000, {}, {}), 0x2000)

    def test_calls_and_data_lookup(self) -> None:
        calls = {0x00400000: 0x00500000}
        data = {0x08801000: 0x08901000}
        self.assertEqual(C.map_value("FUN", 0x00400000, 0x1000, 0x2000, calls, data), 0x00500000)
        self.assertEqual(C.map_value("DAT", 0x08801000, 0x1000, 0x2000, calls, data), 0x08901000)

    def test_address_kind_constant_shift(self) -> None:
        # DAT_08801008 is 8 bytes after DAT_08801000 (0 <= ev - value < MAX_DATA_SHIFT: 08801008 - 08801000 = 8)
        # ev=0x08801008, tv=0x08901008, ev-value=0
        data = {0x08801008: 0x08901008}
        self.assertEqual(C.map_value("DAT", 0x08801000, 0x1000, 0x2000, {}, data), 0x08901000)

    def test_unmapped_address_kind_raises_key_error(self) -> None:
        with self.assertRaises(KeyError):
            C.map_value("FUN", 0x00700000, 0x1000, 0x2000, {}, {})

    def test_non_address_kind_returns_none(self) -> None:
        self.assertIsNone(C.map_value("", 0x00700000, 0x1000, 0x2000, {}, {}))


class RetargetNamesTests(unittest.TestCase):
    def test_retarget_names(self) -> None:
        text = "void FUN_00400000(void) { DAT_08801000 = 1; unmapped_00700000 = 2; }"
        calls = {0x00400000: 0x00500000}
        data = {0x08801000: 0x08901000}
        res = C.retarget_names(text, 0x1000, 0x2000, calls, data)
        self.assertIn("FUN_00500000", res)
        self.assertIn("DAT_08901000", res)
        self.assertIn("unmapped_00700000", res)


class SymbolEntriesTests(unittest.TestCase):
    def test_symbol_entries_mapping(self) -> None:
        base = {"FUN_00400000": 0x00400000, "unmapped": 0x00700000}
        calls = {0x00400000: 0x00500000}
        res = C.symbol_entries(base, 0x1000, 0x2000, calls, {})
        self.assertEqual(res, {"FUN_00500000": 0x00500000})

    def test_symbol_entries_keep_names(self) -> None:
        base = {"__dl__FPv": 0x00400000}
        calls = {0x00400000: 0x00500000}
        res = C.symbol_entries(base, 0x1000, 0x2000, calls, {}, keep_names=True)
        self.assertEqual(res, {"__dl__FPv": 0x00500000})


class RetargetTests(unittest.TestCase):
    def test_retarget_full_source(self) -> None:
        text = (
            "/* HSTMATCH module=EBOOT.BIN start=0x00001000 end=0x00001020 rodata=0x08801000 */\n"
            "void FUN_00400000(void) {\n"
            "    int val = 0x08801000;\n"
            "}\n"
        )
        calls = {0x00400000: 0x00500000}
        data = {0x08801000: 0x08901000}
        out = C.retarget(text, 0x00001000, 0x00002000, 0x00002020, calls, data)
        self.assertIsNotNone(out)
        self.assertIn("start=0x00002000", out)
        self.assertIn("end=0x00002020", out)
        self.assertIn("rodata=0x08901000", out)
        self.assertIn("FUN_00500000", out)
        self.assertIn("0x8901000", out)

    def test_retarget_unmapped_address_returns_none(self) -> None:
        text = (
            "/* HSTMATCH module=EBOOT.BIN start=0x00001000 end=0x00001020 */\n"
            "void FUN_00700000(void) {}\n"
        )
        out = C.retarget(text, 0x00001000, 0x00002000, 0x00002020, {}, {})
        self.assertIsNone(out)


if __name__ == "__main__":
    unittest.main()
