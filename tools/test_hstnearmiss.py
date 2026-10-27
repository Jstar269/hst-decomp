#!/usr/bin/env python3
"""Synthetic tests for the near-miss levers (hstnearmiss.route and relocated_words)."""
from __future__ import annotations

import struct
import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import hstnearmiss as N

ADDIU_SP = 0x27BDFFE0
JR_RA = N.JR_RA
NOP = 0


def addu(rd: int, rs: int, rt: int) -> int:
    return (rs << 21) | (rt << 16) | (rd << 11) | 0x21


def lw(rt: int, base: int, imm: int) -> int:
    return (0x23 << 26) | (base << 21) | (rt << 16) | (imm & 0xFFFF)


def lui(rt: int, imm: int) -> int:
    return (0x0F << 26) | (rt << 16) | imm


def jal(target: int) -> int:
    return (3 << 26) | (target >> 2)


def jalr(rs: int) -> int:
    return (rs << 21) | (31 << 11) | 9


def beq(rs: int, rt: int, off: int) -> int:
    return (4 << 26) | (rs << 21) | (rt << 16) | (off & 0xFFFF)


def bne(rs: int, rt: int, off: int) -> int:
    return (5 << 26) | (rs << 21) | (rt << 16) | (off & 0xFFFF)


def lb(rt: int, base: int, imm: int) -> int:
    return (0x20 << 26) | (base << 21) | (rt << 16) | imm


def lbu(rt: int, base: int, imm: int) -> int:
    return (0x24 << 26) | (base << 21) | (rt << 16) | imm


def lever(ours: list[int], theirs: list[int], relocated: set[int] | None = None) -> str:
    cls, _facets = N.classify_words(ours, theirs)
    return N.route(cls, ours, theirs, relocated)[0]


class RouteTests(unittest.TestCase):
    def test_register_colouring_goes_to_the_permuter(self) -> None:
        self.assertEqual(lever([ADDIU_SP, addu(2, 4, 5), lw(3, 4, 8), JR_RA],
                               [ADDIU_SP, addu(3, 4, 5), lw(2, 4, 8), JR_RA]), "permute")

    def test_schedule_goes_to_the_permuter(self) -> None:
        self.assertEqual(lever([ADDIU_SP, addu(2, 4, 5), lw(3, 4, 8), JR_RA],
                               [ADDIU_SP, lw(3, 4, 8), addu(2, 4, 5), JR_RA]), "permute")

    def test_a_missing_call_is_body_work_even_when_registers_also_differ(self) -> None:
        ours = [ADDIU_SP, addu(2, 4, 5), JR_RA]
        theirs = [ADDIU_SP, jal(0x1000), addu(3, 4, 5), JR_RA]
        self.assertEqual(lever(ours, theirs), "body")

    def test_an_indirect_call_counts_as_a_call(self) -> None:
        self.assertEqual(lever([ADDIU_SP, jalr(2), NOP, JR_RA], [ADDIU_SP, NOP, NOP, JR_RA]), "body")

    def test_a_different_callee_at_the_same_place_is_a_referent(self) -> None:
        route = N.route("unknown", [ADDIU_SP, jal(0x1000), JR_RA], [ADDIU_SP, jal(0x2000), JR_RA], None)
        self.assertEqual(route[0], "referent")

    def test_different_callees_with_other_changes_are_body_work(self) -> None:
        self.assertEqual(lever([ADDIU_SP, jal(0x1000), addu(2, 4, 5), JR_RA],
                               [ADDIU_SP, jal(0x2000), JR_RA]), "body")

    def test_an_extra_branch_is_structure(self) -> None:
        self.assertEqual(lever([ADDIU_SP, beq(4, 0, 2), addu(2, 4, 5), JR_RA],
                               [ADDIU_SP, addu(2, 4, 5), JR_RA]), "structure")

    def test_an_inverted_condition_is_structure(self) -> None:
        route = N.route("branch_shape", [ADDIU_SP, beq(4, 0, 2), JR_RA], [ADDIU_SP, bne(4, 0, 2), JR_RA], None)
        self.assertEqual(route[0], "structure")
        self.assertIn("branch kinds", route[1])

    def test_likely_vs_normal_is_named_as_such(self) -> None:
        beql = lambda rs, rt, off: (0x14 << 26) | (rs << 21) | (rt << 16) | (off & 0xFFFF)
        route = N.route("branch_shape", [ADDIU_SP, beql(2, 3, -9), JR_RA], [ADDIU_SP, beq(2, 3, -9), JR_RA], None)
        self.assertEqual(route[0], "structure")
        self.assertIn("likely vs normal", route[1])
        bc1tl, bc1t = 0x45030007, 0x45010006
        self.assertIn("likely vs normal", N.route("unknown", [ADDIU_SP, bc1tl, JR_RA], [ADDIU_SP, bc1t, JR_RA], None)[1])

    def test_a_branch_offset_alone_is_not_structure(self) -> None:
        # an offset moves when instructions are added elsewhere; the branch itself is the same
        ours = [ADDIU_SP, beq(4, 0, 3), lw(3, 4, 8), addu(2, 4, 5), JR_RA]
        theirs = [ADDIU_SP, beq(4, 0, 2), lw(3, 4, 8), JR_RA]
        self.assertEqual(lever(ours, theirs), "expression")

    def test_an_extra_return_is_structure(self) -> None:
        self.assertEqual(lever([ADDIU_SP, JR_RA, NOP, JR_RA], [ADDIU_SP, NOP, NOP, JR_RA]), "structure")

    def test_relocated_fields_only_is_a_referent(self) -> None:
        ours = [ADDIU_SP, lui(2, 0x3b), lw(3, 2, 0x10), JR_RA]
        theirs = [ADDIU_SP, lui(2, 0x3c), lw(3, 2, 0x20), JR_RA]
        self.assertEqual(lever(ours, theirs, relocated={1, 2}), "referent")

    def test_the_same_change_without_relocations_is_a_wrong_constant(self) -> None:
        ours = [ADDIU_SP, lui(2, 0x3b), lw(3, 2, 0x10), JR_RA]
        theirs = [ADDIU_SP, lui(2, 0x3c), lw(3, 2, 0x20), JR_RA]
        self.assertEqual(lever(ours, theirs, relocated=set()), "expression")
        self.assertEqual(lever(ours, theirs, relocated=None), "expression")

    def test_a_relocated_word_with_a_different_register_is_not_a_referent(self) -> None:
        ours = [ADDIU_SP, lw(3, 2, 0x10), JR_RA]
        theirs = [ADDIU_SP, lw(4, 2, 0x20), JR_RA]
        self.assertNotEqual(lever(ours, theirs, relocated={1}), "referent")

    def test_signedness_is_types(self) -> None:
        self.assertEqual(lever([ADDIU_SP, lb(2, 4, 3), JR_RA], [ADDIU_SP, lbu(2, 4, 3), JR_RA]), "types")

    def test_frame_only_is_frame(self) -> None:
        self.assertEqual(lever([ADDIU_SP, lw(3, 29, 16), JR_RA], [0x27BDFFD0, lw(3, 29, 32), JR_RA]), "frame")

    def test_states_without_words_keep_their_lever(self) -> None:
        self.assertEqual(N.route("tool_state", None, None)[0], "tooling")
        self.assertEqual(N.route("exact_now", None, None)[0], "install")
        self.assertEqual(N.route("superseded", [1], [2])[0], "none")

    def test_every_class_has_a_lever_and_every_lever_an_entry(self) -> None:
        self.assertEqual(set(N.CLASS_LEVER), set(N.CLASSES))
        self.assertTrue(set(N.CLASS_LEVER.values()) <= set(N.LEVERS))


def elf_with_rel(text: bytes, symbol: str, sym_value: int, sym_size: int, rel_offsets: list[int],
                 rel_section_info: int = 1) -> bytes:
    """A minimal little-endian ELF32 relocatable: null, .text, .rel.text, .symtab, .strtab, .shstrtab."""
    shstr = b"\0.text\0.rel.text\0.symtab\0.strtab\0.shstrtab\0"
    off = {n: shstr.index(n.encode() + b"\0") for n in (".text", ".rel.text", ".symtab", ".strtab", ".shstrtab")}
    strtab = b"\0" + symbol.encode() + b"\0"
    symtab = bytes(16) + struct.pack("<IIIBBH", 1, sym_value, sym_size, 0x12, 0, 1)
    rel = b"".join(struct.pack("<II", o, (1 << 8) | 4) for o in rel_offsets)
    blobs = [text, rel, symtab, strtab, shstr]
    pos, offsets = 52, []
    for b in blobs:
        offsets.append(pos)
        pos += len(b)
    shoff = pos
    def sh(name, typ, flags, offset, size, link, info, align, entsize):
        return struct.pack("<IIIIIIIIII", name, typ, flags, 0, offset, size, link, info, align, entsize)
    shdrs = [bytes(40),
             sh(off[".text"], 1, 6, offsets[0], len(text), 0, 0, 4, 0),
             sh(off[".rel.text"], 9, 0, offsets[1], len(rel), 3, rel_section_info, 4, 8),
             sh(off[".symtab"], 2, 0, offsets[2], len(symtab), 4, 1, 4, 16),
             sh(off[".strtab"], 3, 0, offsets[3], len(strtab), 0, 0, 1, 0),
             sh(off[".shstrtab"], 3, 0, offsets[4], len(shstr), 0, 0, 1, 0)]
    ehdr = (b"\x7fELF\x01\x01\x01" + bytes(9) +
            struct.pack("<HHIIIIIHHHHHH", 1, 8, 1, 0, 0, shoff, 0, 52, 0, 0, 40, len(shdrs), 5))
    return ehdr + b"".join(blobs) + b"".join(shdrs)


class RelocatedWordsTests(unittest.TestCase):
    H = {"symbol": "FUN_00001000", "start": 0x1000, "end": 0x1010}

    def test_offsets_become_word_indexes_from_the_symbol(self) -> None:
        obj = elf_with_rel(bytes(32), "FUN_00001000", 8, 16, [8, 12, 20, 28])
        self.assertEqual(N.relocated_words(obj, self.H), {0, 1, 3})   # 28 is past the function

    def test_relocations_of_another_section_are_ignored(self) -> None:
        obj = elf_with_rel(bytes(16), "FUN_00001000", 0, 16, [4], rel_section_info=4)
        self.assertEqual(N.relocated_words(obj, self.H), set())

    def test_unknown_symbol_or_helpers_give_none(self) -> None:
        obj = elf_with_rel(bytes(16), "FUN_00002000", 0, 16, [4])
        self.assertIsNone(N.relocated_words(obj, self.H))
        self.assertIsNone(N.relocated_words(obj, {**self.H, "symbol": "FUN_00002000", "helpers": [("h", 0, 4)]}))


class QueueFieldTests(unittest.TestCase):
    def test_items_carry_the_lever_and_its_digest_sections(self) -> None:
        import hstqueue as Q
        fields = Q.lever_fields({"class": "missing_extra_insn", "lever": "body", "lever_why": "calls 3 vs retail 4"})
        self.assertEqual(fields, {"near_class": "missing_extra_insn", "lever": "body", "lever_why": "calls 3 vs retail 4",
                                  "lever_digest": N.LEVERS["body"][0]})

    def test_rows_without_a_lever_add_nothing(self) -> None:
        import hstqueue as Q
        self.assertEqual(Q.lever_fields(None), {})
        self.assertEqual(Q.lever_fields({"class": "unknown"}), {})

    def test_the_queue_knows_every_lever(self) -> None:
        import hstqueue as Q
        self.assertEqual(set(Q.LEVER_NAMES), set(N.LEVERS))


if __name__ == "__main__":
    unittest.main()
