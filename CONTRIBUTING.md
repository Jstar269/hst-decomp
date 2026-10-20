# Contributing

This guide describes how functions are matched, installed and documented in this repository. It is written for a
person; the version for automated matching agents is [docs/AGENT-BRIEF.md](docs/AGENT-BRIEF.md), and the two are
meant to agree.

The repository is not yet open to outside contributions. Contributions are licensed as [Licensing](docs/GUIDE.md#licensing) in the project guide says:
GPL-3.0-or-later for `src/`, `wip/` and `symbols/`, MIT for the tools, documentation and headers. This guide is for the
owner and for anyone the owner invites.

## Ground rules

- **A source enters `src/` only when `tools/hstmatch.py` reports `EXACT` for it.** Exact means the compiled and linked
  bytes equal the retail bytes of the function, with no masking. There are no near misses in `src/`.
- Code taken from another project (newlib is the case so far) keeps its copyright and licence notices and is listed in
  `THIRD_PARTY.md`; do not remove a notice and do not paste a compiler's or SDK's header text into a source (the
  project-authored headers in `include/` exist for that). Library sources are produced by `tools/hstnewlib.py`.
- Do not commit game data of any kind: no retail modules, no disassembly dumps of whole modules, no keys, no
  compilers. The ignore rules already exclude binaries and key files; keep it that way.
- Do not edit existing lines of `symbols/` (appending is allowed, see below), and do not edit `tools/` as part of a
  matching change.
- The tools that write into `src/` (`hstgen`, `hstclone`, `hsttmpl`, `hstperm`, `hstnewlib`) and the one that builds
  batches for matching agents (`hstqueue`) are run deliberately by whoever runs the campaign, not casually while
  matching a function.
- Keep scratch work out of the tracked tree: use `try/<your-name>/` (gitignored). Build products go to
  `build/<module>/<dir>__<stem>`, so use a distinct directory name to avoid colliding with someone else's run.
- Do not search recursively (`grep -r`) outside `src/`, `wip/`, `docs/`, `symbols/`, `include/` and your own `try/`
  directory. The campaign directory and `build/` can hold gigabytes.

## Setting up

Follow [Setup](docs/GUIDE.md#setup) in the project guide, then check that one function builds:

```
python tools/hstconfig.py check
python tools/hstmatch.py src/eboot/FUN_00000000.c
```

## Method

1. **Pick a function.** `python tools/hstfamilies.py` ranks unmatched clone families (code identical apart from
   addresses): one match unlocks the whole family, because `hstclone.py` propagates it. For single functions,
   `python tools/hstqueue.py` builds batches, listing the Ghidra pseudocode path and, if one exists, the best
   mechanically generated candidate (`best_generated.source`), which is a good starting point.
2. **Read the code.** `python tools/hstdis.py 0xADDR` prints the retail disassembly of any reviewed function, so look at
   the callees and callers too: they tell you types, argument counts and what a call returns. The Ghidra pseudocode
   is advisory and often wrong in detail (see the compiler notes below).
3. **Write the function.** Start from the generated candidate, or write it by hand. Prefer natural code (structs with
   fields, member functions, loops with `break`) over the decompiler's pointer arithmetic.
4. **Iterate.** `python tools/hstmatch.py <file>` compiles, links at the retail address and compares;
   `python tools/hstdiff.py <file>` then prints your disassembly next to retail's, with `**` marking differing words.
   Always pass explicit file names. `--flags` and a header `extra=` are for experiments and never count as a match.
5. **Budget.** About 40 compiles per function is a reasonable limit. When stuck, move on and come back later; if you
   end within a few words, save a near miss (below).
6. **Install** the source once it is EXACT (below), and re-run the matcher on the installed file.

External references: address-named symbols (`FUN_xxxxxxxx`, `DAT_xxxxxxxx` with exactly 8 hex digits) link at their
address automatically. Every other name must be in `symbols/<module>.txt` (C++ runtime helpers, vtables, mangled
member names). If a match needs a new named symbol, verify its address in the disassembly, check with `grep` that the
name is not already there, and **append** one line:

```
printf '%s\n' 'name = 0xADDR;   # <your source file>' >> symbols/<module>.txt
```

A function whose constants or jump table live in `.rodata` needs `rodata=0xADDR` in the header, the address that
retail's `lui`/`lo` pair loads. The matcher then also requires the placed bytes to equal retail (`data=`, `sdata=`,
`bss=` and `sbss=` work the same way).

### Same-file static helpers

If retail's code depends on a `static` helper compiled earlier in the same file (for example MWCC keeping `a0` live
across a call it knows preserves `a0`), match the whole contiguous run of retail functions in one source: `start=` is
the first function's start, `end=` the last function's end, `symbol=` the first function, and the functions are
defined in address order. The matcher compares the whole span. Name the file `<name>_<first addr8>_run.cpp` and say
"run" in the note line.

## Source file format

**File name and place.** `src/eboot/` for `EBOOT.BIN`, `src/sharing_main/` for `hstp_trans_main.prx`; name the file
`<short_descriptive_name>_<addr8>.cpp` (or `.c`), where `<addr8>` is the start address in eight hex digits. Before
installing, check that nobody covered the function already (a duplicate must be removed, keeping the reviewed one):

```
grep -l "start=0x<addr>" src/*/* wip/*
```

**Line 1: the header.**

```c
/* HSTMATCH module=EBOOT.BIN start=0x0011d894 end=0x0011dad8 symbol=FUN_0011d894 lang=c++ */
```

`module`, `start`, `end` and `symbol` are required (`symbol` must be the name your source defines for the function).
`lang` is `c99` or `c++`. Optional: `cc=<profile>` (absent means MWCC build 219; GCC sources say `cc=gcc171-O2` or
`cc=gcc171-Os`), the section placement keys above, and the experimental `extra=`.

**Line 2: the note.** Exactly one provenance note, and it must be true. "Hand-written" means a person wrote it; a
source that started from a generated candidate names the generator tag.

- Written from scratch, or heavily restructured:
  `/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */`
- Derived from a generated candidate with small corrections:
  `/* Ghidra pseudocode (hstgen.py tag <tag>) corrected by hand: <what you changed>; exact match verified; names and types await human review. */`
- The tools write the other kinds themselves: `Mechanical translation of Ghidra pseudocode (hstgen.py tag X)`,
  `Clone of src/... (hstclone.py tag X)`, `... (template instance, hsttmpl.py tag X)` and
  `Library source: newlib <release> <dir>/<file>.c function <name>, ...`.

`python tools/hstlint.py` rejects a source without a known note kind.

## Source quality

The owner reviews every source at the end, so aim for the code the developers wrote.

- Among exact variants, keep the most natural one: real control flow (loops, early returns, `switch`), structs and
  member access instead of `*(int *)(p + 0x14)` when the layout is clear, `bool` and enums where obvious.
- Avoid matching hacks: duplicated conditions, dummy locals or parameters that only steer register allocation,
  `volatile`, self-assignments, gratuitous casts or `goto`. When one of them is the **only** exact form you found,
  keep it, but name it in the note line ("matching idiom: <what>"); `hstlint.py` counts those.
- Names: use a descriptive name only when the evidence supports it (strings, callers, documented research findings);
  otherwise keep the Ghidra address names. Never invent semantics.
- Be consistent: one declaration per symbol across the tree (`hstlint.py` reports symbols declared with different
  types in different sources).

## Near misses

If a function ends within about six differing words but not exact, save your best attempt to
`wip/<short_name>_<addr8>.cpp` (same header) with trailing `//` comments: what differs and what you ruled out. Files
in `wip/` are not built by `--all` and are not verified; they are leads for the next person.

## Compiler notes

The detailed, address-referenced findings are in [docs/MWCC-DIGEST.md](docs/MWCC-DIGEST.md) (by topic) and
[docs/MWCC-NOTES.md](docs/MWCC-NOTES.md) (the append-only log). Read the digest before starting; it saves many compiles.
If you learn something new, append **one dated line** to `MWCC-NOTES.md` that names the function address (append only,
never rewrite the file):

```
cat >> docs/MWCC-NOTES.md <<'EOF'
- 2026-10-15 (0xADDR): what you found, with the evidence.
EOF
```

The main points, as a start:

- **Game code** is `mwccpsp` 3.0.1 build 219 with `-c -O4,p -sdatathreshold 0`. Some objects were built with
  strength reduction off; those sources carry `#pragma opt_strength_reduction off` themselves. Other per-file pragmas
  seen: `inline_depth(8)` for deep container inline chains, `opt_unroll_loops off`, `pack(1)` (rarely).
- **Undo Ghidra's artefacts.** It inverts `if`/`else` (try both orders), drops parentheses in float chains
  (`a*b*c` may be `a*(b*c)`), prints a signed `x / 2^k` as a shift sequence, hoists repeated subexpressions into
  temporaries, prints `i <= C` as `i < C+1` and `for` loops with `break` as early returns, and drops trailing call
  arguments of callees it typed with fewer parameters. The registers set before a `jal` reveal the real arguments;
  an integer `0` next to a pointer may be a float.
- **Registers follow declaration order.** MWCC gives saved registers in the order locals are declared, the
  earlier-declared getting the higher `s` register. Colouring is global, so a swap in one place can come from code
  elsewhere. Try permuting the declarations of 3 to 6 locals before restructuring.
- **Types decide instructions.** Flags tested `!= 0` that Ghidra types `char` or `undefined4` are usually
  `unsigned char` (`lbu`); `bool` results are often `int` returns; a global used as a struct base must be a pointer;
  numeric module addresses in the pseudocode are symbols (`&DAT_xxxxxxxx`), never integer constants.
- **Stack frames.** Address-taken locals sit in declaration order from the frame top, and each empty class passed by
  value (allocator and tag objects in the container code) reserves a hidden slot.
- **The `hstp_trans_main.prx` ("Sharing") twins** of `EBOOT.BIN` functions are the same source built as a debug build
  with `ASSERT` calls; the `EBOOT.BIN` build drops them, and code after an always-failing assert disappears there.
- **SDK code is GCC.** Sony's SDK objects (most of `EBOOT.BIN` below `0x88000`, and the Sony PRXs) are `psp-gcc`
  output: `ra` saved at the top of the frame, `t` temporaries, `movn`/`movz`, `j` between blocks. Use
  `cc=gcc171-O2` or `cc=gcc171-Os` and plain C, without MWCC pragmas; the declaration order of locals has no effect.
  The SDK C library and math library are newlib: report such a function rather than reconstructing it by hand
  (`hstlib.py` and `hstnewlib.py` match it from the library source).
- **Known limit.** Retail uses the Allegrex `ins rd,$zero,pos,size` instruction for field-clearing masks in part of
  the math library, and neither published Sony `psp-gcc` kit emits it. Record such functions in the notes and move
  on.

## Checks before you finish

```
python tools/hstmatch.py <every file you added or changed>     # EXACT n/n
python tools/hstlint.py                                         # no header findings
```

When a change adds files, `python tools/hstreuse.py check` confirms that every tracked file is covered by the licence
map (`REUSE.toml`); new library sources need `python tools/hstreuse.py newlib --write` first. `ORIGINS.json` is a
snapshot made by `python tools/hstorigin.py`; refresh it before a release (`hstpublish.py` classifies afresh).

For a change that touches many sources, `python tools/hstmatch.py --all` is the full regression (it shares `build/`
with any concurrent run, so run one at a time).
