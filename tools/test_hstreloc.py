#!/usr/bin/env python3
"""Synthetic-only tests for hstreloc.py: the bit helpers, the format-A info layout, format-B extended and refused
forms, and the standalone-LO16 code/data classification. The format-A round trip, partner_index, basic format-B
commands, recover_targets, block order, Shift and write_module are covered in test_hstbuild.py."""
from __future__ import annotations

import struct
import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import hstreloc as R


def lui(rt: int, imm: int) -> int:
    return 0x3C000000 | (rt << 16) | (imm & 0xFFFF)


def addiu(rt: int, rs: int, imm: int) -> int:
    return 0x24000000 | (rs << 21) | (rt << 16) | (imm & 0xFFFF)


def lw(rt: int, rs: int, imm: int) -> int:
    return 0x8C000000 | (rs << 21) | (rt << 16) | (imm & 0xFFFF)


def words(*ws: int) -> bytes:
    return b"".join(struct.pack("<I", w) for w in ws)


class BitHelpersTests(unittest.TestCase):
    def test_sext16(self) -> None:
        self.assertEqual(R.sext16(0x0000), 0)
        self.assertEqual(R.sext16(0x7FFF), 32767)
        self.assertEqual(R.sext16(0x8000), -32768)
        self.assertEqual(R.sext16(0xFFFF), -1)
        self.assertEqual(R.sext16(0x12345678), 22136)  # mask to 0x5678

    def test_rs_and_rt_of(self) -> None:
        # Instruction: addiu $a0, $v0, 0x10 -> rs=$v0 (2), rt=$a0 (4)
        w = addiu(4, 2, 0x10)
        self.assertEqual(R.rs_of(w), 2)
        self.assertEqual(R.rt_of(w), 4)

    def test_first_difference(self) -> None:
        self.assertIsNone(R.first_difference(b"abc", b"abc"))
        self.assertEqual(R.first_difference(b"abc", b"abd"), 2)
        self.assertEqual(R.first_difference(b"abc", b"abcd"), 3)
        self.assertEqual(R.first_difference(b"abcd", b"abc"), 3)


class FormatATests(unittest.TestCase):
    def test_entry_properties_and_info(self) -> None:
        e = R.Entry(0x100, R.R_MIPS_32, oseg=1, aseg=2)
        self.assertEqual(e.offset, 0x100)
        self.assertEqual(e.type, R.R_MIPS_32)
        self.assertEqual(e.oseg, 1)
        self.assertEqual(e.aseg, 2)
        self.assertEqual(e.info, R.R_MIPS_32 | (1 << 8) | (2 << 16))


class FormatBTests(unittest.TestCase):
    def test_decode_b_validation_errors(self) -> None:
        # Too short header
        with self.assertRaises(ValueError) as cm:
            R.decode_b(b"\x00\x00\x01", nseg=1)
        self.assertIn("format B header", str(cm.exception))

        # Invalid first two bytes
        with self.assertRaises(ValueError) as cm:
            R.decode_b(b"\x01\x00\x01\x01\x01", nseg=1)
        self.assertIn("format B header", str(cm.exception))

        # Invalid flag index
        f, t = 2, 3
        flags = bytes([2, 0x00])
        kinds = bytes([2, 2])
        # Cmd with fi=3 (out of bounds)
        cmd = 3 | (0 << 2) | (1 << 3)
        data = bytes([0, 0, f, t]) + flags + kinds + struct.pack("<H", cmd)
        with self.assertRaises(ValueError) as cm:
            R.decode_b(data, nseg=1)
        self.assertIn("format B flag index 3", str(cm.exception))

    def test_decode_b_extended_forms(self) -> None:
        # One segment: f=2 flag bits, 1 segment bit, t=3 kind bits, so the displacement is the top 10 bits (shift 6).
        # Flag 1 (0x04): set the offset from a following 32-bit word. Flag 2 (0x13): relocate, offset form 2
        # (displacement extended by a following 16-bit word: offset += (sext(draw) << 16) | ext), addend form 2
        # (a following 16-bit addend).
        f, t = 2, 3
        flags = bytes([3, 0x04, 0x13])
        kinds = bytes([2, 4])          # index 1: kind 4 (R_MIPS_HI16)

        set_offset = 1 | (0 << 2) | (0 << 3)
        reloc_up = 2 | (0 << 2) | (1 << 3) | (0x001 << 6)     # draw +1: offset += 0x1_0010
        reloc_down = 2 | (0 << 2) | (1 << 3) | (0x3FF << 6)   # draw -1: offset += -0x1_0000 | 0x0004
        data = (bytes([0, 0, f, t]) + flags + kinds
                + struct.pack("<HI", set_offset, 0x1000)
                + struct.pack("<HHH", reloc_up, 0x0010, 0x8000)
                + struct.pack("<HHH", reloc_down, 0x0004, 0x7FFF))

        res = R.decode_b(data, nseg=1)
        self.assertEqual([(e.offset, e.addend, e.type) for e in res],
                         [(0x11010, -32768, R.R_MIPS_HI16), (0x1014, 32767, R.R_MIPS_HI16)])


class Lo16ClassTests(unittest.TestCase):
    # A standalone LO16 (its previous entry is not a HI16) at 0x0c: lw $a1, 0x10($v0).
    ENTRIES = [
        R.Entry(0x00, R.R_MIPS_HI16),
        R.Entry(0x04, R.R_MIPS_HI16),
        R.Entry(0x08, R.R_MIPS_32),
        R.Entry(0x0C, R.R_MIPS_LO16),
    ]

    @staticmethod
    def classify(code: bytes) -> dict[int, bool]:
        return R.lo16_class_targets(Lo16ClassTests.ENTRIES, lambda a: struct.unpack_from("<I", code, a)[0],
                                    lambda a: (0, 0x10), data_start=0x1000)

    def test_lo16_class_targets_and_shift_failure(self) -> None:
        # Both HI16 load $v0, the register the LO16 reads: lui $v0,0 gives 0x00000010 (code, below data_start) and
        # lui $v0,1 gives 0x00010010 (data). The candidates disagree, so the LO16 cannot be classified.
        code = words(lui(2, 0x0000), lui(2, 0x0001), 0x00000000, lw(5, 2, 0x0010))
        with self.assertRaises(R.ShiftFailure) as cm:
            self.classify(code)
        self.assertIn("cannot tell code from data", str(cm.exception))

    def test_lo16_class_follows_the_register_it_reads(self) -> None:
        # Only lui $v0,1 writes $v0; lui $a0,0 (a code address) is not a candidate, so the LO16 is data.
        code = words(lui(4, 0x0000), lui(2, 0x0001), 0x00000000, lw(5, 2, 0x0010))
        self.assertEqual(self.classify(code), {3: True})


if __name__ == "__main__":
    unittest.main()
