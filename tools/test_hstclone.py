#!/usr/bin/env python3
"""Synthetic tests for hstclone.py: words and instruction stream analysis."""
from __future__ import annotations

import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import hstclone as C


class WordsTests(unittest.TestCase):
    def test_words_empty(self) -> None:
        self.assertEqual(C.words(b""), [])

    def test_words_short_unaligned(self) -> None:
        self.assertEqual(C.words(b"\x01"), [])
        self.assertEqual(C.words(b"\x01\x02"), [])
        self.assertEqual(C.words(b"\x01\x02\x03"), [])

    def test_words_single_word(self) -> None:
        self.assertEqual(C.words(b"\x01\x02\x03\x04"), [0x04030201])

    def test_words_multiple_words(self) -> None:
        data = b"\x00\x00\x00\x00\xff\xff\xff\xff\x78\x56\x34\x12"
        expected = [0x00000000, 0xFFFFFFFF, 0x12345678]
        self.assertEqual(C.words(data), expected)

    def test_words_trailing_unaligned_bytes(self) -> None:
        data = b"\x01\x02\x03\x04\x05\x06"
        self.assertEqual(C.words(data), [0x04030201])

        data7 = b"\x01\x02\x03\x04\x05\x06\x07"
        self.assertEqual(C.words(data7), [0x04030201])


class AnalyseTests(unittest.TestCase):
    def test_analyse_calls_and_lui(self) -> None:
        # Jal (op 3), LUI (op 0x0F)
        jal_word = (3 << 26) | 0x0010000
        lui_word = (0x0F << 26) | (8 << 16) | 0x0880  # rt=8 ($t0), imm=0x0880
        sig, refs = C.analyse([jal_word, lui_word])
        self.assertEqual(sig[0], 3 << 26)
        self.assertEqual(sig[1], (0x0F << 26) | (8 << 16))
        self.assertEqual(refs, [("call", 0, 0x00040000), ("hi", 1, 0x08800000)])


if __name__ == "__main__":
    unittest.main()
