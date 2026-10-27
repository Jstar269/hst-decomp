#!/usr/bin/env python3
"""Unit tests for tools/hstdis.py disassembling retail functions."""
from __future__ import annotations

import io
import json
import sys
import tempfile
import unittest
from pathlib import Path
from unittest import mock

sys.path.insert(0, str(Path(__file__).resolve().parent))
import hstdis as DIS


class DisasmTests(unittest.TestCase):
    def setUp(self) -> None:
        self.tmp_dir = tempfile.TemporaryDirectory()
        self.root = Path(self.tmp_dir.name)
        (self.root / "build").mkdir(parents=True, exist_ok=True)
        (self.root / "ledger").mkdir(parents=True, exist_ok=True)

        self.ledger_data = {
            "modules": [
                {
                    "name": "EBOOT.BIN",
                    "functions": [
                        {"start": 0x00010000, "end": 0x00010010},
                        {"start": 0x00010020, "end": 0x00010030},
                    ],
                },
                {
                    "name": "OVERLAY.PRX",
                    "functions": [
                        {"start": 0x00000100, "end": 0x00000120},
                    ],
                },
            ]
        }
        (self.root / "ledger" / "campaign.json").write_text(
            json.dumps(self.ledger_data), encoding="utf-8"
        )

        self.bytes_data = b"\x12\x34\x56\x78" * 16
        self.seg = {"file_offset": 0, "start": 0x00010000}

    def tearDown(self) -> None:
        self.tmp_dir.cleanup()

    def test_disassemble_single_address(self) -> None:
        def fake_disasm(bin_path: Path, start: int) -> list[str]:
            self.assertTrue(bin_path.exists())
            self.assertEqual(bin_path.read_bytes(), self.bytes_data[:0x10])
            self.assertEqual(start, 0x00010000)
            return ["00010000: nop", "00010004: jr ra"]

        with mock.patch("hstmatch.campaign_root", return_value=self.root), \
             mock.patch.object(DIS.M, "ROOT", self.root), \
             mock.patch.object(DIS.M, "module_bytes", return_value=(self.bytes_data, self.seg)) as mock_bytes, \
             mock.patch.object(DIS.D, "disasm", side_effect=fake_disasm) as mock_disasm, \
             mock.patch("sys.argv", ["hstdis.py", "0x00010000"]), \
             mock.patch("sys.stdout", new_callable=io.StringIO) as mock_stdout:

            res = DIS.main()
            self.assertEqual(res, 0)

            mock_bytes.assert_called_once_with({}, "EBOOT.BIN")
            self.assertEqual(mock_disasm.call_count, 1)

            out = mock_stdout.getvalue()
            self.assertIn("== 0x00010000..0x00010010 (16 bytes)", out)
            self.assertIn("   00010000: nop", out)
            self.assertIn("   00010004: jr ra", out)

    def test_disassemble_multiple_addresses_with_missing_address(self) -> None:
        with mock.patch("hstmatch.campaign_root", return_value=self.root), \
             mock.patch.object(DIS.M, "ROOT", self.root), \
             mock.patch.object(DIS.M, "module_bytes", return_value=(self.bytes_data, self.seg)), \
             mock.patch.object(DIS.D, "disasm", return_value=["00010020: addiu sp, sp, -8"]), \
             mock.patch("sys.argv", ["hstdis.py", "0x00010020", "0x00010050"]), \
             mock.patch("sys.stdout", new_callable=io.StringIO) as mock_stdout:

            res = DIS.main()
            self.assertEqual(res, 0)

            out = mock_stdout.getvalue()
            self.assertIn("== 0x00010020..0x00010030 (16 bytes)", out)
            self.assertIn("   00010020: addiu sp, sp, -8", out)
            self.assertIn("== 0x00010050: no ledger function starts here", out)

    def test_disassemble_custom_module(self) -> None:
        seg_overlay = {"file_offset": 0x10, "start": 0x00000100}
        with mock.patch("hstmatch.campaign_root", return_value=self.root), \
             mock.patch.object(DIS.M, "ROOT", self.root), \
             mock.patch.object(DIS.M, "module_bytes", return_value=(self.bytes_data, seg_overlay)) as mock_bytes, \
             mock.patch.object(DIS.D, "disasm", return_value=["00000100: lw a0, 0(s0)"]), \
             mock.patch("sys.argv", ["hstdis.py", "--module", "OVERLAY.PRX", "0x00000100"]), \
             mock.patch("sys.stdout", new_callable=io.StringIO) as mock_stdout:

            res = DIS.main()
            self.assertEqual(res, 0)

            mock_bytes.assert_called_once_with({}, "OVERLAY.PRX")
            out = mock_stdout.getvalue()
            self.assertIn("== 0x00000100..0x00000120 (32 bytes)", out)
            self.assertIn("   00000100: lw a0, 0(s0)", out)


if __name__ == "__main__":
    unittest.main()
