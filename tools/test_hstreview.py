import unittest
from pathlib import Path
import sys

sys.path.insert(0, str(Path(__file__).resolve().parent))
import hstreview
import hstmatch as M

class ReviewTests(unittest.TestCase):
    def test_load_sources_returns_expected_items(self):
        items = hstreview.load_sources()
        self.assertGreater(len(items), 0)
        first = items[0]
        self.assertIn("path", first)
        self.assertIn("module", first)
        self.assertIn("sha256", first)
        self.assertTrue(first["path"].endswith(".c") or first["path"].endswith(".cpp"))

    def test_load_sources_order_and_filtering(self):
        items = hstreview.load_sources()
        paths = [it["path"] for it in items]
        self.assertEqual(paths, sorted(paths))
        for p in paths:
            self.assertTrue(p.endswith(".c") or p.endswith(".cpp"))

if __name__ == "__main__":
    unittest.main()
