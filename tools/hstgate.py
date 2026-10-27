#!/usr/bin/env python3
"""The fake-match gate (docs/COMPLETION.md, gate 2): a source may only be C or C++ that the compiler turns into the bytes.

    python tools/hstgate.py [--all | files ...] [--show idiom|warn]

One check, shared by tools/hstmatch.py (an EXACT from a source that fails it is reported as EXACT_FAILS_GATE, never as
EXACT, so no installer accepts it), tools/hstlane.py harvest (refuses to install such a source) and tools/hstlint.py
(reports it). The refusals, each looked for in the source text with comments removed (string literals are kept: an
instruction pasted as text is the thing to find):

  asm-emit          any `asm`, `__asm__`, `__asm` or `_asm` statement, block or function that can emit instructions
  data-directive    an assembler data directive in the text: .word .byte .half .long .short .quad .incbin .ascii .space ...
                    (`{ .word = 1 }` designated initialisers are fine)
  pragma-code       a #pragma that emits code (asm, endasm, push_asm and anything with asm in its name)
  text-section      data or code steered into the code section by hand: __attribute__((section(".text..."))),
                    __declspec(section ".text...") or #pragma section/segment naming .text
  binary-include    #include of a file that is not a header (.bin .inc .s .S .o .dat ...)
  extra-header      an `extra=` key in the HSTMATCH header of a source under src/ (experimental flags never count)

Tagged but allowed:

  register-asm-binding   `register T x asm("$N")`: binds a variable to a register and emits nothing (idiom)
  empty-asm-barrier      `asm("" ...)` with an empty template: emits nothing (idiom)
  vfpu-inline-asm        project rule (owner decision 2026-10-27, the rule lbp-decomp adopted): an `asm` statement
                         whose template holds only Allegrex VFPU instructions, in a source whose HSTMATCH header says
                         `asm=vfpu` and which has a line starting `Original inline VFPU asm:` with the reason. The SDK
                         and game code wrote VFPU math as inline asm (the PSP compilers emit almost no VFPU
                         instructions themselves), so it is reconstructed as the inline asm it was. Every template
                         instruction must be a VFPU instruction: no other instruction, no label, no VFPU branch
                         (bvf/bvt: the assembler would fill or reorder the delay slot), and every VFPU load/store
                         names `offset(base)` explicitly or is a bare `%N` whose operand constraint is "m" (a
                         local, parameter or dereference the compiler addresses as offset(base); write a global's
                         access through a pointer, since a symbolic address expands to an extra lui). The only
                         directives allowed are the assembler-mode switches that emit nothing,
                         `.set push|pop|noreorder|reorder|nomacro|macro` (the SDK's VFPU blocks are wrapped in
                         `.set push; .set noreorder ... .set pop`, which is why retail keeps a `nop` after them in a
                         return's delay slot). Anything else stays asm-emit (refused).

Reported only (a warning): pragma-unknown, a #pragma that is not on the list of the compiler controls this project uses.
Every refusal and idiom is a finding with a line number; `refusals(findings)` is what the callers act on.
"""
from __future__ import annotations

import argparse
import re
import sys
from dataclasses import dataclass
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]

REFUSE, IDIOM, WARN = "refuse", "idiom", "warn"
ASM_TOKEN = re.compile(r"(?<![\w$])(?:__asm__|__asm|_asm|asm)(?![\w$])")
DIRECTIVE = re.compile(r"(?<![\w\])>])\.(?:word|byte|half|hword|short|long|quad|dword|incbin|ascii|asciiz|string|space|skip|fill|zero|"
                       r"float|double|octa|int|2byte|4byte|8byte)\b(?!\s*=)", re.I)
PRAGMA = re.compile(r"^[ \t]*#[ \t]*pragma[ \t]+([A-Za-z_][\w]*)(.*)$", re.M)
INCLUDE = re.compile(r'^[ \t]*#[ \t]*include[ \t]+[<"]([^>"]+)[>"]', re.M)
TEXT_SECTION = re.compile(r"""(?:section\s*\(\s*["']\.text|__declspec\s*\(\s*section\s*["']\.text|#\s*pragma\s+(?:section|segment)\b[^\n]*\.text)""")
HEADER_EXT = {".h", ".hpp", ".hh", ".hxx", ""}
# compiler controls this project's sources use (pragmas that change how code is generated, not what is emitted)
KNOWN_PRAGMAS = {"opt_strength_reduction", "opt_unroll_loops", "opt_common_subs", "opt_common", "opt_loop_invariants",
                 "opt_propagation", "opt_dead_code", "opt_dead_assignments", "opt_lifetimes", "opt_vectorize_loops",
                 "inline_depth", "inline_max_size", "inline_max_total_size", "inline_bottom_up", "auto_inline",
                 "dont_inline", "peephole", "scheduling", "global_optimizer", "optimization_level", "optimize_for_size",
                 "fp_contract", "pack", "once", "exceptions", "cplusplus", "ANSI_strict", "warning", "message",
                 "readonly_strings", "pool_strings", "opt_unroll_count", "inline_max_auto_size"}
CODE_PRAGMA = re.compile(r"asm", re.I)


@dataclass(frozen=True)
class Finding:
    kind: str
    severity: str        # refuse | idiom | warn
    line: int
    text: str

    def __str__(self) -> str:
        return f"{self.severity}:{self.kind}:{self.line}: {self.text.strip()[:100]}"


def strip_comments(text: str) -> str:
    """The text with /* */ and // comments blanked out (newlines kept, so line numbers survive); strings are kept."""
    out: list[str] = []
    i, n = 0, len(text)
    while i < n:
        c = text[i]
        if c == '"' or c == "'":
            j = i + 1
            while j < n and text[j] != c and text[j] != "\n":
                j += 2 if text[j] == "\\" else 1
            out.append(text[i:j + 1])
            i = j + 1
        elif text.startswith("/*", i):
            j = text.find("*/", i + 2)
            j = n if j < 0 else j + 2
            out.append("".join("\n" if ch == "\n" else " " for ch in text[i:j]))
            i = j
        elif text.startswith("//", i):
            j = text.find("\n", i)
            j = n if j < 0 else j
            out.append(" " * (j - i))
            i = j
        else:
            out.append(c)
            i += 1
    return "".join(out)


def _line_of(text: str, pos: int) -> int:
    return text.count("\n", 0, pos) + 1


def _statement_around(text: str, pos: int) -> str:
    start = max(text.rfind(";", 0, pos), text.rfind("{", 0, pos), text.rfind("}", 0, pos)) + 1
    ends = [e for e in (text.find(";", pos), text.find("{", pos)) if e >= 0]
    return text[start:(min(ends) + 1 if ends else len(text))]


# Allegrex VFPU instructions. Every VFPU arithmetic/move mnemonic begins with `v` (no other Allegrex mnemonic does);
# the rest are the COP2 loads/stores and the GPR<->VFPU moves. The VFPU branches bvf/bvt/bvfl/bvtl are left out on
# purpose: the assembler fills or reorders their delay slot itself.
VFPU_MNEMONIC = re.compile(r"^(?:v[a-z0-9]+(?:\.[spqt])?|lv\.[sq]|lvl\.q|lvr\.q|sv\.[sq]|svl\.q|svr\.q|ulv\.q|usv\.q|"
                           r"mfv|mtv|mfvc|mtvc)$", re.I)
VFPU_MEMORY = re.compile(r"^(?:lv\.[sq]|lvl\.q|lvr\.q|sv\.[sq]|svl\.q|svr\.q|ulv\.q|usv\.q)$", re.I)
# the memory operand of a VFPU load/store: an optional numeric (or %N) offset, then an explicit base register
VFPU_ADDRESS = re.compile(r"^(?:-?(?:0x[0-9a-f]+|\d+)|%\d+|%\[\w+\])?\s*\(\s*(?:%\d+|%\[\w+\]|\$\w+)\s*\)(?:\s*,\s*wb)?$",
                          re.I)
# assembler-mode switches that emit no instruction (allowed inside a VFPU template)
VFPU_SET = re.compile(r"^\.set\s+(?:push|pop|noreorder|reorder|nomacro|macro)$")
VFPU_REASON = re.compile(r"^[ \t]*(?:/\*+|\*+|//+)?[ \t]*Original inline VFPU asm:[ \t]*\w", re.M)
ASM_PREFIX = re.compile(r"^(?:__asm__|__asm|_asm|asm)\s*(?:__volatile__|volatile)?$")
BACKSLASH = chr(92)


def asm_template(code: str, pos: int) -> str | None:
    """The template of the asm statement whose keyword is at `pos`: its string literals up to the first ':' at the
    top level, one line per literal, escape sequences kept as written. None unless the statement is
    `asm [volatile] ( "..." ... )` with nothing but string literals before the operands."""
    i = code.find("(", pos)
    if i < 0 or not ASM_PREFIX.match(code[pos:i].strip()):
        return None
    out: list[str] = []
    depth, j = 0, i
    while j < len(code):
        ch = code[j]
        if ch == "(":
            depth += 1
            if depth > 1:
                return None     # a parenthesised or macro-built template
        elif ch == ")":
            depth -= 1
            if depth == 0:
                break
        elif ch == ":" and depth == 1:
            break
        elif ch == '"':
            k = j + 1
            while k < len(code) and code[k] != '"':
                step = 2 if code[k] == BACKSLASH and k + 1 < len(code) else 1
                out.append(code[k:k + step])
                k += step
            out.append("\n")
            j = k
        elif not ch.isspace():
            return None         # anything but string literals in the template
        j += 1
    return "".join(out)


ASM_OPERAND = re.compile(r'\s*(?:\[(\w+)\]\s*)?"([^"]*)"\s*\(')
MEMORY_REF = re.compile(r"^%(?:(\d+)|\[(\w+)\])$")


def asm_operands(code: str, pos: int) -> list[tuple[str | None, str]] | None:
    """(name, constraint) of every output and input operand of the asm statement whose keyword is at `pos`, in
    operand-number order, or None when they cannot be read."""
    i = code.find("(", pos)
    if i < 0:
        return None
    sections: list[str] = [""]
    depth, j = 0, i
    while j < len(code):
        ch = code[j]
        if ch == '"':
            k = j + 1
            while k < len(code) and code[k] != '"':
                k += 2 if code[k] == BACKSLASH else 1
            sections[-1] += code[j:k + 1]
            j = k + 1
            continue
        if ch == "(":
            depth += 1
            if depth == 1:
                j += 1
                continue
        elif ch == ")":
            depth -= 1
            if depth == 0:
                break
        elif ch == ":" and depth == 1:
            sections.append("")
            j += 1
            continue
        sections[-1] += ch
        j += 1
    out: list[tuple[str | None, str]] = []
    for sec in sections[1:3]:
        k = 0
        while k < len(sec) and sec[k:].strip():
            m = ASM_OPERAND.match(sec, k)
            if not m:
                return None
            depth, k = 1, m.end()
            while k < len(sec) and depth:
                depth += {"(": 1, ")": -1}.get(sec[k], 0)
                k += 1
            out.append((m.group(1), m.group(2)))
            while k < len(sec) and sec[k] in " \t\n,":
                k += 1
    return out


def memory_operand(ref: str, operands: list[tuple[str | None, str]] | None) -> bool:
    """`%N` / `%[name]` naming an operand whose constraint is a plain memory constraint ("m", "=m", "+m")."""
    m = MEMORY_REF.match(ref)
    if not m or not operands:
        return False
    if m.group(1) is not None:
        n = int(m.group(1))
        if n >= len(operands):
            return False
        constraint = operands[n][1]
    else:
        named = [c for name, c in operands if name == m.group(2)]
        if len(named) != 1:
            return False
        constraint = named[0]
    return constraint.lstrip("=+&") == "m"


def vfpu_only(template: str, operands: list[tuple[str | None, str]] | None = None) -> bool:
    """True when the template holds at least one instruction and every instruction is a VFPU instruction whose
    memory operand, if it has one, is an explicit `offset(base)` or a `%N` whose constraint (from `operands`) is
    "m". Empty parts and the `.set` mode switches of VFPU_SET are ignored; labels, other directives and any other
    mnemonic make it False."""
    text = template.replace(BACKSLASH + "n", "\n").replace(BACKSLASH + "t", " ")
    seen = False
    for part in re.split(r"[\n;]", text):
        part = part.split("#", 1)[0].strip()
        if not part or VFPU_SET.match(part):
            continue
        mnemonic, _, args = part.partition(" ")
        if not VFPU_MNEMONIC.match(mnemonic):
            return False
        if VFPU_MEMORY.match(mnemonic):
            ops = [o.strip() for o in args.split(",", 1)]
            if len(ops) != 2 or not (VFPU_ADDRESS.match(ops[1]) or memory_operand(ops[1], operands)):
                return False
        seen = True
    return seen


def vfpu_allowed(text: str, header: dict | None) -> bool:
    """The source-level conditions of the VFPU rule: header key `asm=vfpu` and a line `Original inline VFPU asm: ...`."""
    return header is not None and header.get("asm") == "vfpu" and bool(VFPU_REASON.search(text))


REGISTER_BINDING = re.compile(r"""^\s*(?:static\s+|volatile\s+|const\s+)*register\b[^;{}]*?(?<![\w$])(?:__asm__|__asm|asm)\s*\(\s*["']\$?\w+["']\s*\)\s*(?:=[^;]*)?;?\s*$""", re.S)
EMPTY_ASM = re.compile(r"""(?:__asm__|__asm|asm)\s*(?:__volatile__|volatile)?\s*\(\s*(?:""\s*)+(?:[:)]|$)""")


def check_text(text: str, header: dict | None = None, tree: str = "src") -> list[Finding]:
    """Findings for one source. `header` is the parsed HSTMATCH header (for extra=); `tree` is "src" for a source that
    is installed (an `extra=` key is refused there) or anything else (wip, a lane's scratch file)."""
    code = strip_comments(text)
    findings: list[Finding] = []
    lines = text.split("\n")
    vfpu_ok = vfpu_allowed(text, header)
    for m in ASM_TOKEN.finditer(code):
        stmt = _statement_around(code, m.start())
        ln = _line_of(code, m.start())
        shown = lines[ln - 1] if ln - 1 < len(lines) else m.group(0)
        if PRAGMA.match(shown):
            continue            # a #pragma asm line is reported once, as pragma-code (an asm in a #define is not)
        if REGISTER_BINDING.match(stmt):
            findings.append(Finding("register-asm-binding", IDIOM, ln, shown))
        elif EMPTY_ASM.search(code[m.start():m.start() + 200]):
            findings.append(Finding("empty-asm-barrier", IDIOM, ln, shown))
        elif (vfpu_ok and (tpl := asm_template(code, m.start())) is not None
              and vfpu_only(tpl, asm_operands(code, m.start()))):
            findings.append(Finding("vfpu-inline-asm", IDIOM, ln, shown))
        else:
            findings.append(Finding("asm-emit", REFUSE, ln, shown))
    for m in DIRECTIVE.finditer(code):
        ln = _line_of(code, m.start())
        findings.append(Finding("data-directive", REFUSE, ln, lines[ln - 1]))
    for m in PRAGMA.finditer(code):
        name = m.group(1)
        ln = _line_of(code, m.start())
        if CODE_PRAGMA.search(name):
            findings.append(Finding("pragma-code", REFUSE, ln, lines[ln - 1]))
        elif name not in KNOWN_PRAGMAS and not TEXT_SECTION.search(m.group(0)):
            findings.append(Finding("pragma-unknown", WARN, ln, lines[ln - 1]))
    for m in TEXT_SECTION.finditer(code):
        ln = _line_of(code, m.start())
        findings.append(Finding("text-section", REFUSE, ln, lines[ln - 1]))
    for m in INCLUDE.finditer(code):
        suffix = Path(m.group(1)).suffix.lower()
        if suffix not in HEADER_EXT:
            ln = _line_of(code, m.start())
            findings.append(Finding("binary-include", REFUSE, ln, lines[ln - 1]))
    if tree == "src" and header is not None and "extra" in header:
        findings.append(Finding("extra-header", REFUSE, 1, f'extra="{header["extra"]}"'))
    return sorted(findings, key=lambda f: (f.line, f.kind))


def tree_of(path: Path, root: Path = ROOT) -> str:
    try:
        rel = path.resolve().relative_to(root.resolve())
    except ValueError:
        return "other"
    return rel.parts[0] if rel.parts else "other"


def check_file(path: Path, root: Path = ROOT) -> list[Finding]:
    text = path.read_text(encoding="utf-8", errors="replace")
    header = None
    m = re.search(r"/\*\s*HSTMATCH\s+(.*?)\*/", text[:2000], re.S)
    if m:
        header = {k: v.strip('"') for k, v in re.findall(r'(\w+)=("[^"]*"|\S+)', m.group(1))}
    return check_text(text, header, tree_of(path, root))


def refusals(findings: list[Finding]) -> list[Finding]:
    return [f for f in findings if f.severity == REFUSE]


def summary(findings: list[Finding]) -> str:
    """'kind1,kind2' for the refusals (used as the detail of a failed gate)."""
    return ",".join(sorted({f.kind for f in refusals(findings)}))


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("files", nargs="*", type=Path)
    ap.add_argument("--all", action="store_true", help="every source under src/")
    ap.add_argument("--wip", action="store_true", help="with --all, wip/ as well")
    ap.add_argument("--show", choices=("idiom", "warn"), help="also list idioms or warnings")
    args = ap.parse_args()
    paths = list(args.files)
    if args.all:
        trees = ["src"] + (["wip"] if args.wip else [])
        paths += sorted(p for t in trees for p in (ROOT / t).rglob("*") if p.suffix in (".c", ".cpp"))
    if not paths:
        ap.error("name files or pass --all")
    refused = 0
    counts: dict[str, int] = {}
    for p in paths:
        findings = check_file(p)
        for f in findings:
            counts[f.kind] = counts.get(f.kind, 0) + 1
            shown = {REFUSE} | ({IDIOM} if args.show in ("idiom", "warn") else set()) | ({WARN} if args.show == "warn" else set())
            if f.severity in shown:
                print(f"{p.resolve().relative_to(ROOT).as_posix() if p.resolve().is_relative_to(ROOT) else p}: {f}")
        refused += bool(refusals(findings))
    print(f"checked {len(paths)} files: {refused} refused; findings by kind: {counts or 'none'}")
    return 1 if refused else 0


if __name__ == "__main__":
    raise SystemExit(main())
