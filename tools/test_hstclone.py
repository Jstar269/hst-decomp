import tempfile
import unittest
from pathlib import Path
import sys

sys.path.insert(0, str(Path(__file__).resolve().parent))
import hstclone


class TestHSTClone(unittest.TestCase):

    def test_parse_source_header(self):
        with tempfile.TemporaryDirectory() as tmpdir:
            p = Path(tmpdir) / "test.c"
            p.write_text(
                '/* HSTMATCH module=EBOOT.BIN start=0x00010000 end=0x00010020 symbol=FUN_00010000 lang=c99 */\nvoid FUN_00010000(void) {}\n',
                encoding="utf-8"
            )
            module, start, path = hstclone._parse_source_header(p)
            self.assertEqual(module, "EBOOT.BIN")
            self.assertEqual(start, 0x10000)
            self.assertEqual(path, p)


if __name__ == "__main__":
    unittest.main()
