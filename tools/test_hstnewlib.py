#!/usr/bin/env python3
import shlex
import unittest
from unittest.mock import patch, MagicMock
from pathlib import Path

import hstnewlib


class TestHstNewlib(unittest.TestCase):
    @patch("hstnewlib.wsl")
    @patch("hstnewlib.M")
    @patch("hstnewlib.hstconfig")
    def test_preprocess_file_quoting(self, mock_hstconfig, mock_M, mock_wsl):
        mock_hstconfig.wsl_path.return_value = "/path/with spaces/newlib"
        mock_M.gcc_home.return_value = "/path/with'quotes/gcc"
        mock_M.ROOT = Path("/project/root dir")
        mock_M.to_wsl.side_effect = lambda p: f"/wsl{p}"

        mock_completed = MagicMock()
        mock_completed.returncode = 0
        mock_wsl.return_value = mock_completed

        out_path = Path("/out/dir/pp.c")

        with patch.object(Path, "exists", return_value=True):
            res = hstnewlib.preprocess_file(
                ver="1.14.0; id",
                gcc="171",
                rel_dir="libc/stdio's",
                base="printf; echo injected",
                out=out_path,
            )

        self.assertTrue(res)
        mock_wsl.assert_called_once()
        cmd = mock_wsl.call_args[0][0]

        # Verify quoted paths and inputs in cmd
        self.assertIn(shlex.quote("/path/with spaces/newlib/inc-1.14.0; id"), cmd)
        self.assertIn(shlex.quote("/path/with'quotes/gcc/psp-gcc-1.3.1/bin/psp-gcc"), cmd)
        self.assertIn(shlex.quote("/path/with'quotes/gcc/psp-gcc-1.7.1/lib/gcc-lib/psp/3.3.3+allegrex-2.2.2-psp-1.7.1/"), cmd)
        self.assertIn(shlex.quote("/wsl/out/dir/pp.c"), cmd)
        self.assertIn(shlex.quote("/path/with spaces/newlib/1.14.0; id/newlib-1.14.0; id/newlib/libc/stdio's/printf; echo injected.c"), cmd)


if __name__ == "__main__":
    unittest.main()
