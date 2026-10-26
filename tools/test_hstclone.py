#!/usr/bin/env python3
"""Unit tests for tools/hstclone.py mapping and analysis pure functions."""
from __future__ import annotations

import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import hstclone as C


def mips_i(op: int, rs: int, rt: int, imm: int) -> int:
    return (op << 26) | (rs << 21) | (rt << 16) | (imm & 0xFFFF)


def mips_j(op: int, target: int) -> int:
    return (op << 26) | ((target >> 2) & 0x03FFFFFF)


def mips_r(op: int, rs: int, rt: int, rd: int, shamt: int = 0, funct: int = 0) -> int:
    return (op << 26) | (rs << 21) | (rt << 16) | (rd << 11) | (shamt << 6) | funct


class AnalyseTests(unittest.TestCase):
    def test_words_conversion(self) -> None:
        raw = bytes([0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09])
        self.assertEqual(C.words(raw), [0x04030201, 0x08070605])

    def test_jal_and_j_instructions_produce_call_refs(self) -> None:
        ws = [mips_j(3, 0x08801000), mips_j(2, 0x08802000)]
        sig, refs = C.analyse(ws)
        self.assertEqual(sig, (3 << 26, 2 << 26))
        self.assertEqual(refs, [("call", 0, 0x08801000), ("call", 1, 0x08802000)])

    def test_lui_and_data_ref_with_sign_extension(self) -> None:
        # lui $v0, 0x0880 -> hi[$v0=2] = 0x08800000
        # lw $v1, -0x1000($v0) -> imm = 0xF000 (-0x1000), op=0x23 (35)
        lui = mips_i(0x0F, 0, 2, 0x0880)
        lw = mips_i(0x23, 2, 3, 0xF000)  # 0x08800000 - 0x1000 = 0x087FF000
        sig, refs = C.analyse([lui, lw])
        self.assertEqual(refs, [("hi", 0, 0x08800000), ("data", 1, 0x087FF000)])

    def test_lui_and_ori_data_ref(self) -> None:
        # lui $a0, 0x0880
        # ori $a0, $a0, 0x1234 -> op=0x0D (13)
        lui = mips_i(0x0F, 0, 4, 0x0880)
        ori = mips_i(0x0D, 4, 4, 0x1234)
        sig, refs = C.analyse([lui, ori])
        self.assertEqual(refs, [("hi", 0, 0x08800000), ("data", 1, 0x08801234)])

    test_lui_and_addiu_positive_offset = lambda self: self.assertEqual(
        C.analyse([mips_i(0x0F, 0, 4, 0x0880), mips_i(0x09, 4, 4, 0x0100)])[1],
        [("hi", 0, 0x08800000), ("data", 1, 0x08800100)]
    )

    def test_hi_register_cleared_on_register_write(self) -> None:
        # lui $t0, 0x0880
        # addiu $t0, $zero, 5 (op=0x09 in GPR_WRITE_RT) -> clears $t0 (rt=8) from hi
        # lw $t1, 0($t0) -> $t0 is no longer in hi, so no data ref created
        lui = mips_i(0x0F, 0, 8, 0x0880)
        clobber = mips_i(0x09, 0, 8, 5)
        lw = mips_i(0x23, 8, 9, 0)
        sig, refs = C.analyse([lui, clobber, lw])
        self.assertEqual(refs, [("hi", 0, 0x08800000)])

    def test_hi_register_cleared_on_special_op(self) -> None:
        # lui $v0, 0x0880
        # special op (0x00) writing to rd=$v0 (2)
        lui = mips_i(0x0F, 0, 2, 0x0880)
        spec = mips_r(0x00, 4, 5, 2)  # addu $v0, $a0, $a1
        lw = mips_i(0x23, 2, 3, 0)
        sig, refs = C.analyse([lui, spec, lw])
        self.assertEqual(refs, [("hi", 0, 0x08800000)])

    def test_hi_register_cleared_on_cop1_rs0(self) -> None:
        # op == 0x11 and rs == 0 -> clears rt
        lui = mips_i(0x0F, 0, 5, 0x0880)
        cop1 = mips_i(0x11, 0, 5, 0)
        lw = mips_i(0x23, 5, 6, 0)
        sig, refs = C.analyse([lui, cop1, lw])
        self.assertEqual(refs, [("hi", 0, 0x08800000)])


class MappingTests(unittest.TestCase):
    def test_mapping_matches(self) -> None:
        e_refs = [("call", 0, 0x08801000), ("hi", 1, 0x08800000), ("data", 2, 0x08800010)]
        t_refs = [("call", 0, 0x08805000), ("hi", 1, 0x08800000), ("data", 2, 0x08800020)]
        res = C.mapping(e_refs, t_refs)
        self.assertIsNotNone(res)
        calls, data, his = res  # type: ignore
        self.assertEqual(calls, {0x08801000: 0x08805000})
        self.assertEqual(his, {0x08800000: 0x08800000})
        self.assertEqual(data, {0x08800010: 0x08800020})

    def test_mapping_length_mismatch(self) -> None:
        self.assertIsNone(C.mapping([("call", 0, 0x10)], []))

    def test_mapping_kind_or_index_mismatch(self) -> None:
        self.assertIsNone(C.mapping([("call", 0, 0x10)], [("data", 0, 0x10)]))
        self.assertIsNone(C.mapping([("call", 0, 0x10)], [("call", 1, 0x10)]))

    def test_mapping_conflicting_values(self) -> None:
        e_refs = [("call", 0, 0x08801000), ("call", 2, 0x08801000)]
        t_refs = [("call", 0, 0x08805000), ("call", 2, 0x08806000)]
        self.assertIsNone(C.mapping(e_refs, t_refs))


class MapValueTests(unittest.TestCase):
    def test_map_value_exact_start(self) -> None:
        self.assertEqual(C.map_value("FUN", 0x1000, 0x1000, 0x2000, {}, {}), 0x2000)

    def test_map_value_calls_and_data(self) -> None:
        self.assertEqual(C.map_value("FUN", 0x1000, 0x0, 0x0, {0x1000: 0x3000}, {}), 0x3000)
        self.assertEqual(C.map_value("DAT", 0x1000, 0x0, 0x0, {}, {0x1000: 0x4000}), 0x4000)

    def test_map_value_address_kind_shift(self) -> None:
        # data ev 0x1010 maps to tv 0x2010 -> shift +0x1000
        # requesting value 0x1000 (ev - value = 0x10 < MAX_DATA_SHIFT 0x10000)
        data = {0x1010: 0x2010}
        self.assertEqual(C.map_value("DAT", 0x1000, 0x0, 0x0, {}, data), 0x2000)

    def test_map_value_address_kind_missing_raises_key_error(self) -> None:
        with self.assertRaises(KeyError):
            C.map_value("DAT", 0x1000, 0x0, 0x0, {}, {})

    def test_map_value_non_address_kind_returns_none(self) -> None:
        self.assertIsNone(C.map_value("OTHER", 0x1000, 0x0, 0x0, {}, {}))


class RetargetTests(unittest.TestCase):
    def test_retarget_names(self) -> None:
        text = "void FUN_00001000(void) { DAT_00002000 = 1; }"
        res = C.retarget_names(text, 0x1000, 0x5000, {}, {0x2000: 0x6000})
        self.assertEqual(res, "void FUN_00005000(void) { DAT_00006000 = 1; }")

    def test_symbol_entries(self) -> None:
        base = {"FUN_00001000": 0x1000, "DAT_00002000": 0x2000}
        entries = C.symbol_entries(base, 0x1000, 0x5000, {}, {0x2000: 0x6000})
        self.assertEqual(entries, {"FUN_00005000": 0x5000, "DAT_00006000": 0x6000})

    def test_retarget_full(self) -> None:
        text = "/* HSTMATCH module=EBOOT.BIN start=0x00001000 end=0x00001020 symbol=FUN_00001000 */\nvoid FUN_00001000(void) {}"
        out = C.retarget(text, 0x1000, 0x5000, 0x5020, {}, {})
        self.assertIsNotNone(out)
        self.assertIn("start=0x00005000", out)  # type: ignore
        self.assertIn("end=0x00005020", out)  # type: ignore
        self.assertIn("FUN_00005000", out)  # type: ignore


if __name__ == "__main__":
    unittest.main()
