#!/usr/bin/env python3
"""Unit tests for the candidate mismatch classifier (hstcat.py)."""
from __future__ import annotations

import io
import json
import sys
import tempfile
import unittest
from pathlib import Path
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parent))
import hstcat as C


class WordsTests(unittest.TestCase):
    def test_words_converts_little_endian_bytes(self) -> None:
        data = b"\x01\x02\x03\x04\x05\x06\x07\x08"
        self.assertEqual(C.words(data), [0x04030201, 0x08070605])

    def test_words_truncates_trailing_incomplete_words(self) -> None:
        data = b"\x01\x00\x00\x00\x02\x00"
        self.assertEqual(C.words(data), [1])

    def test_words_empty_input(self) -> None:
        self.assertEqual(C.words(b""), [])


class OpcodeKeyTests(unittest.TestCase):
    def test_special_opcode(self) -> None:
        # op = 0 (SPECIAL), function field in lowest 6 bits (0x20 = ADD)
        word = 0x00852020
        self.assertEqual(C.opcode_key(word), (0, 0x20))

    def test_regimm_opcode(self) -> None:
        # op = 1 (REGIMM), rt field in bits 16-20 (0x01 = BGEZ)
        word = (1 << 26) | (1 << 16)
        self.assertEqual(C.opcode_key(word), (1, 1))

    def test_standard_opcode(self) -> None:
        # op = 0x09 (ADDIU)
        word = 0x25080001
        self.assertEqual(C.opcode_key(word), (0x09, 0))


class ClassifyTests(unittest.TestCase):
    def test_frame_mismatch(self) -> None:
        # ADDIU $sp, $sp, -32 vs ADDIU $sp, $sp, -48
        ours = [(0x27BD << 16) | 0xFFE0, 0x00000000]
        theirs = [(0x27BD << 16) | 0xFFD0, 0x00000000]
        self.assertEqual(C.classify(ours, theirs), "frame")

    def test_length_mismatch(self) -> None:
        ours = [0x00000000, 0x00000000]
        theirs = [0x00000000]
        self.assertEqual(C.classify(ours, theirs), "length")

    def test_load_sign_mismatch(self) -> None:
        # lb $t0, 0($a0) vs lbu $t0, 0($a0)
        # lb opcode: 0x20, lbu opcode: 0x24
        ours = [(0x20 << 26) | 0x00880000]
        theirs = [(0x24 << 26) | 0x00880000]
        self.assertEqual(C.classify(ours, theirs), "load_sign")

    def test_regalloc_mismatch(self) -> None:
        # addiu $a0, $a0, 1 vs addiu $a1, $a1, 1
        # opcodes are both 0x09
        ours = [(0x09 << 26) | (4 << 21) | (4 << 16) | 1]
        theirs = [(0x09 << 26) | (5 << 21) | (5 << 16) | 1]
        self.assertEqual(C.classify(ours, theirs), "regalloc")

    def test_likely_mismatch(self) -> None:
        # beq $a0, $a1, target vs beql $a0, $a1, target
        # beq opcode: 0x04, beql opcode: 0x14
        ours = [(0x04 << 26) | 0x00850002, 0x00000000]
        theirs = [(0x14 << 26) | 0x00850002, 0x00000000]
        self.assertEqual(C.classify(ours, theirs), "likely")

    def test_reorder_mismatch(self) -> None:
        ours = [0x11111111, 0x22222222]
        theirs = [0x22222222, 0x11111111]
        self.assertEqual(C.classify(ours, theirs), "reorder")

    def test_other_mismatch(self) -> None:
        # Completely different opcodes
        ours = [(0x09 << 26) | 1]
        theirs = [(0x0F << 26) | 2]
        self.assertEqual(C.classify(ours, theirs), "other")


class MainTests(unittest.TestCase):
    def test_main_classifies_summary_rows_and_prints_report(self) -> None:
        with tempfile.TemporaryDirectory() as tmp:
            tmp_path = Path(tmp)
            gen_dir = tmp_path / "try" / "gen-tag"
            gen_dir.mkdir(parents=True)

            # Create summary file
            summary_data = [
                {
                    "start": 0x1000,
                    "status": "EXACT",
                    "source": "v0/func_exact.c",
                },
                {
                    "start": 0x1000,
                    "status": "MISMATCH",
                    "source": "v0/func_exact.c",  # Should be excluded because start is in exact
                },
                {
                    "start": 0x2000,
                    "status": "MISMATCH",
                    "source": "v0/func_frame.c",
                },
                {
                    "start": 0x3000,
                    "status": "MISMATCH",
                    "source": "v1/func_ignored.c",  # Ignored due to variant mismatch
                },
                {
                    "start": 0x4000,
                    "status": "MISMATCH",
                    "source": "v0/func_missing.c",  # Missing binary files
                },
            ]
            (gen_dir / "summary-0.json").write_text(json.dumps(summary_data), encoding="utf-8")

            # Create build binary files for v0/func_frame.c
            build_dir = tmp_path / "build" / "EBOOT.BIN" / "v0__func_frame"
            build_dir.mkdir(parents=True)

            ours_bytes = ((0x27BD << 16) | 0xFFE0).to_bytes(4, "little") + b"\x00\x00\x00\x00"
            theirs_bytes = ((0x27BD << 16) | 0xFFD0).to_bytes(4, "little") + b"\x00\x00\x00\x00"
            (build_dir / "text.bin").write_bytes(ours_bytes)
            (build_dir / "target.bin").write_bytes(theirs_bytes)

            test_args = ["hstcat.py", str(gen_dir), "--variant", "v0", "--module", "EBOOT.BIN", "--examples", "2"]
            captured_output = io.StringIO()

            with patch.object(C, "ROOT", tmp_path), patch.object(sys, "argv", test_args), patch("sys.stdout", captured_output):
                res = C.main()

            self.assertEqual(res, 0)
            out_str = captured_output.getvalue()
            self.assertIn("v0 mismatches classified: 1", out_str)
            self.assertIn("frame", out_str)
            self.assertIn("v0/func_frame.c", out_str)


if __name__ == "__main__":
    unittest.main()
