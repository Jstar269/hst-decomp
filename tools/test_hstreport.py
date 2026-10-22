#!/usr/bin/env python3
"""Tests for the objdiff report written for recomp.fyi (hstreport.py)."""
from __future__ import annotations

import json
import sys
import tempfile
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import hstreport as R

MODULES = {"A.BIN": {"functions": 10, "matched_functions": 4, "code_bytes": 1000, "matched_code_bytes": 250},
           "B.prx": {"functions": 6, "matched_functions": 3, "code_bytes": 600, "matched_code_bytes": 300}}


def fig() -> dict:
    total = {k: sum(m[k] for m in MODULES.values()) for k in ("functions", "matched_functions", "code_bytes", "matched_code_bytes")}
    return {"modules": MODULES, "total": total}


def scope() -> dict:
    return {"modules": {"A.BIN": {"image_bytes": 1500}, "B.prx": {"image_bytes": 900}}}


class ReportTests(unittest.TestCase):
    def test_schema_shape_is_objdiff_report_version_2(self) -> None:
        rep = R.build_report(fig(), scope())
        self.assertEqual(set(rep), {"measures", "units", "version", "categories"})
        self.assertEqual(rep["version"], 2)
        fields = {"fuzzy_match_percent", "total_code", "matched_code", "matched_code_percent", "total_data", "matched_data",
                  "matched_data_percent", "total_functions", "matched_functions", "matched_functions_percent",
                  "complete_code", "complete_code_percent", "complete_data", "complete_data_percent", "total_units",
                  "complete_units"}
        for m in [rep["measures"]] + [u["measures"] for u in rep["units"]] + [c["measures"] for c in rep["categories"]]:
            self.assertEqual(set(m), fields)
            for k in ("total_code", "matched_code", "total_data", "matched_data", "complete_code", "complete_data"):
                self.assertIsInstance(m[k], str)            # pbjson writes 64-bit counters as decimal strings
                self.assertTrue(m[k].isdigit())
            for k in ("total_functions", "matched_functions", "total_units", "complete_units"):
                self.assertIsInstance(m[k], int)
        self.assertEqual([u["name"] for u in rep["units"]], ["A.BIN", "B.prx"])
        self.assertEqual([c["id"] for c in rep["categories"]], ["A.BIN", "B.prx"])
        self.assertEqual(rep["units"][0]["metadata"], {"module_name": "A.BIN", "progress_categories": ["A.BIN"]})
        self.assertEqual(rep["measures"]["total_units"], 2)

    def test_totals_equal_the_progress_figures(self) -> None:
        f = fig()
        rep = R.build_report(f, scope())
        m = rep["measures"]
        t = f["total"]
        self.assertEqual(int(m["total_code"]), t["code_bytes"])
        self.assertEqual(int(m["matched_code"]), t["matched_code_bytes"])
        self.assertEqual(m["total_functions"], t["functions"])
        self.assertEqual(m["matched_functions"], t["matched_functions"])
        self.assertEqual(m["matched_code_percent"], round(100 * 550 / 1600, 3))
        for key in ("total_code", "matched_code", "total_data"):
            self.assertEqual(sum(int(u["measures"][key]) for u in rep["units"]), int(m[key]))

    def test_data_is_never_claimed(self) -> None:
        rep = R.build_report(fig(), scope())
        self.assertEqual(int(rep["measures"]["total_data"]), (1500 - 1000) + (900 - 600))
        full = {k: dict(v, matched_functions=v["functions"], matched_code_bytes=v["code_bytes"]) for k, v in MODULES.items()}
        done = R.build_report({"modules": full, "total": {}}, scope())["measures"]
        self.assertEqual(done["matched_code_percent"], 100.0)           # all code matched ...
        self.assertEqual(done["matched_data"], "0")                      # ... and still no data and nothing linked
        self.assertGreater(int(done["total_data"]), 0)
        self.assertEqual((done["complete_code"], done["complete_units"]), ("0", 0))

    def test_functions_larger_than_the_image_are_refused(self) -> None:
        with self.assertRaises(ValueError):
            R.build_report(fig(), {"modules": {"A.BIN": {"image_bytes": 10}, "B.prx": {"image_bytes": 900}}})

    def test_no_private_path_strings_and_no_function_names(self) -> None:
        text = R.render(R.build_report(fig(), scope()))
        for needle in ("\\", "C:", "/nk/", "private", "try/", "hst-config", "wip/", "src/", "accepted-ledger", "sony", "Sony"):
            self.assertNotIn(needle, text)
        self.assertNotIn("functions\": [", text)
        self.assertNotIn("sections", text)

    def test_committed_report_is_valid_and_public_safe(self) -> None:
        doc = json.loads(R.REPORT_PATH.read_text(encoding="utf-8"))
        self.assertEqual(doc["version"], 2)
        text = R.REPORT_PATH.read_text(encoding="utf-8")
        for needle in ("\\", "C:", "/nk/", "private", "try/", "hst-config"):
            self.assertNotIn(needle, text)
        m = doc["measures"]
        self.assertLessEqual(int(m["matched_code"]), int(m["total_code"]))

    def test_differences_detect_a_stale_file(self) -> None:
        with tempfile.TemporaryDirectory() as tmp:
            path = Path(tmp) / "objdiff-report.json"
            self.assertTrue(R.differences(fig(), scope(), path))        # missing
            R.write(fig(), scope(), path)
            self.assertEqual(R.differences(fig(), scope(), path), [])
            newer = fig()
            newer["modules"] = {k: dict(v, matched_functions=v["matched_functions"] + 1,
                                        matched_code_bytes=v["matched_code_bytes"] + 8) for k, v in MODULES.items()}
            diffs = R.differences(newer, scope(), path)
            self.assertTrue(any("matched_code" in d for d in diffs))
            path.write_text("{not json", encoding="utf-8")
            self.assertTrue(any("not valid JSON" in d for d in R.differences(fig(), scope(), path)))


if __name__ == "__main__":
    unittest.main()
