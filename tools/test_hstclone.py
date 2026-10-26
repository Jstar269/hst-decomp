#!/usr/bin/env python3
"""Unit tests for tools/hstclone.py (retargeting and on-demand file reading)."""
from __future__ import annotations

import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import hstclone as C


class MockPath:
    def __init__(self, content: str, name: str = "sample_00010000.c") -> None:
        self.content = content
        self.name = name
        self.stem = name.rsplit(".", 1)[0]
        self.suffix = "." + name.rsplit(".", 1)[1] if "." in name else ""
        self.read_count = 0

    def read_text(self, encoding: str = "utf-8") -> str:
        self.read_count += 1
        return self.content


class CloneTests(unittest.TestCase):
    def test_retarget_names_and_addresses(self) -> None:
        text = """/* HSTMATCH module=EBOOT.BIN start=0x00010000 end=0x00010010 symbol=FUN_00010000 lang=c99 */
int FUN_00010000(void) {
    return 0x00010000;
}
"""
        calls = {}
        data = {0x00020000: 0x00020000}
        out = C.retarget(text, 0x00010000, 0x00010020, 0x00010030, calls, data)
        self.assertIsNotNone(out)
        assert out is not None
        self.assertIn("start=0x00010020", out)
        self.assertIn("end=0x00010030", out)
        self.assertIn("FUN_00010020", out)

    def test_on_demand_reading_simulation(self) -> None:
        path = MockPath("/* source code */")
        by_sig = { (1, 2, 3): [0x00020000, 0x00030000] }
        e_functions = { 0x00010000: (0x00010010, ((1, 2, 3), [("call", 0, 0x100)])) }
        functions = {
            0x00020000: (0x00020010, ((1, 2, 3), [("call", 0, 0x200)])),
            0x00030000: (0x00030010, ((1, 2, 3), [("call", 0, 0x300)])),
        }
        matched_targets = set()
        same_module = True

        exemplars = { 0x00010000: path }

        # Simulate the on-demand reading loop logic from hstclone.py
        results = []
        for e_start, p in sorted(exemplars.items()):
            if e_start not in e_functions:
                continue
            e_end, (sig, e_refs) = e_functions[e_start]
            text = None
            for t_start in by_sig[sig]:
                if t_start in matched_targets or (same_module and t_start == e_start):
                    continue
                t_end, (_sig, t_refs) = functions[t_start]
                maps = C.mapping(e_refs, t_refs)
                if maps is None:
                    continue
                if text is None:
                    text = p.read_text(encoding="utf-8")
                results.append((t_start, text))

        self.assertEqual(len(results), 2)
        # Verify read_text was called exactly ONCE despite 2 matching clone targets
        self.assertEqual(path.read_count, 1)

    def test_on_demand_reading_skipped_when_no_matching_target(self) -> None:
        path = MockPath("/* source code */")
        by_sig = { (1, 2, 3): [] }  # No targets match signature
        e_functions = { 0x00010000: (0x00010010, ((1, 2, 3), [])) }
        exemplars = { 0x00010000: path }

        for e_start, p in sorted(exemplars.items()):
            if e_start not in e_functions:
                continue
            e_end, (sig, e_refs) = e_functions[e_start]
            text = None
            for t_start in by_sig[sig]:
                if text is None:
                    text = p.read_text(encoding="utf-8")

        # Verify read_text was NOT called when there are no targets
        self.assertEqual(path.read_count, 0)


if __name__ == "__main__":
    unittest.main()
