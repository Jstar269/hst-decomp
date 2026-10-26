#!/usr/bin/env python3
"""Find non-relocatable numeric addresses in one HSTMATCH source with Clang's AST.

The stable import surface is ``findings(path, lang)``. It returns dictionaries with exactly
``kind``, ``line`` and ``column``; it never returns source text or address values. Callers may
override the checkout root, host Clang, or header overlay with keyword arguments for isolated
synthetic fixtures. The AST is built for x86_64 Windows because the expression and cast kinds
are language properties, while the pointer width and the same freestanding header overlay used
by :mod:`hstport` are held fixed.

``integral-to-pointer`` marks every non-null integer constant expression cast to a pointer,
including folded arithmetic and enumerators. ``module-address-conversion`` marks a non-constant
integer-to-pointer conversion containing a constant within the source module's mapped range.
``module-address-pointer-compare`` marks a pointer comparison against a module-range integer
constant when Clang has not already represented that integer as an IntegralToPointer cast.
"""
from __future__ import annotations

import argparse
import concurrent.futures
import json
import os
import re
import subprocess
import sys
from pathlib import Path
from typing import Callable, Iterable

PROJECT_ROOT = Path(__file__).resolve().parent.parent
TARGET = "x86_64-pc-windows-msvc"
CXX_STANDARD = "c++17"
DEFAULT_NDK = Path(os.environ.get("LOCALAPPDATA", r"C:\Users\Default\AppData\Local")) / "Android" / "Sdk" / "ndk" / "30.0.16248370"
NDK_CLANG_RELATIVE = Path("toolchains") / "llvm" / "prebuilt" / "windows-x86_64" / "bin" / "clang.exe"
DEFAULT_HOST_CLANG = Path(r"C:\Program Files\LLVM\bin\clang.exe")
HEADER_RE = re.compile(r"/\*\s*HSTMATCH\s+([^*]+?)\s*\*/")
FIELD_RE = re.compile(r"([A-Za-z_][A-Za-z_0-9]*)=([^\s]+)")
POINTER_COMPARE_OPS = frozenset(("==", "!=", "<", "<=", ">", ">="))
CAST_KINDS = frozenset(("CStyleCastExpr", "CXXFunctionalCastExpr", "CXXReinterpretCastExpr", "ImplicitCastExpr"))


class HstAddrError(RuntimeError):
    """The requested source could not be analyzed into a Clang AST."""


def _expand_path(value: str | Path) -> Path:
    return Path(os.path.expanduser(os.path.expandvars(str(value)))).resolve()


def _find_root(path: Path, root: Path | None) -> Path:
    if root is not None:
        return root.resolve()
    resolved = path.resolve()
    if PROJECT_ROOT in resolved.parents:
        return PROJECT_ROOT
    for parent in resolved.parents:
        if (parent / "include").is_dir() and (parent / "data").is_dir():
            return parent
    return PROJECT_ROOT


def _read_header(path: Path) -> dict[str, str]:
    head = path.read_text(encoding="utf-8", errors="replace")[:2048]
    match = HEADER_RE.search(head)
    fields = dict(FIELD_RE.findall(match.group(1))) if match else {}
    return fields


def _language_args(lang: str) -> list[str]:
    if lang == "c99":
        return ["-x", "c", "-std=c99"]
    if lang == "c++":
        return ["-x", "c++", f"-std={CXX_STANDARD}"]
    raise ValueError(f"unsupported source language: {lang!r}")


def _configured_clang(root: Path) -> Path:
    config_path = root / "hst-config.json"
    config: dict = {}
    if config_path.is_file():
        try:
            config = json.loads(config_path.read_text(encoding="utf-8"))
        except (OSError, json.JSONDecodeError):
            config = {}
    host_value = os.environ.get("HST_HOST_CLANG") or config.get("host_clang") or DEFAULT_HOST_CLANG
    host = _expand_path(host_value)
    if host.is_file():
        return host
    ndk_value = os.environ.get("HST_ANDROID_NDK") or config.get("android_ndk") or DEFAULT_NDK
    ndk = _expand_path(ndk_value)
    ndk_clang = ndk if ndk.is_file() else ndk / NDK_CLANG_RELATIVE
    if ndk_clang.is_file():
        return ndk_clang
    raise FileNotFoundError("neither the configured Windows Clang nor Android NDK Clang exists")


def _load_ranges(root: Path, module: str, path: Path) -> list[tuple[int, int]]:
    modules_path = root / "data" / "modules.json"
    if modules_path.is_file():
        try:
            data = json.loads(modules_path.read_text(encoding="utf-8"))
            entry = next((item for item in data.get("modules", ()) if item.get("name") == module), None)
            if entry is not None:
                ranges = []
                for segment in entry.get("load_segments", ()):
                    start = segment.get("start")
                    end = segment.get("memory_end", segment.get("file_end"))
                    if start is not None and end is not None:
                        lo = int(start, 0) if isinstance(start, str) else int(start)
                        hi = int(end, 0) if isinstance(end, str) else int(end)
                        if hi > lo:
                            ranges.append((lo, hi))
                if ranges:
                    return ranges
        except (OSError, ValueError, json.JSONDecodeError):
            pass

    function_path = root / "data" / f"functions-{module}.txt"
    if function_path.is_file():
        ranges = []
        for line in function_path.read_text(encoding="utf-8", errors="replace").splitlines():
            fields = line.split()
            if len(fields) != 2 or fields[0].startswith("#"):
                continue
            try:
                lo, hi = (int(value, 16) for value in fields)
            except ValueError:
                continue
            if hi > lo:
                ranges.append((lo, hi))
        if ranges:
            return [(min(lo for lo, _ in ranges), max(hi for _, hi in ranges))]

    header = _read_header(path)
    try:
        lo, hi = int(header["start"], 0), int(header["end"], 0)
    except (KeyError, ValueError):
        return []
    return [(lo, hi)] if hi > lo else []


def _source_point(node: dict, source_path: Path, source_bytes: bytes) -> tuple[int, int] | None:
    raw = node.get("range", {}).get("begin") or node.get("loc") or {}
    if not isinstance(raw, dict):
        return None
    # A macro's expansion point belongs to the source using it; its spelling point may be
    # in an included header. Header declarations are excluded from the per-source census.
    while isinstance(raw.get("expansionLoc"), dict):
        raw = raw["expansionLoc"]
    if raw.get("includedFrom"):
        return None
    named_file = raw.get("file")
    if named_file:
        try:
            if _expand_path(named_file) != source_path.resolve():
                return None
        except OSError:
            return None
    offset = raw.get("offset")
    if isinstance(offset, int) and 0 <= offset <= len(source_bytes):
        line = source_bytes.count(b"\n", 0, offset) + 1
        previous_newline = source_bytes.rfind(b"\n", 0, offset)
        column = offset - previous_newline
        return line, column
    line, column = raw.get("line"), raw.get("col")
    if isinstance(line, int) and isinstance(column, int):
        return line, column
    return None


def _field_integer(node: dict) -> int | None:
    value = node.get("value")
    if not isinstance(value, (str, int)):
        return None
    try:
        return int(value, 0) if isinstance(value, str) else value
    except ValueError:
        try:
            return int(value, 10)
        except ValueError:
            return None


def _integer_value(node: dict, enum_values: dict[str, int], constexpr_values: dict[str, int],
                   active: frozenset[str] = frozenset()) -> int | None:
    direct = _field_integer(node)
    if direct is not None and node.get("kind") in (
        "ConstantExpr", "IntegerLiteral", "CharacterLiteral", "CXXBoolLiteralExpr",
        "EnumConstantDecl", "ConstantArrayType",
    ):
        return direct
    kind = node.get("kind")
    if kind == "DeclRefExpr":
        reference = node.get("referencedDecl", {})
        ref_id = reference.get("id")
        ref_kind = reference.get("kind")
        if ref_id in active:
            return None
        if ref_kind == "EnumConstantDecl":
            return enum_values.get(ref_id)
        if ref_kind == "VarDecl" and reference.get("constexpr"):
            return constexpr_values.get(ref_id)
        return None

    children = [child for child in node.get("inner", ()) if isinstance(child, dict)]
    if kind in ("ParenExpr", "ImplicitCastExpr", "CStyleCastExpr", "CXXStaticCastExpr",
                "CXXConstCastExpr", "CXXFunctionalCastExpr", "ExprWithCleanups", "FullExpr",
                "ConstantExpr", "MaterializeTemporaryExpr", "CXXBindTemporaryExpr"):
        if kind == "ConstantExpr" and direct is not None:
            return direct
        return _integer_value(children[-1], enum_values, constexpr_values, active) if children else None
    if kind == "UnaryOperator" and children:
        value = _integer_value(children[0], enum_values, constexpr_values, active)
        op = node.get("opcode")
        if value is None:
            return None
        if op == "+":
            return value
        if op == "-":
            return -value
        if op == "~":
            return ~value
        if op == "!":
            return int(not value)
        return None
    if kind == "BinaryOperator" and len(children) >= 2:
        left = _integer_value(children[0], enum_values, constexpr_values, active)
        right = _integer_value(children[1], enum_values, constexpr_values, active)
        if left is None or right is None:
            return None
        op = node.get("opcode")
        operations = {
            "+": lambda: left + right,
            "-": lambda: left - right,
            "*": lambda: left * right,
            "/": lambda: int(left / right),
            "%": lambda: left % right,
            "<<": lambda: left << right,
            ">>": lambda: left >> right,
            "|": lambda: left | right,
            "&": lambda: left & right,
            "^": lambda: left ^ right,
            "==": lambda: int(left == right),
            "!=": lambda: int(left != right),
            "<": lambda: int(left < right),
            "<=": lambda: int(left <= right),
            ">": lambda: int(left > right),
            ">=": lambda: int(left >= right),
            "&&": lambda: int(bool(left) and bool(right)),
            "||": lambda: int(bool(left) or bool(right)),
        }
        operation = operations.get(op)
        if operation is None:
            return None
        try:
            return operation()
        except (ArithmeticError, OverflowError, ValueError):
            return None
    if kind == "ConditionalOperator" and len(children) >= 3:
        condition = _integer_value(children[0], enum_values, constexpr_values, active)
        if condition is None:
            return None
        return _integer_value(children[1] if condition else children[2], enum_values, constexpr_values, active)
    return direct


def _is_pointer(node: dict) -> bool:
    type_info = node.get("type", {})
    qual_type = type_info.get("desugaredQualType") or type_info.get("qualType") or ""
    return "*" in qual_type


def _in_ranges(value: int, ranges: Iterable[tuple[int, int]]) -> bool:
    return any(start <= value < end for start, end in ranges)


def _constant_nodes(node: dict, enum_values: dict[str, int], constexpr_values: dict[str, int]):
    value = _integer_value(node, enum_values, constexpr_values)
    if value is not None:
        yield node, value
        return
    for child in _walk(node):
        if child is node:
            continue
        value = _integer_value(child, enum_values, constexpr_values)
        if value is not None:
            yield child, value


def _pointer_related(node: dict) -> bool:
    return _is_pointer(node) or any(
        item.get("castKind") in ("IntegralToPointer", "PointerToIntegral") for item in _walk(node)
    )


def _ast_command(source: Path, lang: str, root: Path, overlay: Path, compiler: Path) -> list[str]:
    return [
        str(compiler), f"--target={TARGET}", *_language_args(lang), "-ffreestanding", "-nostdinc",
        "-fno-color-diagnostics", "-fdiagnostics-show-option",
        "-I", str(overlay.resolve()), "-I", str((root / "include").resolve()),
        "-I", str((root / "src").resolve()),
        "-Xclang", "-ast-dump=json", "-fsyntax-only", str(source.resolve()),
    ]


def _run_clang_ast(source: Path, lang: str, checkout: Path, host_overlay: Path, clang: Path) -> dict:
    command = _ast_command(source, lang, checkout, host_overlay, clang)
    try:
        proc = subprocess.run(command, cwd=checkout, capture_output=True, text=True, encoding="utf-8",
                              errors="replace", stdin=subprocess.DEVNULL, check=False)
    except OSError as exc:
        raise HstAddrError("could not launch Clang AST analysis") from exc
    try:
        return json.loads(proc.stdout)
    except json.JSONDecodeError as exc:
        # Never expose Clang's diagnostic text here: it can contain source excerpts.
        raise HstAddrError(f"Clang did not produce an AST for {source.name}") from exc


def _collect_ast_nodes(ast: dict) -> list[dict]:
    nodes: list[dict] = []

    def collect(node: dict) -> None:
        nodes.append(node)
        for child in node.get("inner", ()):
            if isinstance(child, dict):
                collect(child)

    collect(ast)
    return nodes


def _extract_decl_values(nodes: list[dict]) -> tuple[dict[str, int], dict[str, int]]:
    enum_values: dict[str, int] = {}
    constexpr_values: dict[str, int] = {}
    for node in nodes:
        kind = node.get("kind")
        node_id = node.get("id")
        if kind not in ("EnumConstantDecl", "VarDecl") or not node_id:
            continue
        if kind == "VarDecl" and not node.get("constexpr"):
            continue
        children = [child for child in node.get("inner", ()) if isinstance(child, dict)]
        value = next((_integer_value(child, enum_values, constexpr_values)
                      for child in reversed(children)
                      if _integer_value(child, enum_values, constexpr_values) is not None), None)
        if value is not None:
            if kind == "EnumConstantDecl":
                enum_values[node_id] = value
            else:
                constexpr_values[node_id] = value
    return enum_values, constexpr_values


def _check_cast_node(node: dict, enum_values: dict[str, int], constexpr_values: dict[str, int],
                     ranges: list[tuple[int, int]], add: Callable[[str, dict], None]) -> None:
    cast_kind = node.get("castKind")
    node_kind = node.get("kind")
    children = [child for child in node.get("inner", ()) if isinstance(child, dict)]
    if cast_kind == "IntegralToPointer" and node_kind in CAST_KINDS and children:
        operand = children[-1]
        value = _integer_value(operand, enum_values, constexpr_values)
        if value is not None:
            if value != 0:
                add("integral-to-pointer", node)
        elif ranges:
            # An address constant buried in a non-constant expression is still a fixed
            # module address. Keep this separate from the general ICE cast finding.
            for child in [operand, *[n for n in _walk(operand) if n is not operand]]:
                child_value = _integer_value(child, enum_values, constexpr_values)
                if child_value is not None and child_value != 0 and _in_ranges(child_value, ranges):
                    add("module-address-conversion", child)


def _check_compare_node(node: dict, enum_values: dict[str, int], constexpr_values: dict[str, int],
                        ranges: list[tuple[int, int]], add: Callable[[str, dict], None]) -> None:
    node_kind = node.get("kind")
    children = [child for child in node.get("inner", ()) if isinstance(child, dict)]
    if node_kind == "BinaryOperator" and node.get("opcode") in POINTER_COMPARE_OPS and len(children) >= 2:
        left, right = children[0], children[1]
        if _is_pointer(left) and not _is_pointer(right):
            integer_side = right
        elif _is_pointer(right) and not _is_pointer(left):
            integer_side = left
        else:
            integer_side = None
        if integer_side is not None:
            if any(child.get("castKind") == "IntegralToPointer" for child in _walk(integer_side)):
                return
            for constant_node, value in _constant_nodes(integer_side, enum_values, constexpr_values):
                if value != 0 and _in_ranges(value, ranges):
                    add("module-address-pointer-compare", constant_node)
            return

        # A source can first convert a pointer to uintptr_t and then compare it with a
        # numeric module address. In that case the binary operands are both integers;
        # preserve the pointer provenance carried by the cast in the AST.
        left_related, right_related = _pointer_related(left), _pointer_related(right)
        if left_related == right_related:
            return
        if any(child.get("castKind") == "IntegralToPointer" for child in _walk(left)) or any(
            child.get("castKind") == "IntegralToPointer" for child in _walk(right)
        ):
            return
        integer_side = right if left_related else left
        for constant_node, value in _constant_nodes(integer_side, enum_values, constexpr_values):
            if value != 0 and _in_ranges(value, ranges):
                add("module-address-pointer-compare", constant_node)



def findings(path: str | Path, lang: str, *, root: str | Path | None = None,
             overlay: str | Path | None = None, compiler: str | Path | None = None) -> list[dict]:
    """Return numeric-address findings for path without retaining source text.

    lang is c99 or c++. Optional keyword arguments select the checkout,
    host header overlay, and Clang executable; the two-argument form uses this checkout's
    configuration and is stable for external census consumers.
    """
    source = Path(path).resolve()
    checkout = _find_root(source, Path(root) if root is not None else None)
    host_overlay = _expand_path(overlay or (checkout / "port" / "include"))
    if not host_overlay.is_dir():
        raise FileNotFoundError(f"Clang host header overlay not found: {host_overlay}")
    clang = _expand_path(compiler) if compiler is not None else _configured_clang(checkout)
    if not clang.is_file():
        raise FileNotFoundError(f"Clang executable not found: {clang}")
    source_bytes = source.read_bytes()
    header = _read_header(source)
    module = header.get("module", "")
    ranges = _load_ranges(checkout, module, source) if module else []
    ast = _run_clang_ast(source, lang, checkout, host_overlay, clang)

    nodes = _collect_ast_nodes(ast)
    enum_values, constexpr_values = _extract_decl_values(nodes)

    found: set[tuple[str, int, int]] = set()

    def add(kind: str, node: dict) -> None:
        point = _source_point(node, source, source_bytes)
        if point is not None:
            found.add((kind, point[0], point[1]))

    for node in nodes:
        _check_cast_node(node, enum_values, constexpr_values, ranges, add)
        _check_compare_node(node, enum_values, constexpr_values, ranges, add)

    return [
        {"kind": kind, "line": line, "column": column}
        for kind, line, column in sorted(found, key=lambda item: (item[1], item[2], item[0]))
    ]


def _walk(node: dict):
    yield node
    for child in node.get("inner", ()):
        if isinstance(child, dict):
            yield from _walk(child)


def _language_for(path: Path, override: str | None) -> str:
    if override:
        return override
    lang = _read_header(path).get("lang")
    if lang in ("c99", "c++"):
        return lang
    if path.suffix.lower() == ".cpp":
        return "c++"
    return "c99"


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("paths", nargs="+", type=Path, help="source paths to analyze")
    parser.add_argument("--root", type=Path, help="checkout root (default: discovered from the source path)")
    parser.add_argument("--overlay", type=Path, help="host header overlay (default: ROOT/port/include)")
    parser.add_argument("--clang", type=Path, help="Clang executable (default: configured Windows Clang)")
    parser.add_argument("--lang", choices=("c99", "c++"), help="override language for every input path")
    parser.add_argument("--parallel", type=int, default=4, help="maximum concurrent Clang AST processes")
    parser.add_argument("--json", action="store_true", help="emit path and findings objects as JSON")
    args = parser.parse_args(argv)
    if args.parallel < 1:
        parser.error("--parallel must be at least 1")
    root = args.root.resolve() if args.root else None

    def analyze(path: Path) -> tuple[str, list[dict]]:
        lang = _language_for(path, args.lang)
        result = findings(path, lang, root=root, overlay=args.overlay, compiler=args.clang)
        return str(path), result

    try:
        with concurrent.futures.ThreadPoolExecutor(max_workers=args.parallel) as executor:
            results = list(executor.map(analyze, args.paths))
    except (OSError, ValueError, HstAddrError) as exc:
        print(f"hstaddr: {exc}", file=sys.stderr)
        return 2
    payload = [{"path": path, "findings": result} for path, result in results]
    if args.json:
        print(json.dumps(payload, indent=2, sort_keys=True))
    else:
        for item in payload:
            if not item["findings"]:
                print(f"{item['path']}: no numeric-address findings")
            for finding in item["findings"]:
                print(f"{item['path']}:{finding['line']}:{finding['column']}: {finding['kind']}")
    return 1 if any(item["findings"] for item in payload) else 0


if __name__ == "__main__":
    raise SystemExit(main())
