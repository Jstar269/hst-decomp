#!/usr/bin/env python3
"""Synthetic, game-free tests for tools/hstdatapool.py (string-literal pools of matched functions).

    python tools/test_hstdatapool.py
"""
from __future__ import annotations

import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import hstdatapool as D  # noqa: E402

BASE = 0x1000
REGION = (0x1000, 0x1100)


def blob_of(*parts: bytes) -> bytes:
    out = b""
    for p in parts:
        out += p + b"\0" * (-len(p) % 4)
    return out


class Extent(unittest.TestCase):
    def test_well_formed(self):
        b = blob_of(b"abc\0", b"hello\0")
        self.assertEqual(D.string_extent(b, 0), 3)
        self.assertEqual(D.string_extent(b, 4), 5)

    def test_unaligned_or_binary(self):
        b = blob_of(b"abc\0", b"\x01\x02\0")
        self.assertIsNone(D.string_extent(b, 1))
        self.assertIsNone(D.string_extent(b, 4))

    def test_nonzero_padding(self):
        self.assertIsNone(D.string_extent(b"ab\0x", 0))

    def test_high_bytes_are_text(self):
        self.assertEqual(D.string_extent(blob_of(b"\x82\xa0\0"), 0), 2)


class Literal(unittest.TestCase):
    def test_escapes(self):
        self.assertEqual(D.c_literal(b'a"b\\c\n\t\r'), r'"a\"b\\c\n\t\r"')

    def test_octal_not_hex(self):
        self.assertEqual(D.c_literal(b"\x82" + b"1"), r'"\2021"')

    def test_trigraph(self):
        self.assertEqual(D.c_literal(b"??="), r'"?\?="')


def refs_for(entries):
    out = {}
    for t, site, kind in entries:
        out.setdefault(t, []).append(D.Ref(t, site, kind))
    return out


class Runs(unittest.TestCase):
    blob = blob_of(b"one\0", b"three\0", b"x\0", b"shared\0")   # 0x1000, 0x1004, 0x100c, 0x1010

    def runs(self, entries, fn=(0x100, 0x200)):
        refs = refs_for(entries)
        return D.runs_of(fn, refs, sorted(refs), self.blob, BASE, REGION)

    def test_contiguous_exclusive(self):
        self.assertEqual(self.runs([(0x1000, 0x104, "addiu"), (0x1004, 0x108, "addiu"), (0x100C, 0x10C, "addiu")]),
                         [[(0x1000, 3), (0x1004, 5), (0x100C, 1)]])

    def test_relocated_pointer_inside_is_not_a_string(self):
        # a pointer table entry whose bytes happen to look like text (FUN_001b29b0's 0x002e9944 in EBOOT) has an
        # R_MIPS_32 site inside it: it is data, never a literal
        got = self.runs([(0x1000, 0x104, "addiu"), (0x1004, 0x108, "addiu"), (0x9000, 0x1004, "ptr")])
        self.assertEqual(got, [[(0x1000, 3)]])

    def test_foreign_reference_breaks_the_run(self):
        got = self.runs([(0x1000, 0x104, "addiu"), (0x1004, 0x108, "addiu"), (0x1004, 0x300, "addiu"),
                         (0x100C, 0x10C, "addiu")])
        self.assertEqual(got, [[(0x1000, 3)], [(0x100C, 1)]])

    def test_data_pointer_or_load_excludes(self):
        self.assertEqual(self.runs([(0x1000, 0x104, "addiu"), (0x1000, 0x1050, "ptr")]), [])
        self.assertEqual(self.runs([(0x1000, 0x104, "addiu"), (0x1000, 0x108, "lo-other")]), [])

    def test_interior_reference_excludes(self):
        self.assertEqual(self.runs([(0x1004, 0x104, "addiu"), (0x1006, 0x300, "addiu")]), [])

    def test_gap_splits(self):
        got = self.runs([(0x1000, 0x104, "addiu"), (0x100C, 0x10C, "addiu")])
        self.assertEqual(got, [[(0x1000, 3)], [(0x100C, 1)]])


SOURCE = '''/* HSTMATCH module=EBOOT.BIN start=0x00000100 end=0x00000200 symbol=FUN_00000100 lang=c99 */
/* Hand-written reconstruction from the disassembly; names and types await human review. */
extern char DAT_00001000[]; /* "one" */
extern char DAT_00001004[];
extern char DAT_00002000[];
extern char DAT_00001010;
void FUN_00000300(const char *s);

void FUN_00000100(void)
{
    FUN_00000300(DAT_00001000);   /* DAT_00001004 in a comment stays */
    FUN_00000300(DAT_00001004);
    FUN_00000300(DAT_00002000);
    FUN_00000300(&DAT_00001010);
}
'''


class Rewrite(unittest.TestCase):
    def test_substitution(self):
        new, why = D.rewrite(SOURCE, {"DAT_00001000": b"one", "DAT_00001004": b"three", "DAT_00001010": b"s"},
                             0x1000, "NOTE.")
        self.assertEqual(why, "")
        self.assertIn("symbol=FUN_00000100 lang=c99 data=0x00001000 */", new.splitlines()[0])
        self.assertTrue(new.splitlines()[1].endswith("review. NOTE. */"))
        self.assertIn('FUN_00000300("one");', new)
        self.assertIn('FUN_00000300("three");', new)
        self.assertIn('FUN_00000300("s");', new)
        self.assertIn("FUN_00000300(DAT_00002000);", new)
        self.assertIn("/* DAT_00001004 in a comment stays */", new)
        self.assertNotIn("extern char DAT_00001000", new)
        self.assertIn("extern char DAT_00002000[];", new)
        self.assertTrue(D.first_use_order(new, ['"one"', '"three"']))
        self.assertFalse(D.first_use_order(new, ['"three"', '"one"']))

    def test_refusals(self):
        _n, why = D.rewrite(SOURCE.replace("lang=c99", "lang=c99 data=0x1000"), {"DAT_00001000": b"one"}, 0x1000, "N")
        self.assertIn("already places data", why)
        _n, why = D.rewrite(SOURCE.replace("(DAT_00001000)", "(DAT_00001000 + 1)").replace(
            "FUN_00000300(DAT_00001004);", 'FUN_00000300("lit");'), {"DAT_00001000": b"one"}, 0x1000, "N")
        self.assertIn("already has string literals", why)
        _n, why = D.rewrite(SOURCE.replace("(DAT_00001000)", "(&DAT_00001000[1])"), {"DAT_00001000": b"one"},
                            0x1000, "N")
        self.assertIn("used other than", why)
        _n, why = D.rewrite(SOURCE.replace("(&DAT_00001010)", "(DAT_00001010)"), {"DAT_00001010": b"s"}, 0x1000, "N")
        self.assertIn("scalar extern", why)
        _n, why = D.rewrite(SOURCE, {"DAT_00003000": b"z"}, 0x1000, "N")
        self.assertIn("0 matching extern char declarations", why)


TABLE_SOURCE = """/* HSTMATCH module=EBOOT.BIN start=0x00000100 end=0x00000200 symbol=FUN_00000100 lang=c++ */
/* Hand-written reconstruction; exact match verified. */
extern "C" {
extern const char *DAT_00001008[];
void FUN_00000300(const char *);
extern char *DAT_00001014;
}
void FUN_00000100(int i) { FUN_00000300(DAT_00001008[i]); FUN_00000300(DAT_00001014); }
"""


class Tables(unittest.TestCase):
    def test_pointer_tables_from_relocations(self):
        blob = blob_of(b"ab\0", b"c\0", b"\0\0\0\0", b"\0\0\0\0")   # strings 0x1000/0x1004, table 0x1008 (2 entries)
        refs = refs_for([(0x1000, 0x1008, "ptr"), (0x1004, 0x100C, "ptr"), (0x1008, 0x110, "addiu")])
        region = D.REGIONS["EBOOT.BIN"]
        D.REGIONS["EBOOT.BIN"] = REGION
        try:
            tables, _why = D.string_tables("EBOOT.BIN", blob, BASE, refs)
        finally:
            D.REGIONS["EBOOT.BIN"] = region
        self.assertEqual(tables, [{"table": 0x1008, "entries": [0x1000, 0x1004], "lo": 0x1000, "hi": 0x1010,
                                   "users": [0x110]}])

    def test_rewrite_tables(self):
        new, why = D.rewrite_tables(TABLE_SOURCE, [("DAT_00001008", [b"ab", b"c"]), ("DAT_00001014", [b"x"])],
                                    0x1000, "N")
        self.assertEqual(why, "")
        self.assertIn("data=0x00001000 */", new.splitlines()[0])
        self.assertIn('const char *DAT_00001008[] = {\n    "ab",\n    "c",\n};\nchar *DAT_00001014 = "x";\n', new)
        self.assertNotIn("extern char *DAT_00001014", new)
        self.assertIn("FUN_00000300(DAT_00001008[i]);", new)

    def test_rewrite_tables_refusals(self):
        _n, why = D.rewrite_tables(TABLE_SOURCE, [("DAT_00001014", [b"x", b"y"])], 0x1000, "N")
        self.assertIn("one pointer", why)
        _n, why = D.rewrite_tables(TABLE_SOURCE.replace("lang=c++", "lang=c++ data=0x1"), [("DAT_00001008", [b"a"])],
                                   0x1000, "N")
        self.assertIn("already places data", why)


if __name__ == "__main__":
    unittest.main()
