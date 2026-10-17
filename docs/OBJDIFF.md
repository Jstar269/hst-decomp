# objdiff for the HST decompilation

[objdiff](https://github.com/encounter/objdiff) shows a per-function diff of a source against retail
and can print a progress report. This document explains how the project is generated, how to open it,
how to generate a report, and what objdiff does not do.

Everything objdiff reads is generated from `hstmatch.py`'s output, so **hstmatch remains the authority
on whether a function matches**; objdiff is the viewer and the progress report on top of it.

## 1. Install objdiff

objdiff is not vendored. Download the two official Windows x86_64 assets of the latest release into
`try/objdiff-bin/` (a scratch directory, not part of the deliverable):

```bash
mkdir -p try/objdiff-bin && cd try/objdiff-bin
curl -sSL -o objdiff.exe     https://github.com/encounter/objdiff/releases/download/v3.8.2/objdiff-windows-x86_64.exe
curl -sSL -o objdiff-cli.exe https://github.com/encounter/objdiff/releases/download/v3.8.2/objdiff-cli-windows-x86_64.exe
```

Version used here: **v3.8.2** (2026-09-29; `objdiff-cli.exe --version` prints `3.8.2`), the official
release assets with these SHA-256 digests:

| file | SHA-256 |
|---|---|
| `objdiff.exe` (GUI, 24,316,928 bytes) | `ce9d877a8cd6f133a962fb86d66f0348b9b88d735cea0fd52ae61bb9ad4d6691` |
| `objdiff-cli.exe` (7,144,448 bytes) | `36d229ac6ce74a26b47f42cf86ea8e808d8cd834a54aa62d7ed3f47b765d971b` |

`tools/hstobjdiff.py` looks for
`try/objdiff-bin/objdiff-cli.exe` by default, then `try/objdiff-bin/objdiff-cli`, then `objdiff-cli` on
`PATH`; `--objdiff-cli PATH` overrides.

## 2. Build the link products, then the project

objdiff units are built from hstmatch's output, so every source must have been matched at least once:

```bash
python tools/hstmatch.py --all --parallel 4          # src/ (about 45 min; --parallel 4 stays the cap)
python tools/hstmatch.py --parallel 4 wip/*.c wip/*.cpp   # the near misses, for their units
python tools/hstobjdiff.py                           # writes objdiff.json + build/objdiff/
```

`tools/hstobjdiff.py` writes, under `build/objdiff/` (generated, never committed):

```
units/<source>.base.o     our bytes of that function's range, at their retail address
units/<source>.target.o   the retail bytes of the same range, at the same address
unmatched/<module>.o      target-only unit: every retail function no source covers
empty.base.o              the empty base object the unmatched units use
hstobjdiff.json           what was generated: counts, warnings, skipped sources
```

and `objdiff.json` in the repository root, which is the project file both the GUI and
`objdiff-cli report generate` read. `generate` takes `--no-wip` (leave `wip/` out, see §4), `--only GLOB`
(debug a subset) and `--quiet`; `--out FILE` (default `objdiff.json`) picks the project file and
is accepted before or after the subcommand, so both `python tools/hstobjdiff.py --out p.json generate`
and `python tools/hstobjdiff.py generate --out p.json` work.

A `--only` subset is a debug aid with two consequences: its project has **no** `unmatched/` units (so its
`total_code` is only the subset and cannot be compared with hstcov), and it leaves the shared
`unmatched/*.o` objects of the real project alone - those objects depend on which sources were
generated, so rebuilding them from a subset would silently corrupt the full project's totals until the
next full `generate`. Always write a subset with `--out`, never over `objdiff.json`.

A full `generate` writes ~17,200 small objects and takes about five minutes on Windows (the cost is
file I/O; nearly all of it is reading hstmatch's `text.bin`). It is meant to be run after a matching
session, not on every edit: use `--only` while debugging, and `check` does not regenerate anything.

### How a unit is built

* **base** - the source's linked bytes. hstmatch links our object with `.text` at the retail address
  and extracts the section to `text.bin`; `tools/hstobjdiff.py` slices the header's range out of it
  (at the offset hstmatch used, for the rare source that is one function of a file compiled as a
  whole) and repacks it into a minimal ELF32 little-endian `EM_MIPS` object. `e_flags` is copied from
  the hstmatch object, so objdiff sees the toolchain's own header flags.
* **target** - the same range of the retail module image (through `hstmatch.module_bytes`, the same
  helper the other tools use), repacked the same way.
* **symbols** - both sides carry one `FUN_<address>` symbol per ledger function in the range, with the
  ledger's start and size. Using the ledger's boundaries (rather than the compiler's) is what makes
  the report's byte totals comparable with `hstcov.py`: a unit stands for exactly the ledger functions
  the source spans, and every ledger function appears in exactly one unit.

Both sides are fully resolved images at the retail address, so no relocation reconstruction is needed
and objdiff compares instruction words directly. Because the hstmatch artifacts and the retail images
are involved, `build/objdiff/` must never be committed.

## 3. Open the project in the GUI

Run `try/objdiff-bin/objdiff.exe`. objdiff opens a project *directory*, not a file: until one is chosen it
shows "No project selected". Next to the **Project** heading in the left panel, open **Settings**, and under
**Project directory** select the repository root (the directory that holds the generated `objdiff.json`). objdiff
remembers it (**Recent projects…** in the menu). The unit list is the source tree: `src/eboot/FUN_0001b918`,
`wip/FUN_0007fa1c`, … Select a unit and a function to see our code next to retail, with the diff
highlighted.

The project has `build_base`/`build_target` disabled on purpose: objdiff must not try to run a build
system of ours, and the objects are already there. The GUI's "rebuild" button therefore does nothing
useful - regenerate with `tools/hstobjdiff.py` instead, and reload the unit. Sources with a missing
hstmatch artifact are not in the project at all; the tool reports them ("N source(s) skipped") and
lists them in `build/objdiff/hstobjdiff.json`.

## 4. Generate a progress report

```bash
try/objdiff-bin/objdiff-cli.exe report generate -p . -o build/objdiff/report.json --format json
# or, human readable:
try/objdiff-bin/objdiff-cli.exe report generate -p . -o build/objdiff/report.txt
```

(`-p .` is the directory holding `objdiff.json`; the extension decides the format, and `-o -` prints to
stdout.)

The report groups by the `progress_categories` of the project (one per module) and prints
`total_code`, `matched_code`, `complete_code`, `total_functions` and `matched_functions`.

* `total_code` is the sum of every ledger function's size, i.e. the same denominator as
  `python tools/hstcov.py` (`code_bytes`).
* `matched_code` counts the bytes of functions that match fully, in every unit.
* `complete_code` counts the same, restricted to the units marked complete, i.e. the sources installed
  in `src/`; that is the figure to compare with hstcov's `exact_bytes`.

With the project as generated (`src/` plus `wip/`), no near miss matches fully, so `matched_code`,
`complete_code` and hstcov's `exact_bytes` are the same number, and `total_code` equals hstcov's
`code_bytes` - the report agrees with `hstcov.py` on both the numerator and the denominator.

`python tools/hstobjdiff.py check` runs the comparison for you.

## 5. Verify the project

```bash
python tools/hstobjdiff.py check --random 30        # 30 random src/ units must be 100%
python tools/hstobjdiff.py check --random 0 --wip   # every src/ unit, and every wip/ unit vs hstdiff.py
```

`check` compares, and fails on any difference:

1. `complete_code`/`total_code` and matched function counts per module against
   `python tools/hstcov.py --json`;
2. a random sample of `src/` units (`--random 0` = all of them) at 100%;
3. with `--wip`: every `wip/` unit below 100%, and its differences cross-checked with
   `python tools/hstdiff.py <file>` against the bytes the generator wrote:
   * every instruction hstdiff marks (its `**` lines, at a fixed 4-byte stride) must be a word that
     really differs between the unit's base and target objects, and
   * every instruction objdiff reports as different must sit on such a word or immediately next to
     one, because objdiff aligns the two instruction streams.

   The two tools do not report the same *number* of differences, by design: hstdiff compares word<i>i</i>
   with word<i>i</i>, so one inserted instruction makes every later position differ (a cascade), while
   objdiff aligns the streams and resolves branch targets to the instruction they point at. `check`
   therefore prints three counts per unit - words whose bytes differ, instructions objdiff reports,
   instructions hstdiff marks - and fails only on differences that do not correspond to a real byte
   difference.

A `wip/` draft whose function an installed `src/` source already matches is skipped as superseded: two
units for one ledger function would count its bytes twice. `generate` reports those (and removes their
leftover objects).

## 6. Known limitations

* **The instruction category must be Allegrex.** objdiff's default MIPS instruction category cannot
  decode the PSP's Allegrex instructions: `ext`, `ins`, `seb`, `seh`, `bitrev`, `wsbh`, `movz` and `movn`
  become `INVALID` with their operands dropped, `max`/`min` show as `daddu`/`dsubu`, and VFPU as generic
  cop2/64-bit instructions. Worse, every `INVALID` word compares equal whatever its bytes (measured on
  `FUN_0014d788`: flipping one bit inside its `ext` still reported 100.0%). The generated `objdiff.json`
  therefore sets `"options": {"mips_instr_category": "r4000allegrex"}`, and `check` passes the same
  property to its one-shot `objdiff-cli diff` runs (`-c mips_instr_category=r4000allegrex`; one-shot diffs
  do not read the project file). With it, the same flipped bit reports 99.83%, and objdiff's disassembly
  agrees with `psp-objdump -m mips:allegrex` on ext/ins/seb/min and the VFPU (`lv.q`, `vmul.q`, `mfv`,
  ...) apart from objdump's `move`/`li` pseudo-instruction spellings. If the GUI ever shows `INVALID` for
  such an instruction, set the diff option *Instruction category* to *R4000 Allegrex*.
* **No data diffing.** Units carry `.text` only; `rodata=`/`.data` sections are not placed into the
  unit objects, so objdiff shows code, not the surrounding data. hstmatch still checks placed sections
  byte-for-byte (`SECTION_MISMATCH`), so match quality is unaffected.
* **Only the ledger's functions exist as symbols.** objdiff cannot show a helper our compiler emitted
  under a different name as a separate function; a source's whole header span is diffed as the ledger
  function(s) it covers.
* **A near miss can be longer or shorter than the ledger function.** A unit compares exactly what
  hstmatch.py compares: the ledger function on the target side, and on our side the header span or the
  whole compiled function when that is longer (the extra bytes stay unattributed; a shorter function is
  clamped, because objdiff rejects a symbol whose data runs past its section).
* objdiff reports `fuzzy_match_percent`, which counts instruction arguments; the project's numbers of
  interest are the byte totals and the presence of a unit at 100%.
* `tools/hstobjdiff.py` is the only writer of `objdiff.json` and of `build/objdiff/`; it never touches
  `src/`, `wip/`, `symbols/`, the other tools or `hst-config.json`.
