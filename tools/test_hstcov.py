#!/usr/bin/env python3
"""Synthetic tests for hstcov.py (exact-match coverage measurement)."""
from __future__ import annotations

import io
import json
import sys
import tempfile
import unittest
from pathlib import Path
from unittest.mock import MagicMock, patch

sys.path.insert(0, str(Path(__file__).resolve().parent))
import hstcov as C
import hstmatch as M


class CoverageTests(unittest.TestCase):
    def setUp(self) -> None:
        self.tmp_dir = tempfile.TemporaryDirectory()
        self.root = Path(self.tmp_dir.name)

        # Setup directory structure for mock ROOT
        (self.root / "src").mkdir(parents=True, exist_ok=True)

        # Mock campaign ledger JSON
        self.ledger_data = {
            "modules": [
                {
                    "name": "EBOOT.BIN",
                    "functions": [
                        {"name": "fn1", "start": 0x1000, "end": 0x1020, "boundary_status": "reviewed"},
                        {"name": "fn2", "start": 0x1020, "end": 0x1060, "boundary_status": "unreviewed"},
                        {"name": "fn3", "start": 0x1060, "end": 0x1100, "boundary_status": "reviewed"}
                    ]
                },
                {
                    "name": "MODULE2.PRX",
                    "functions": [
                        {"name": "m2_fn1", "start": 0x2000, "end": 0x2050, "boundary_status": "reviewed"}
                    ]
                },
                {
                    "name": "EMPTY.PRX",
                    "functions": []
                },
                {
                    "name": "ZERO_BYTE.PRX",
                    "functions": [
                        {"name": "zb_fn1", "start": 0x3000, "end": 0x3000, "boundary_status": "unreviewed"}
                    ]
                }
            ]
        }

        self.mock_campaign = self.root / "campaign"
        (self.mock_campaign / "ledger").mkdir(parents=True, exist_ok=True)
        (self.mock_campaign / "ledger" / "campaign.json").write_text(json.dumps(self.ledger_data), encoding="utf-8-sig")

        # CAMPAIGN is a lazy PEP 562 attribute of hstmatch; put back exactly what was there.
        had = "CAMPAIGN" in vars(M)
        old = vars(M).get("CAMPAIGN")
        M.CAMPAIGN = self.mock_campaign
        self.addCleanup(lambda: setattr(M, "CAMPAIGN", old) if had else vars(M).pop("CAMPAIGN", None))

    def tearDown(self) -> None:
        self.tmp_dir.cleanup()

    def create_source(self, rel_path: str, module: str, start: int, end: int, symbol: str = "dummy_sym", cc: str = "mwcc219") -> Path:
        src_file = self.root / "src" / rel_path
        src_file.parent.mkdir(parents=True, exist_ok=True)
        content = (
            f"/* HSTMATCH module={module} start={hex(start)} end={hex(end)} symbol={symbol} cc={cc} */\n"
            f"void dummy(void) {{}}\n"
        )
        src_file.write_text(content, encoding="utf-8")
        return src_file

    def test_presence_based_coverage_single_and_multi_spans(self) -> None:
        # Create sources:
        # 1. fn1 in EBOOT.BIN (exact start match 0x1000, length 0x20=32 B)
        self.create_source("eboot/fn1.c", "EBOOT.BIN", 0x1000, 0x1020, symbol="fn1", cc="mwcc219-v1")
        # 2. multi-function span covering fn2 (0x1020-0x1060, len 0x40=64 B) and fn3 (0x1060-0x1100, len 0xa0=160 B)
        self.create_source("eboot/fn2_3.c", "EBOOT.BIN", 0x1020, 0x1100, symbol="fn2", cc="gcc-v2")

        with patch("sys.argv", ["hstcov.py"]), \
             patch.object(M, "ROOT", self.root), \
             patch("sys.stdout", new_callable=io.StringIO) as mock_stdout:
            ret = C.main()
            self.assertEqual(ret, 0)
            output = mock_stdout.getvalue()

        self.assertIn("mode: presence-based", output)
        self.assertIn("EBOOT.BIN", output)
        self.assertIn("3/3", output)          # 3 exact / 3 total functions
        self.assertIn("256/256", output)      # 256 exact / 256 code bytes (32 + 64 + 160)
        self.assertIn("100.000%", output)
        self.assertIn("boundary-reviewed 2", output)
        self.assertIn("MODULE2.PRX", output)
        self.assertIn("0/1", output)          # 0 exact / 1 total function
        self.assertIn("ALL", output)

    def test_proof_based_coverage(self) -> None:
        # Mock hstproof module and accepted_proofs()
        mock_proofs = [
            {"module": "EBOOT.BIN", "start": "0x1000", "end": "0x1020", "cc": "mwcc219-opt"},
            {"module": "MODULE2.PRX", "start": "0x2000", "end": "0x2050", "cc": "mwcc219-opt"}
        ]
        mock_hstproof = MagicMock()
        mock_hstproof.accepted_proofs.return_value = mock_proofs

        with patch("sys.argv", ["hstcov.py", "--proofs"]), \
             patch.dict("sys.modules", {"hstproof": mock_hstproof}), \
             patch.object(M, "ROOT", self.root), \
             patch("sys.stdout", new_callable=io.StringIO) as mock_stdout:
            ret = C.main()
            self.assertEqual(ret, 0)
            output = mock_stdout.getvalue()

        self.assertIn("mode: accepted ledger", output)
        # EBOOT.BIN: 1 function matched (0x1000 - 0x1020, 32 B out of 256 B) -> 12.5%
        self.assertIn("EBOOT.BIN", output)
        self.assertIn("1/3", output)
        self.assertIn("32/256", output)
        self.assertIn("12.500%", output)
        # MODULE2.PRX: 1 function matched (0x2000 - 0x2050, 80 B out of 80 B) -> 100%
        self.assertIn("MODULE2.PRX", output)
        self.assertIn("1/1", output)
        self.assertIn("80/80", output)
        self.assertIn("100.000%", output)

    def test_json_output_and_edge_cases(self) -> None:
        # Create 1 source in EBOOT.BIN
        self.create_source("eboot/fn1.c", "EBOOT.BIN", 0x1000, 0x1020, symbol="fn1", cc="mwcc219-v1")
        # ZERO_BYTE.PRX source matching its 0-byte function
        self.create_source("zb/zb.cpp", "ZERO_BYTE.PRX", 0x3000, 0x3000, symbol="zb_fn1", cc="mwcc219")

        json_out_path = self.root / "out.json"

        with patch("sys.argv", ["hstcov.py", "--json", str(json_out_path)]), \
             patch.object(M, "ROOT", self.root), \
             patch("sys.stdout", new_callable=io.StringIO):
            ret = C.main()
            self.assertEqual(ret, 0)

        self.assertTrue(json_out_path.exists())
        data = json.loads(json_out_path.read_text(encoding="utf-8"))

        # Assert JSON structure and modules
        modules_in_data = [r["module"] for r in data]
        self.assertIn("EBOOT.BIN", modules_in_data)
        self.assertIn("MODULE2.PRX", modules_in_data)
        self.assertIn("ZERO_BYTE.PRX", modules_in_data)
        self.assertNotIn("EMPTY.PRX", modules_in_data)  # empty functions list module is skipped
        self.assertIn("ALL", modules_in_data)

        eboot_row = next(r for r in data if r["module"] == "EBOOT.BIN")
        self.assertEqual(eboot_row["functions"], 3)
        self.assertEqual(eboot_row["exact"], 1)
        self.assertEqual(eboot_row["code_bytes"], 256)
        self.assertEqual(eboot_row["exact_bytes"], 32)
        self.assertEqual(eboot_row["pct_bytes"], 12.5)
        self.assertEqual(eboot_row["sources_by_cc"], {"mwcc21": 1})

        zb_row = next(r for r in data if r["module"] == "ZERO_BYTE.PRX")
        self.assertEqual(zb_row["code_bytes"], 0)
        self.assertEqual(zb_row["pct_bytes"], 0.0)


if __name__ == "__main__":
    unittest.main()
