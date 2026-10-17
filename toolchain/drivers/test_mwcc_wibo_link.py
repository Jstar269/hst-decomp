"""Synthetic tests for the campaign build driver (no retail bytes).

The end-to-end case needs WSL and the pinned components; set HST_DRIVER_COMPONENTS to a JSON file
{"wibo": path, "compiler": path, "ld": path, "objcopy": path} to run it, otherwise it is skipped.
"""
from __future__ import annotations

import contextlib
import hashlib
import io
import json
import os
import sys
import tempfile
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import mwcc_wibo_link as driver

SYNTHETIC = """/* HSTMATCH module=SYNTHETIC start=0x00001000 end=0x00001038 symbol=synthetic_add lang=c99 */
int FUN_00002000(void);
int synthetic_add(int a, int b) { return a + b + FUN_00002000(); }
"""


def sha(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


class DriverCase(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory(prefix="mwcc-driver-test-")
        self.root = Path(self.temp.name)
        self.build = self.root / "build"
        self.build.mkdir()
        self.components = {}
        for role in ("wibo", "compiler", "ld", "objcopy"):
            path = self.root / f"{role}.bin"
            path.write_bytes(f"synthetic {role}\n".encode())
            self.components[role] = (path, sha(path.read_bytes()))
        self.source = self.build / "source.c"
        self.source.write_text(SYNTHETIC, encoding="utf-8")

    def tearDown(self):
        self.temp.cleanup()

    def argv(self, **overrides):
        values = {
            "source": str(self.source), "output": str(self.build / "function.bin"), "build-dir": str(self.build),
            "start": "0x00001000", "end": "0x00001038", "symbol-map": "", "cflags": "-c -O4,p -sdatathreshold 0",
        }
        for role, (path, digest) in self.components.items():
            values[role], values[f"{role}-sha256"] = str(path), digest
        values.update(overrides)
        return [item for key, value in values.items() for item in (f"--{key}", value)]

    def run_driver(self, **overrides):
        stderr = io.StringIO()
        with contextlib.redirect_stderr(stderr), contextlib.redirect_stdout(io.StringIO()):
            code = driver.main(self.argv(**overrides))
        return code, stderr.getvalue()


class RefusalTests(DriverCase):
    def assertRefused(self, code_name, **overrides):
        code, stderr = self.run_driver(**overrides)
        self.assertEqual(code, 2)
        self.assertIn(f"BUILD_DRIVER_FAILED={code_name}", stderr)
        self.assertFalse((self.build / "function.bin").exists())

    def test_component_digest_mismatch(self):
        self.assertRefused("COMPONENT_HASH_MISMATCH", **{"ld-sha256": "0" * 64})

    def test_header_interval_must_equal_the_runner_interval(self):
        self.assertRefused("SOURCE_HEADER_INTERVAL_MISMATCH", end="0x0000103c")

    def test_experimental_flags_are_refused(self):
        self.source.write_text(SYNTHETIC.replace("lang=c99", 'lang=c99 extra="-O0"'), encoding="utf-8")
        self.assertRefused("SOURCE_HEADER_EXTRA_FLAGS_REFUSED")

    def test_missing_header_is_refused(self):
        self.source.write_text("int f(void) { return 0; }\n", encoding="utf-8")
        self.assertRefused("SOURCE_HEADER_MISSING")

    def test_language_must_follow_the_suffix(self):
        self.source.write_text(SYNTHETIC.replace("lang=c99", "lang=c++"), encoding="utf-8")
        self.assertRefused("SOURCE_LANGUAGE_UNSUPPORTED")

    def test_misaligned_interval_is_refused(self):
        self.assertRefused("FUNCTION_INTERVAL_INVALID", start="0x00001002")

    def test_symbol_map_cannot_contradict_an_address_name(self):
        symbols = self.root / "symbols.txt"
        symbols.write_text("FUN_00002000 = 0x00002004;\n", encoding="utf-8")
        self.assertRefused("SYMBOL_MAP_CONTRADICTS_NAME", **{"symbol-map": str(symbols)})

    def test_symbol_map_conflicts_and_bad_lines_are_refused(self):
        symbols = self.root / "symbols.txt"
        symbols.write_text("helper = 0x00002000;\nhelper = 0x00002004;\n", encoding="utf-8")
        self.assertRefused("SYMBOL_MAP_CONFLICT", **{"symbol-map": str(symbols)})
        symbols.write_text("helper at 0x2000\n", encoding="utf-8")
        self.assertRefused("SYMBOL_MAP_LINE_INVALID", **{"symbol-map": str(symbols)})


@unittest.skipUnless(os.environ.get("HST_DRIVER_COMPONENTS"), "needs WSL and the pinned components")
class EndToEndTests(DriverCase):
    def setUp(self):
        super().setUp()
        paths = json.loads(Path(os.environ["HST_DRIVER_COMPONENTS"]).read_text(encoding="utf-8"))
        self.components = {role: (Path(path), sha(Path(path).read_bytes())) for role, path in paths.items()}

    def test_synthetic_function_links_at_its_address(self):
        code, stderr = self.run_driver()
        self.assertEqual(code, 0, stderr)
        body = (self.build / "function.bin").read_bytes()
        self.assertEqual(len(body), 0x38)
        words = [int.from_bytes(body[i:i + 4], "little") for i in range(0, len(body), 4)]
        # The call to FUN_00002000 is resolved by the linker from the address-bearing name.
        self.assertIn(0x0C000000 | (0x2000 >> 2), words)

    def test_unresolved_symbol_is_refused(self):
        self.source.write_text(SYNTHETIC.replace("FUN_00002000", "helper"), encoding="utf-8")  # declaration and call
        code, stderr = self.run_driver()
        self.assertEqual(code, 2)
        self.assertIn("BUILD_DRIVER_FAILED=UNRESOLVED_SYMBOLS: helper", stderr)

    def test_size_mismatch_is_refused(self):
        self.source.write_text(SYNTHETIC.replace("0x00001038", "0x0000103c"), encoding="utf-8")
        code, stderr = self.run_driver(end="0x0000103c")
        self.assertEqual(code, 2)
        self.assertIn("BUILD_DRIVER_FAILED=FUNCTION_SIZE_MISMATCH", stderr)


if __name__ == "__main__":
    unittest.main(verbosity=2)
