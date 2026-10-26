#!/usr/bin/env python3
"""Tests for hstconfig.py."""
from __future__ import annotations

import shlex
import sys
import unittest
from pathlib import Path
from unittest.mock import MagicMock, patch

sys.path.insert(0, str(Path(__file__).resolve().parent))
import hstconfig


class WSLTests(unittest.TestCase):
    @patch("hstconfig.subprocess.run")
    def test_wsl_exists_normal_path(self, mock_run: MagicMock) -> None:
        mock_run.return_value.returncode = 0
        path = "/home/user/test_file.txt"
        self.assertTrue(hstconfig._wsl_exists(path))
        mock_run.assert_called_once_with(
            ["wsl.exe", "-e", "sh", "-c", f"test -e {shlex.quote(path)}"],
            capture_output=True,
        )

    @patch("hstconfig.subprocess.run")
    def test_wsl_exists_nonexistent_path(self, mock_run: MagicMock) -> None:
        mock_run.return_value.returncode = 1
        path = "/home/user/nonexistent.txt"
        self.assertFalse(hstconfig._wsl_exists(path))

    @patch("hstconfig.subprocess.run")
    def test_wsl_exists_escapes_command_injection(self, mock_run: MagicMock) -> None:
        mock_run.return_value.returncode = 1
        payloads = [
            'file.txt"; echo injected; echo "',
            "file.txt'; echo injected; echo '",
            "file.txt $(id)",
            "file.txt uid=1001(jules) gid=1001(jules) groups=1001(jules),27(sudo),103(docker)",
            "file.txt | cat /etc/passwd",
            "file.txt && echo injected",
            'file.txt\necho injected',
        ]
        for payload in payloads:
            mock_run.reset_mock()
            mock_run.return_value.returncode = 0
            res = hstconfig._wsl_exists(payload)
            self.assertTrue(res)
            mock_run.assert_called_once_with(
                ["wsl.exe", "-e", "sh", "-c", f"test -e {shlex.quote(payload)}"],
                capture_output=True,
            )
            # Verify the command argument passed to sh -c contains properly quoted payload
            cmd = mock_run.call_args[0][0][4]
            self.assertEqual(cmd, f"test -e {shlex.quote(payload)}")


if __name__ == "__main__":
    unittest.main()
