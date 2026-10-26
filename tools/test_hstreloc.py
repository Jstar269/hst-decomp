#!/usr/bin/env python3
"""Synthetic-only tests for PSP relocation tables and PSP container format (hstreloc.py)."""
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


def jal(target: int) -> int:
    return 0x0C000000 | ((target >> 2) & 0x03FFFFFF)


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

    def test_encode_and_decode_roundtrip(self) -> None:
        entries = [
            R.Entry(0x00, R.R_MIPS_HI16, 0, 0),
            R.Entry(0x04, R.R_MIPS_LO16, 0, 0),
            R.Entry(0x08, R.R_MIPS_32, 1, 1),
            R.Entry(0x0C, R.R_MIPS_26, 0, 1),
        ]
        encoded = R.encode_a(entries)
        self.assertEqual(len(encoded), 32)
        decoded = R.decode_a(encoded, nseg=2)
        self.assertEqual(decoded, entries)

    def test_decode_validation_errors(self) -> None:
        # Non-multiple of 8
        with self.assertRaises(ValueError) as cm:
            R.decode_a(b"\x00" * 7)
        self.assertIn("not a multiple of 8", str(cm.exception))

        # Bits 24-31 not zero
        bad_info = struct.pack("<II", 0x100, R.R_MIPS_32 | (1 << 24))
        with self.assertRaises(ValueError) as cm:
            R.decode_a(bad_info)
        self.assertIn("bits 24-31 of r_info are 0x1", str(cm.exception))

        # Segment index beyond nseg
        seg_out = struct.pack("<II", 0x100, R.R_MIPS_32 | (2 << 8))  # oseg=2
        with self.assertRaises(ValueError) as cm:
            R.decode_a(seg_out, nseg=2)
        self.assertIn("beyond the 2 segments", str(cm.exception))

        # Unknown relocation type
        unknown_type = struct.pack("<II", 0x100, 99)
        with self.assertRaises(ValueError) as cm:
            R.decode_a(unknown_type)
        self.assertIn("relocation type 99 is not one this tool knows", str(cm.exception))

    def test_partner_index(self) -> None:
        entries = [
            R.Entry(0x00, R.R_MIPS_HI16),
            R.Entry(0x04, R.R_MIPS_HI16),
            R.Entry(0x08, R.R_MIPS_LO16),
            R.Entry(0x0C, R.R_MIPS_32),
            R.Entry(0x10, R.R_MIPS_HI16),
            R.Entry(0x14, R.R_MIPS_LO16),
        ]
        partners = R.partner_index(entries)
        self.assertEqual(partners, [2, 2, None, None, 5, None])

        # HI16 at end without partner
        bad_entries = [R.Entry(0x00, R.R_MIPS_HI16)]
        with self.assertRaises(ValueError) as cm:
            R.partner_index(bad_entries)
        self.assertIn("HI16 run at entry 0 has no partner", str(cm.exception))


class FormatBTests(unittest.TestCase):
    def test_decode_b_success(self) -> None:
        # Header: 2 zero bytes, f=2, t=3, nf=3, nk=3
        # Flags table: count=3, [0, 0x00, 0x01] -> index 1: set-offset (g&6 == 0), index 2: reloc (g&6 == 0, addend form 0)
        # Kinds table: count=3, [0, 2 (R_MIPS_32), 4 (R_MIPS_HI16)]
        f, t = 2, 3
        flags = bytes([3, 0x00, 0x01])
        kinds = bytes([3, 2, 4])
        # Commands (16-bit):
        # Cmd 1: set offset. cur_off = cc >> (f + segw). With f=2, segw=1 (nseg=2), shift is 3. 0x10 << 3.
        # Cmd 2: reloc. fi=2, seg=1, ki=1, draw=0 -> cur_off += 0 -> 0x10, kind=2 (R_MIPS_32)
        cmd1 = 1 | (0 << 2) | (0x10 << 3)
        cmd2 = 2 | (1 << 2) | (1 << 3) | (0 << 6)
        data = bytes([0, 0, f, t]) + flags + kinds + struct.pack("<HH", cmd1, cmd2)

        res = R.decode_b(data, nseg=2)
        self.assertEqual(len(res), 1)
        self.assertEqual(res[0], R.EntryB(oseg=0, offset=0x10, kind=2, aseg=1, addend=0))
        self.assertEqual(res[0].type, R.R_MIPS_32)

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
        # Test set-offset 32-bit (g&6 == 4) and addend 16-bit (b345 == 2)
        f, t = 2, 3
        # g = 0x01 (reloc) | (1 << 1) (g&6 == 2: 16-bit ext offset) | (2 << 3) (b345 == 2: 16-bit addend) = 0x13
        flags = bytes([3, 0x04, 0x13])  # index 1: g&6 == 4 (set-offset 32-bit), index 2: g=0x13
        kinds = bytes([2, 4])          # index 1: kind 4 (R_MIPS_HI16)

        cmd1 = 1 | (0 << 2) | (0 << 3)
        cmd2 = 2 | (0 << 2) | (1 << 3)
        data = bytes([0, 0, f, t]) + flags + kinds + struct.pack("<H", cmd1) + struct.pack("<I", 0x1000) + struct.pack("<H", cmd2) + struct.pack("<H", 0x10) + struct.pack("<H", 0x8000)

        res = R.decode_b(data, nseg=1)
        self.assertEqual(len(res), 1)
        self.assertEqual(res[0].offset, 0x1010)
        self.assertEqual(res[0].addend, -32768)


class RecoverTargetsTests(unittest.TestCase):
    def test_recover_targets_all_types(self) -> None:
        code = words(
            lui(2, 0x0001),         # 0x00: HI16 (target high = 0x0001)
            addiu(4, 2, -0x7FFC),   # 0x04: LO16 partner (imm = -0x7FFC -> 0x00010000 + (-0x7FFC) = 0x8004)
            jal(0x1000),            # 0x08: R_MIPS_26
            0x00002000,             # 0x0C: R_MIPS_32
            lw(5, 2, 0x0010),       # 0x10: Standalone LO16 (rs=2=$v0, matches the earlier lui)
        )

        entries = [
            R.Entry(0x00, R.R_MIPS_HI16),
            R.Entry(0x04, R.R_MIPS_LO16),
            R.Entry(0x08, R.R_MIPS_26),
            R.Entry(0x0C, R.R_MIPS_32),
            R.Entry(0x10, R.R_MIPS_LO16),
        ]

        def word_at(addr: int) -> int:
            return struct.unpack_from("<I", code, addr)[0]

        def function_of(addr: int) -> tuple[int, int]:
            return (0, 0x20)

        def inside(addr: int) -> bool:
            return 0 <= addr < 0x100000

        targets = R.recover_targets(entries, word_at, function_of, inside)
        self.assertEqual(targets[0], 0x8004)       # HI16 target
        self.assertEqual(targets[1], 0x8004)       # Paired LO16 target
        self.assertEqual(targets[2], 0x00001000)  # R_MIPS_26 target
        self.assertEqual(targets[3], 0x00002000)  # R_MIPS_32 target
        self.assertEqual(targets[4], 0x00010010)  # Standalone LO16 target (high from lui 0x1, low 0x10)


class OrderTests(unittest.TestCase):
    def test_block_owner_and_runs(self) -> None:
        entries = [
            R.Entry(0x04, R.R_MIPS_HI16),
            R.Entry(0x14, R.R_MIPS_LO16),
            R.Entry(0x08, R.R_MIPS_32),
            R.Entry(0x18, R.R_MIPS_32),
        ]

        # owner_of: addresses < 0x10 belong to tile 0, >= 0x10 belong to tile 1
        def owner_of(addr: int) -> int:
            return 1 if addr >= 0x10 else 0

        # HI16 at 0x04 has partner LO16 at 0x14 (owner 1), so HI16 owner becomes 1
        owners = R.block_owner(entries, owner_of)
        self.assertEqual(owners, [1, 1, 0, 1])

        runs = R.runs_of(owners)
        self.assertEqual(runs, [(1, 0, 2), (0, 2, 1), (1, 3, 1)])

        self.assertFalse(R.is_address_ordered(runs))

        ordered_runs = R.runs_of([0, 0, 1, 1, 2])
        self.assertTrue(R.is_address_ordered(ordered_runs))


class ShiftTests(unittest.TestCase):
    def test_shift_delta(self) -> None:
        shift = R.Shift(n=0x100, data_start=0x1000)
        self.assertEqual(shift.delta(0x500), 0x100)
        self.assertEqual(shift.delta(0x1000), 0x200)
        self.assertEqual(shift.delta(0x2000), 0x200)

    def test_lo16_class_targets_and_shift_failure(self) -> None:
        # Candidate 1: lui $v0, 0x0000 (target 0x0010 < 0x1000, code)
        # Candidate 2: lui $v0, 0x0001 (target 0x1010 >= 0x1000, data)
        # Standalone LO16 at 0x08: lw $a0, 0x10($v0)
        code = words(
            lui(2, 0x0000),       # 0x00: HI16 (paired with LO16 at 0x04)
            addiu(2, 2, 0x0000),  # 0x04: LO16 partner
            lui(2, 0x0001),       # 0x08: HI16 (standalone, for register $v0)
            lw(5, 2, 0x0010),     # 0x0C: standalone LO16 reading $v0 (k=3, k-1 is HI16 so we need non-HI16 before it)
        )
        # To make 0x0C standalone, let's insert a dummy R_MIPS_32 at 0x0B or place entries appropriately:
        code_standalone = words(
            lui(2, 0x0000),       # 0x00: HI16
            lui(2, 0x0001),       # 0x04: HI16
            0x00000000,           # 0x08: dummy word
            lw(5, 2, 0x0010),     # 0x0C: standalone LO16
        )
        entries = [
            R.Entry(0x00, R.R_MIPS_HI16),
            R.Entry(0x04, R.R_MIPS_HI16),
            R.Entry(0x08, R.R_MIPS_32),
            R.Entry(0x0C, R.R_MIPS_LO16),  # k=3, entries[2] is R_MIPS_32 -> standalone!
        ]

        def word_at(addr: int) -> int:
            return struct.unpack_from("<I", code_standalone, addr)[0]

        def function_of(addr: int) -> tuple[int, int]:
            return (0, 0x10)

        # Disagreement between candidate HI16 targets (0x0010 code vs 0x1010 data) -> ShiftFailure
        with self.assertRaises(R.ShiftFailure) as cm:
            R.lo16_class_targets(entries, word_at, function_of, data_start=0x1000)
        self.assertIn("cannot tell code from data", str(cm.exception))

    def test_shifted_table(self) -> None:
        self.assertEqual(
            R.shifted_table([R.Entry(0x100, R.R_MIPS_32)], R.Shift(0x80, 0x1000)),
            [R.Entry(0x180, R.R_MIPS_32)]
        )


class ContainerAndModuleTests(unittest.TestCase):
    def test_write_module_and_module_start(self) -> None:
        lib_ent = struct.pack("<IHHBBHI", 0, 0, 0x8000, 4, 0, 1, 0x60)
        resident = struct.pack("<II", R.MODULE_START_NID, 0x8)
        sections = [
            R.OutSection(".text", 0x00, words(0, 0, 0x03E00008, 0), flags=6, rel=R.encode_a([R.Entry(0, R.R_MIPS_26)])),
            R.OutSection(".lib.ent", 0x10, lib_ent, flags=2),
            R.OutSection(".rodata.sceModuleInfo", 0x20, bytes(0x34), flags=2),
            R.OutSection(".rodata.sceResident", 0x60, resident, flags=2),
        ]

        def word_at(addr: int) -> int:
            for s in sections:
                if s.data and s.addr <= addr < s.addr + len(s.data):
                    return struct.unpack_from("<I", s.data, addr - s.addr)[0]
            return 0

        m_start = R.module_start(sections[1].data, word_at)
        self.assertEqual(m_start, 0x8)

        blob, parts = R.write_module(R.PROFILES["eboot"], sections, entry=m_start, comment=b"TEST", memsz_end=0x100)
        self.assertIn("elf_header", parts)
        self.assertIn("program_header", parts)
        self.assertTrue(blob.startswith(b"\x7fELF"))


if __name__ == "__main__":
    unittest.main()
