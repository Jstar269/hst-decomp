#!/usr/bin/env python3
"""Synthetic-only tests for the AST numeric-address detector."""
from __future__ import annotations

import json
import sys
import tempfile
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import hstaddr as A
import hstport as P

NDK_CLANG = P.DEFAULT_NDK / P.NDK_CLANG_RELATIVE
CLANG = P.DEFAULT_HOST_CLANG if P.DEFAULT_HOST_CLANG.is_file() else NDK_CLANG


def make_root(tmp: str) -> Path:
    root = Path(tmp)
    (root / "include").mkdir()
    (root / "data").mkdir()
    (root / "data" / "modules.json").write_text(
        '{"modules":[{"name":"EBOOT.BIN","load_segments":[{"start":4096,"memory_end":8192}]}]}\n',
        encoding="utf-8")
    (root / "data" / "functions-EBOOT.BIN.txt").write_text("00001000 00002000\n", encoding="utf-8")
    return root


def write_source(root: Path, name: str, code: str, lang: str = "c99") -> Path:
    path = root / "src" / "eboot" / name
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(
        f"/* HSTMATCH module=EBOOT.BIN start=0x00001000 end=0x00002000 symbol=synthetic lang={lang} */\n"
        f"{code}\n",
        encoding="utf-8",
    )
    return path


@unittest.skipUnless(CLANG.is_file(), f"Clang not found: {CLANG}")
class NumericAddressTests(unittest.TestCase):
    def detect(self, root: Path, path: Path, lang: str = "c99") -> list[dict]:
        return A.findings(path, lang, root=root, overlay=P.DEFAULT_OVERLAY, compiler=CLANG)

    def test_literal_folded_and_enum_values_are_ast_findings(self) -> None:
        with tempfile.TemporaryDirectory() as tmp:
            root = make_root(tmp)
            path = write_source(root, "constants.c",
                                "enum { MODULE_ADDRESS = 0x08800000 };\n"
                                "int *literal(void) { return (int *)0x08800000; }\n"
                                "int *folded(void) { return (int *)(0x08000000 + 0x10); }\n"
                                "int *enumerated(void) { return (int *)MODULE_ADDRESS; }\n"
                                "int *implicit(void) { return 0x08800000; }")
            result = self.detect(root, path)
            self.assertEqual([item["kind"] for item in result], [
                "integral-to-pointer", "integral-to-pointer", "integral-to-pointer", "integral-to-pointer",
            ])
            self.assertEqual([item["line"] for item in result], [3, 4, 5, 6])
            self.assertTrue(all(set(item) == {"kind", "line", "column"} for item in result))
            self.assertNotIn("0x08800000", json.dumps(result))
            self.assertNotIn("return", json.dumps(result))

    def test_null_pointer_constants_are_excluded(self) -> None:
        with tempfile.TemporaryDirectory() as tmp:
            root = make_root(tmp)
            path = write_source(root, "nulls.c",
                                "#include <stddef.h>\n"
                                "int *zero(void) { return (int *)0; }\n"
                                "void *macro_null(void) { return NULL; }")
            self.assertEqual(self.detect(root, path), [])

    def test_pointer_sized_integer_variable_is_not_an_integer_constant_expression(self) -> None:
        with tempfile.TemporaryDirectory() as tmp:
            root = make_root(tmp)
            path = write_source(root, "variable.c",
                                "#include <stdint.h>\n"
                                "void *from_uintptr(uintptr_t value) { return (void *)value; }")
            self.assertEqual(self.detect(root, path), [])

    def test_module_address_compared_with_pointer_integer_representation_is_reported(self) -> None:
        with tempfile.TemporaryDirectory() as tmp:
            root = make_root(tmp)
            path = write_source(root, "compare.c",
                                "#include <stdint.h>\n"
                                "int matches(void *pointer) { return (uintptr_t)pointer == 0x1010; }")
            result = self.detect(root, path)
            self.assertEqual(len(result), 1)
            self.assertEqual(result[0]["kind"], "module-address-pointer-compare")
            self.assertEqual(result[0]["line"], 3)

    def test_module_address_constant_inside_nonconstant_pointer_conversion_is_reported(self) -> None:
        with tempfile.TemporaryDirectory() as tmp:
            root = make_root(tmp)
            path = write_source(root, "conversion.c",
                                "#include <stdint.h>\n"
                                "void *from_base(uintptr_t base) { return (void *)(base + 0x1010); }")
            result = self.detect(root, path)
            self.assertEqual(len(result), 1)
            self.assertEqual(result[0]["kind"], "module-address-conversion")

    def test_cpp_reinterpret_cast_of_literal_is_reported_without_source_text(self) -> None:
        with tempfile.TemporaryDirectory() as tmp:
            root = make_root(tmp)
            path = write_source(root, "cast.cpp",
                                "int *literal() { return reinterpret_cast<int *>(0x08800000); }", "c++")
            result = self.detect(root, path, "c++")
            self.assertEqual(len(result), 1)
            self.assertEqual(result[0]["kind"], "integral-to-pointer")
            self.assertEqual(set(result[0]), {"kind", "line", "column"})
            self.assertNotIn("reinterpret_cast", json.dumps(result))
            self.assertNotIn("0x08800000", json.dumps(result))

    def test_cpp_functional_pointer_cast_of_literal_is_reported(self) -> None:
        with tempfile.TemporaryDirectory() as tmp:
            root = make_root(tmp)
            path = write_source(root, "functional.cpp",
                                "using address_pointer = int *;\n"
                                "address_pointer literal() { return address_pointer(0x08800000); }", "c++")
            result = self.detect(root, path, "c++")
            self.assertEqual(len(result), 1)
            self.assertEqual(result[0]["kind"], "integral-to-pointer")


if __name__ == "__main__":
    unittest.main()
