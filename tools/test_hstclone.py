import unittest
from pathlib import Path
from collections import defaultdict
import sys

sys.path.insert(0, str(Path(__file__).resolve().parent))
import hstclone as C
import hstmatch as M


class TestHstClone(unittest.TestCase):
    def test_words(self):
        data = b"\x01\x02\x03\x04\x05\x06\x07\x08"
        self.assertEqual(C.words(data), [0x04030201, 0x08070605])

    def test_map_value(self):
        e_start = 0x00010000
        t_start = 0x00020000
        calls = {0x00010100: 0x00020100}
        data = {0x00010200: 0x00020200}

        # Start address retargeting
        self.assertEqual(C.map_value("FUN", 0x00010000, e_start, t_start, calls, data), 0x00020000)
        # Call retargeting
        self.assertEqual(C.map_value("FUN", 0x00010100, e_start, t_start, calls, data), 0x00020100)
        # Data retargeting
        self.assertEqual(C.map_value("DAT", 0x00010200, e_start, t_start, calls, data), 0x00020200)
        # Unmapped unknown address returns None
        self.assertIsNone(C.map_value("OTHER", 0x00050000, e_start, t_start, calls, data))

    def test_retarget_names(self):
        text = "void func_00010000(void) { call_00010100(); }"
        e_start = 0x00010000
        t_start = 0x00020000
        calls = {0x00010100: 0x00020100}
        data = {}

        res = C.retarget_names(text, e_start, t_start, calls, data)
        self.assertEqual(res, "void func_00020000(void) { call_00020100(); }")

    def test_sources_covered_mapping(self):
        # Verify that set(sources[module]) returns expected start addresses
        sources = defaultdict(dict)
        sources["EBOOT.BIN"][0x00010000] = Path("src/eboot/func_00010000.c")
        sources["EBOOT.BIN"][0x00010040] = Path("src/eboot/func_00010040.c")

        covered = set(sources["EBOOT.BIN"])
        self.assertEqual(covered, {0x00010000, 0x00010040})


if __name__ == "__main__":
    unittest.main()
