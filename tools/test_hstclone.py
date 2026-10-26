#!/usr/bin/env python3
"""Tests for byte decoding and instruction analysis in hstclone.py."""
from __future__ import annotations

import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import hstclone as C


class TestWords(unittest.TestCase):
    def test_words_empty(self) -> None:
        self.assertEqual(C.words(b""), [])

    def test_words_exact_multiples_of_four(self) -> None:
        data = b"\x01\x02\x03\x04\x05\x06\x07\x08"
        self.assertEqual(C.words(data), [0x04030201, 0x08070605])

    def test_words_unaligned_truncates_extra_bytes(self) -> None:
        data = b"\x01\x02\x03\x04\x05\x06\x07"
        self.assertEqual(C.words(data), [0x04030201])
        self.assertEqual(C.words(b"\x01\x02\x03"), [])


class TestAnalyse(unittest.TestCase):
    def test_analyse_empty(self) -> None:
        sig, refs = C.analyse([])
        self.assertEqual(sig, ())
        self.assertEqual(refs, [])

    def test_plain_instructions_unmasked(self) -> None:
        nop = 0x00000000
        jr_ra = 0x03E00008  # jr $ra (op=0)
        sig, refs = C.analyse([nop, jr_ra])
        self.assertEqual(sig, (nop, jr_ra))
        self.assertEqual(refs, [])

    def test_call_instructions_masked_and_referenced(self) -> None:
        # op=2 J 0x001000 -> target 0x00004000
        j_inst = (2 << 26) | 0x001000
        # op=3 JAL 0x002000 -> target 0x00008000
        jal_inst = (3 << 26) | 0x002000
        sig, refs = C.analyse([j_inst, jal_inst])
        self.assertEqual(sig, (2 << 26, 3 << 26))
        self.assertEqual(refs, [("call", 0, 0x00004000), ("call", 1, 0x00008000)])

    def test_lui_high_immediates_tracked_and_referenced(self) -> None:
        # op=0x0F (15): LUI $a0 ($4), 0x8001
        lui_inst = (0x0F << 26) | (4 << 16) | 0x8001
        sig, refs = C.analyse([lui_inst])
        self.assertEqual(sig, (0x3C040000,))
        self.assertEqual(refs, [("hi", 0, 0x80010000)])

    def test_data_reference_with_positive_and_negative_offsets(self) -> None:
        # LUI $a0, 0x8001 (hi[4] = 0x80010000)
        lui_a0 = (0x0F << 26) | (4 << 16) | 0x8001
        # ADDIU $v0, $a0, 0x0020 (op=9, rs=4, rt=2, imm=0x0020)
        addiu_pos = (0x09 << 26) | (4 << 21) | (2 << 16) | 0x0020
        # LUI $a1, 0x8001 (hi[5] = 0x80010000)
        lui_a1 = (0x0F << 26) | (5 << 16) | 0x8001
        # ADDIU $v1, $a1, 0x8000 (op=9, rs=5, rt=3, imm=0x8000 -> signed -0x8000)
        addiu_neg = (0x09 << 26) | (5 << 21) | (3 << 16) | 0x8000

        sig, refs = C.analyse([lui_a0, addiu_pos, lui_a1, addiu_neg])
        self.assertEqual(sig, (0x3C040000, 0x24820000, 0x3C050000, 0x24A30000))
        self.assertEqual(refs, [
            ("hi", 0, 0x80010000),
            ("data", 1, 0x80010020),
            ("hi", 2, 0x80010000),
            ("data", 3, 0x80008000)
        ])

    def test_ori_uses_bitwise_or_instead_of_addition(self) -> None:
        # LUI $a0, 0x8001 (hi[4] = 0x80010000)
        lui_a0 = (0x0F << 26) | (4 << 16) | 0x8001
        # ORI $a0, $a0, 0x8000 (op=0x0D, rs=4, rt=4, imm=0x8000)
        ori_inst = (0x0D << 26) | (4 << 21) | (4 << 16) | 0x8000
        sig, refs = C.analyse([lui_a0, ori_inst])
        self.assertEqual(sig, (0x3C040000, 0x34840000))
        self.assertEqual(refs, [("hi", 0, 0x80010000), ("data", 1, 0x80018000)])

    def test_andi_and_xori_zero_extend_immediates(self) -> None:
        # LUI $a0, 0x8001 (hi[4] = 0x80010000)
        lui_a0 = (0x0F << 26) | (4 << 16) | 0x8001
        # ANDI $a1, $a0, 0x8000 (op=0x0C, rs=4, rt=5, imm=0x8000)
        andi_inst = (0x0C << 26) | (4 << 21) | (5 << 16) | 0x8000
        # XORI $a2, $a0, 0x8000 (op=0x0E, rs=4, rt=6, imm=0x8000)
        xori_inst = (0x0E << 26) | (4 << 21) | (6 << 16) | 0x8000

        sig, refs = C.analyse([lui_a0, andi_inst, xori_inst])
        self.assertEqual(refs, [
            ("hi", 0, 0x80010000),
            ("data", 1, 0x80018000),
            ("data", 2, 0x80018000)
        ])

    def test_register_invalidation_clears_hi_state(self) -> None:
        # 1. R-type overwrites rd
        # LUI $a0 ($4), 0x8001
        lui_a0 = (0x0F << 26) | (4 << 16) | 0x8001
        # ADDU $a0 ($4), $t0 ($8), $t1 ($9) -> op=0, rd=4
        addu_a0 = (0x00 << 26) | (8 << 21) | (9 << 16) | (4 << 11) | 0x21
        # LW $v0 ($2), 0($a0) (op=0x23, rs=4, rt=2, imm=0) -> rs=4 was cleared!
        lw_a0 = (0x23 << 26) | (4 << 21) | (2 << 16) | 0x0000

        sig, refs = C.analyse([lui_a0, addu_a0, lw_a0])
        self.assertEqual(refs, [("hi", 0, 0x80010000)])  # no data ref for lw_a0!
        self.assertEqual(sig[2], lw_a0)  # full word retained since rs=4 not in hi

        # 2. GPR write RT (op in GPR_WRITE_RT, e.g. LW)
        # LUI $a1 ($5), 0x8001
        lui_a1 = (0x0F << 26) | (5 << 16) | 0x8001
        # LW $a1 ($5), 0($sp) (op=0x23, rs=29, rt=5)
        lw_into_a1 = (0x23 << 26) | (29 << 21) | (5 << 16) | 0x0000
        # ADDIU $v0 ($2), $a1 ($5), 0x0010 (op=0x09, rs=5, rt=2)
        addiu_after_lw = (0x09 << 26) | (5 << 21) | (2 << 16) | 0x0010

        sig2, refs2 = C.analyse([lui_a1, lw_into_a1, addiu_after_lw])
        self.assertEqual(refs2, [("hi", 0, 0x80010000)])
        self.assertEqual(sig2[2], addiu_after_lw)

        # 3. COP1 mfc1 (op=0x11, rs=0) writes rt
        # LUI $a2 ($6), 0x8001
        lui_a2 = (0x0F << 26) | (6 << 16) | 0x8001
        # MFC1 $a2 ($6), $f0 ($0) (op=0x11, rs=0, rt=6)
        mfc1_a2 = (0x11 << 26) | (0 << 21) | (6 << 16)
        # LW $v0 ($2), 0($a2) (op=0x23, rs=6, rt=2)
        lw_after_mfc1 = (0x23 << 26) | (6 << 21) | (2 << 16) | 0x0000

        sig3, refs3 = C.analyse([lui_a2, mfc1_a2, lw_after_mfc1])
        self.assertEqual(refs3, [("hi", 0, 0x80010000)])
        self.assertEqual(sig3[2], lw_after_mfc1)


if __name__ == "__main__":
    unittest.main()
