#!/usr/bin/env python3
"""Tests for permuter helper utilities and JSON caching (hstperm.py)."""
from __future__ import annotations

import json
import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import hstperm as P


class HstPermTests(unittest.TestCase):
    def test_parse_json_caching_and_correctness(self) -> None:
        P._parse_json.cache_clear()
        data = [{"module": "EBOOT.BIN", "start": "0x1000", "status": "MISMATCH", "source": "src/foo.c"}]
        raw = json.dumps(data)

        res1 = P._parse_json(raw)
        self.assertEqual(res1, data)

        res2 = P._parse_json(raw)
        self.assertEqual(res2, data)

        info = P._parse_json.cache_info()
        self.assertEqual(info.hits, 1)
        self.assertEqual(info.misses, 1)

    def test_body_bounds(self) -> None:
        lines = [
            "int foo(int x)",
            "{",
            "    return x + 1;",
            "}",
        ]
        start, end = P.body_bounds(lines)
        self.assertEqual(start, 2)
        self.assertEqual(end, 4)

    def test_split_top(self) -> None:
        parts = P.split_top("a + b + (c + d)", "+")
        self.assertEqual(parts, ["a", "b", "(c + d)"])

    def test_negate(self) -> None:
        self.assertEqual(P.negate("a < b"), "a >= b")
        self.assertEqual(P.negate("x == y"), "x != y")

    def test_score(self) -> None:
        self.assertEqual(P.score("EXACT", ""), 0)
        self.assertEqual(P.score("MISMATCH", "10/10 words; 3 differ"), 3)


if __name__ == "__main__":
    unittest.main()
