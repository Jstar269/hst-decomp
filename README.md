# Hot Shots Tennis: Get a Grip (PSP) matching decompilation

A work-in-progress matching decompilation of *Hot Shots Tennis: Get a Grip* (PlayStation Portable, UCUS98701).

"Matching" here is strict. Every file under `src/` is C or C++ that, compiled with the pinned compiler and linked
at the function's retail address, produces **exactly the bytes of the retail function**. There is no masking:
every relocated field comes from the linker and the symbol map, and the comparison is byte for byte. A source that
does not match is not kept in `src/`.

This repository is the public part of the project: Sony SDK reconstructions and a few maintainer-only files are
kept out of it (see [Origin classes and the publish filter](#origin-classes-and-the-publish-filter)); how each part of it is licensed is
described under [Licensing](#licensing).

## Legal notice

- The repository contains **no game assets, no executables, no encryption keys and no compilers**. Nothing in it
  lets you obtain the game. The function boundaries in `data/`, the symbol maps in `symbols/` and the boundary
  lists in `ghidra/` are addresses and sizes derived from the executables, not their contents.
- You need your own, legally obtained copy of the game. The tools read the game's modules in decrypted form, and
  **decrypting your copy is your own responsibility**; this repository contains no decryption code and no keys.
- The compilers are not distributed here. They come from decomp.me's published compiler kits
  (<https://github.com/decompme/compilers>: Metrowerks `mwccpsp` and the Sony `psp-gcc` kits) and from the wibo
  project (<https://github.com/decompals/wibo>). Their licences are their vendors' licences; check them before
  using them. See [THIRD_PARTY.md](THIRD_PARTY.md).
- This is an unofficial fan project. It is not affiliated with, or endorsed by, the game's developer or publisher.
  The game, its name and its trademarks belong to their owners.

## Status

This repository holds **10,469 exact sources** under `src/` (covering 10,470 functions: a source may cover a short run of
functions) and 256 near misses under `wip/`. Each source is verified EXACT when installed and before
commit. Before publication, newly added or changed sources are checked again with
`python tools/hstmatch.py`. Coverage of the two executables reconstructed here (`python tools/hstcov.py` after the bootstrap,
measured 2026-10-20, counted in code bytes; a function counts when an exact source covers its start address):

| Module | Matched / functions | Matched / code bytes | Share of bytes |
|---|---|---|---|
| `EBOOT.BIN` | 5,255 / 9,804 | 705,552 / 2,849,076 | 24.764 % |
| `hstp_trans_main.prx` (Sharing Version) | 5,215 / 9,830 | 680,744 / 2,914,004 | 23.361 % |
| **Both** | 10,470 / 19,634 | 1,386,296 / 5,763,080 | 24.055 % |

The function lists in `data/` are the reviewed boundaries of each module: 19,634 functions, with a few dozen
candidate spans still open. Runtime and static module surveys found no other game code.

Not published here: reconstructions of Sony SDK code, that is, the `psp-gcc`-built SDK runtime of the two
executables and the Sony system-library modules the game loads (`libfont`, `scePsmf`, `scePsmfP`). Those functions
count as unmatched in the table above; see [Origin classes and the publish filter](#origin-classes-and-the-publish-filter).

What the sources are, and are not:

- Matching proves the *compiled bytes*, not that the source is what the developers wrote. Names are mostly the
  address names from Ghidra (`FUN_0011d894`), and types are provisional. Every note line says "names and types
  await human review" until a person has reviewed the source.
- Of the 10,469 sources, 6,410 are address-substituted **clones** of another matched source (retail contains the same
  code many times), 2,136 are mechanical translations of Ghidra pseudocode, 723 are such translations corrected by
  hand, 1,001 are hand-written, 136 are instances of container templates, and 63 are newlib library functions
  translated from newlib sources (18 more are clones of them, counted among the clones).
- 81 of the sources are newlib library functions compiled with Sony's `psp-gcc` kits; all others are game code
  compiled with Metrowerks `mwccpsp`.
- Some SDK functions use the Allegrex `ins rd,$zero,...` instruction, which neither published Sony `psp-gcc` kit
  emits (nor does a current GCC in the same way); they cannot be matched until a later kit is available (see
  `docs/MWCC-NOTES.md`).
- `python tools/hstlint.py` reports how the sources read (matching idioms such as `volatile`, `goto`, duplicated
  conditions), and 860 symbols are declared with differing types in different sources. Cleaning that up is future
  work.

## Requirements

The tools run on a **Windows host and drive the compilers inside WSL** (they call `wsl.exe`).

- Python 3.12 or newer (checked with 3.14; no third-party packages).
- WSL with an Ubuntu distribution.
- `libc6-i386` in WSL (`sudo apt install libc6-i386`): the Sony `psp-gcc` kits are 32-bit Linux programs.
- [wibo](https://github.com/decompals/wibo) 1.2.0, to run the Windows compiler under Linux.
- `mwccpsp.exe` 3.0.1 build 219 (the decomp.me build `219`).
- The decomp.me Sony `psp-gcc` 1.3.1 and 1.7.1 kits.
- PSPDEV binutils (`psp-ld`, `psp-objcopy`, `psp-objdump`) for linking at the retail address and for disassembly.
- Your own decrypted copies of the two executables (see [Setup](#setup)); `tools/hstbootstrap.py` turns them into the
  campaign directory the tools read.

Optional: newlib source trees (library reconstruction, `hstnewlib.py`), and Ghidra 12.x with a JDK 21
(`ghidra/run_commit_decompile.ps1`).

## Setup

1. Install the compilers in WSL, on the **native Linux filesystem** (the i386 `psp-gcc` cannot stat files on
   `/mnt/c`). The layout the tools expect:

   ```
   <mwcc_native>/wibo
   <mwcc_native>/builds/219/mwccpsp.exe
   <gcc_home>/psp-gcc-1.3.1/bin/psp-gcc
   <gcc_home>/psp-gcc-1.7.1/bin/psp-gcc
   <pspdev_bin>/psp-ld   (and psp-objcopy, psp-objdump)
   ```

   `pspdev_bin` may live on `/mnt/c`.

2. Create the campaign directory, `<campaign_root>`, from your own decrypted copies of the two executables this
   repository reconstructs (the disc is Hot Shots Tennis: Get a Grip, UCUS98701, North America, version 1.01):

   ```
   python tools/hstbootstrap.py --out <campaign_root> --eboot <decrypted EBOOT.BIN> --sharing <decrypted DATA.PSP>
   ```

   | Module | On the disc | Decrypted size | SHA-256 of the decrypted module |
   |---|---|---|---|
   | `EBOOT.BIN` | `PSP_GAME/SYSDIR/EBOOT.BIN` | 4,178,820 | `ee39c40ee70af6bb5c76a0789898a9dc8c0a6ddcd0bd4d9d76f6200537f34bbe` |
   | `hstp_trans_main.prx` (Sharing Version) | `DATA.PSP` inside `PSP_GAME/USRDIR/bundle_data/trial/hstp_trans.pbp` | 4,952,948 | `5418712bbe4a4339cf30e5c78b486924f1d24fe313d8bf8b0d56fdc3132fe6ec` |

   The tool checks each file against these digests (a gzip-compressed image is inflated first), copies it into
   `<campaign_root>/inputs/`, and writes `ledger/campaign.json` (load segment and reviewed function boundaries,
   from `data/`) and `inputs/revision-selection.json`. It decrypts nothing: decrypting your copy is your own
   responsibility. A module you leave out is skipped, and `hstmatch.py` then cannot check that module's sources.

3. Describe your machine to the tools:

   ```
   copy hst-config.example.json hst-config.json
   notepad hst-config.json
   python tools/hstconfig.py check
   ```

   `hst-config.json` is gitignored. Every key can instead be set with the environment variable `HST_<KEY>`
   (for example `HST_CAMPAIGN_ROOT`), which overrides the file. Keys (all documented in
   `hst-config.example.json`):

   | Key | Kind | Meaning |
   |---|---|---|
   | `campaign_root` | host | `<campaign_root>`: ledger and revision selection (needed by almost every tool) |
   | `pspdev_bin` | WSL | PSPDEV binutils directory |
   | `mwcc_native` | WSL | wibo and `builds/<build>/mwccpsp.exe` |
   | `gcc_home` | WSL | the `psp-gcc-1.3.1` and `psp-gcc-1.7.1` kits |
   | `newlib_home` | WSL | newlib source trees (`hstnewlib.py` only) |
   | `newlib_obj_root` | host | built newlib objects (`hstlib.py index` only) |
   | `ext_root` | host | workspaces for external agent lanes (maintainers only; not needed to build or verify) |
   | `mwcc_builds_dir`, `wibo_exe` | host | host copies, for the digests `hstsample.py` records |
   | `ghidra_headless`, `java_home` | host | `ghidra/run_commit_decompile.ps1` only |

   A tool asks for a key only when it needs it, so `--help` and the local tools work without a configuration; an
   unset key stops the tool with a message that names the key.

4. Create the scratch directory the report-writing tools use: `mkdir try`. (`build/` is created on demand. Both are
   gitignored.)

## Verify

```
python tools/hstmatch.py --all                   # rebuild and compare every source under src/
python tools/hstmatch.py --all --parallel 12     # more concurrent compiles (default 6)
python tools/hstmatch.py src/eboot/FUN_00000000.c    # specific files
```

The result is one line per source (`--quiet` prints only the failures) and a total such as `EXACT 7761/7761`; the exit
status is 0 only when everything is EXACT. Statuses: `EXACT`, `MISMATCH` (with the number of differing words),
`COMPILE_FAILED`, `LINK_FAILED`, `MISSING_SYMBOLS`, `UNPLACED_SECTION`, `SECTION_MISMATCH`, `NO_SYMBOL`,
`MISPLACED`, and `EXACT_EXTRA_FLAGS` (an experiment with `--flags` or a header `extra=`, which never counts as a
match). `--json out.json` writes the results. Build products go to `build/<module>/<dir>__<stem>/`; a full rebuild
shares `build/` with any concurrent run, so run one at a time.

## Repository layout

| Path | Contents |
|---|---|
| `src/` | The exact-matched sources, by module: `eboot/` (`EBOOT.BIN`), `sharing_main/` (`hstp_trans_main.prx`). Do not edit by hand without re-running the matcher. |
| `wip/` | Near misses (within a few words of exact) with comments on what differs. Not built by `--all`, not verified. |
| `data/` | `modules.json` (each module's description, SHA-256 and load segment) and `functions-<module>.txt` (its reviewed function boundaries). `tools/hstbootstrap.py` reads both. |
| `symbols/` | `symbols/<module>.txt`: `name = 0xaddr;` maps for names that are not address-named (C++ runtime, vtables, library functions). Append-only in practice. |
| `include/` | Project-authored headers: `stddef.h`, `stdint.h` (the only headers the MWCC sources see, via `MWCIncludes`) and `stdarg.h`, `float.h`, `limits.h`, which stand in for the compiler's own headers when `hstnewlib.py` preprocesses newlib sources (`-nostdinc`). |
| `tools/` | The matcher and the other tools, below. |
| `toolchain/drivers/` | `mwcc_wibo_link.py`, the build driver the private campaign pins (compile with wibo, link at the retail address, extract `.text`), and its tests. |
| `ghidra/` | The headless pseudocode export (`HstCommitDecompile.java`, `run_commit_decompile.ps1`) and the reviewed function boundaries of the two large modules. |
| `docs/` | `AGENT-BRIEF.md` (instructions for automated matching agents), `MWCC-NOTES.md` (append-only log of verified compiler behaviour) and `MWCC-DIGEST.md` (the same, by topic), and `OBJDIFF.md` (the objdiff project, see `hstobjdiff.py`). |
| `third_party/` | `newlib/`: newlib's own licence lists (`newlib-<release>-COPYING.NEWLIB`, verbatim) and the table of every newlib-derived source with its release, upstream file, terms and tarball SHA-256. |
| `LICENSE`, `LICENSES/`, `REUSE.toml` | The licence map: `LICENSE` is the GPL-3.0 text, `LICENSES/` holds every licence text, `REUSE.toml` assigns a licence and copyright to each path (see [Licensing](#licensing)). |
| `ORIGINS.json` | Origin class of every source (`python tools/hstorigin.py`), a snapshot: `hstpublish.py` classifies afresh. |
| `hst-config.example.json` | Template for the gitignored `hst-config.json`. |

Generated: `build/` (matcher output) and `try/` (scratch and reports), both gitignored; `reviews/decisions.jsonl`
(written by `hstreview.py`).

Sony SDK reconstructions and a few maintainer-only files are kept out of the public tree (see
[Origin classes and the publish filter](#origin-classes-and-the-publish-filter)).

## Source conventions

See [CONTRIBUTING.md](CONTRIBUTING.md) for the full rules; the format in short.

**Header (line 1).**

```c
/* HSTMATCH module=EBOOT.BIN start=0x0011d894 end=0x0011dad8 symbol=FUN_0011d894 lang=c++ */
```

- `module`: the module the function is in (`EBOOT.BIN`, `hstp_trans_main.prx`, `libfont.prx`,
  `scePsmfP_library.prx`); `start` and `end`: the retail span, module-relative; `symbol`: the name the source
  defines for the function. All four are required.
- `lang=c99|c++` (default from the file extension).
- `cc=<profile>` selects the compiler: absent means `mwcc219` (mwccpsp build 219, `-c -O4,p -sdatathreshold 0`);
  `gcc131-` or `gcc171-` plus `O1`, `O2`, `O3` or `Os` select a Sony `psp-gcc` kit (`gcc171x-*` adds `-mext`).
  The tree currently uses `mwcc219`, `gcc171-O2` and `gcc171-Os`.
- `rodata=0xADDR`, `data=`, `sdata=`, `bss=`, `sbss=`: where the object's sections go when the function refers to
  them; the matcher then also requires the placed `.rodata`/`.data`/`.sdata` bytes to equal retail.
- `extra="..."`: experimental extra compiler flags; such a source is never counted as a match (none are installed).

**Note line (line 2)** records where the source came from. Exactly one of:

| Kind | Starts with | Meaning |
|---|---|---|
| hand-written | `Hand-written reconstruction from the disassembly;` | Written by a person or agent from the disassembly. |
| generated | `Mechanical translation of Ghidra pseudocode (hstgen.py tag X);` | Output of `hstgen.py`, kept only because it matched. |
| corrected | `Ghidra pseudocode (hstgen.py tag X) corrected by hand: ...` | A generated source with small, listed corrections. |
| clone | `Clone of src/... (hstclone.py tag X);` | An exemplar with addresses substituted, for code that is identical apart from addresses. |
| template | `... (template instance, hsttmpl.py tag X)` | An instance of a project-authored container template (element size and offsets read from retail). |
| library | `Library source: newlib <release> <dir>/<file>.c function <name>, ...` | Upstream newlib source, preprocessed with its comments (licence headers) kept. |

`python tools/hstlint.py` rejects a missing or unknown note kind.

## Tools

| Tool | Purpose |
|---|---|
| `hstmatch.py` | The matcher: compile, link at the retail address, compare bytes exactly. |
| `hstdiff.py` | After a matcher run, print our disassembly next to retail's. |
| `hstdis.py` | Disassemble retail functions by address (`hstdis.py 0xADDR`). |
| `hstconfig.py` | Load, list and check `hst-config.json`; the other tools read their paths through it. |
| `hstcov.py` | Exact-match coverage per module against the campaign ledger. |
| `hstobjdiff.py` | Generate an [objdiff](https://github.com/encounter/objdiff) project (`objdiff.json`, objects under `build/objdiff/`) for per-function diffs against retail and a progress report; `check` verifies it against `hstmatch.py` and `hstcov.py` (see `docs/OBJDIFF.md`). |
| `hstlint.py` | Quality report over `src/` (note kinds, matching idioms, conflicting declarations). |
| `hstgen.py` | Translate Ghidra pseudocode into candidate C/C++ variants and install the exact ones. |
| `hstcat.py` | Classify why generated candidates mismatched (frame, register allocation, ...). |
| `hstperm.py` | Random-mutation search that turns near-miss candidates into exact ones. |
| `hstclone.py` | Propagate an exact source to every function whose code differs only in addresses. |
| `hstfamilies.py` | Rank unmatched clone families by total bytes (one match unlocks a whole family). |
| `hsttmpl.py` | Instantiate known container templates for every element size found in retail. |
| `hstlib.py` | Find newlib functions in retail by compiled-code signature (`index`, `report`). |
| `hstnewlib.py` | Turn `hstlib.py` hits into exact library sources (preprocessed with `-nostdinc`: newlib's headers plus `include/`, no compiler header text); `--regenerate` rebuilds installed library sources and their clones from the release, file and function their notes record. |
| `hstqueue.py` | Build work batches for matching agents. |
| `hstreview.py` | Local web app (127.0.0.1) for the owner's human review of matched sources. |
| `hstsample.py` | Write the reference-function sample manifest (digests of sources, targets and toolchain). |
| `hstorigin.py` | Classify every source by origin (`game`, `newlib`, `mw-runtime`, `sony-prx`, `gcc-unattributed`) and write `ORIGINS.json`; prints counts and bytes per class. |
| `hstbootstrap.py` | `--out DIR --eboot FILE --sharing FILE`: check your decrypted executables against `data/modules.json` and write the campaign directory (ledger and input selection) the other tools read. |
| `hstpublish.py` | `--out DIR`: copy the would-be public tree, without the Sony SDK classes and without anything gitignored, and print what was left out. Never touches a git remote. |
| `hstpublic.py` | Maintainers: `sync` mirrors the `hstpublish.py` tree into the public-branch worktree and commits it; `check COMMIT` (run by the pre-push hook) refuses a commit that contains a non-publishable source. |
| `hstreuse.py` | `check`: every tracked file is covered by exactly one effective `REUSE.toml` annotation; `newlib [--write]`: regenerate the newlib annotations and the table in `third_party/newlib/README.md`. |

Tools that install sources (`hstgen`, `hstclone`, `hsttmpl`, `hstperm`, `hstnewlib`) write into `src/`, and `hstqueue`
prepares batches for automated agents. A tool installs a source only after the matcher reports EXACT. The maintainers
also run external AI agent lanes with orchestration scripts that are kept out of the public tree.

## Origin classes and the publish filter

`python tools/hstorigin.py` gives every source under `src/` and `wip/` one origin class and writes them to
`ORIGINS.json` (path to class); a clone inherits the class of its exemplar.

| Class | Meaning |
|---|---|
| `game` | built with `mwccpsp`, not a runtime helper: the game's own code |
| `newlib` | a newlib library function (`Library source: newlib ...` note), under newlib's own terms |
| `mw-runtime` | built with `mwccpsp`, but the symbol is a Metrowerks runtime name (`__ptmf_scall`, `__destroy_*`, `__construct_*`) |
| `sony-prx` | code of a Sony system-library module (`libfont`, `scePsmf`, `scePsmfP`), kept in `src/libfont`, `src/psmf`, `src/psmfp` and `src/sharing_font` in the maintainers' tree |
| `gcc-unattributed` | `psp-gcc`-built code of `EBOOT.BIN` or the Sharing module that is not newlib: treated as Sony SDK until it is attributed |

`python tools/hstorigin.py` prints the current number of sources, source bytes and retail code bytes of each class.

`python tools/hstpublish.py --out DIR` copies the tracked files into a would-be public tree in `DIR` (a new or empty
directory), leaving out the `sony-prx` and `gcc-unattributed` sources, the maintainer-only paths (below), anything git
tracks although `.gitignore` says it is ignored, and the names of the left-out sources in the copied `ORIGINS.json`.
It prints what it left out (`--list` names every file) and runs only the local, read-only `git ls-files`: it never
touches a git remote. The classes to leave out are the one setting `EXCLUDED_CLASSES` at the top of
`tools/hstpublish.py`. **Why:** the reconstructions of Sony SDK and system-library code are not ours to release, so
they are excluded from public releases; in a public build those functions come from the user's own copy of the game.
(Sony SDK is excluded at publish time for now; the symbol maps in `symbols/`, the function lists in `data/` and the
boundary lists in `ghidra/` are not filtered.)

`PRIVATE_PATHS`, next to `EXCLUDED_CLASSES`, lists the maintainer-only files that are never published: working research notes,
and the scripts that run external agent lanes.

## The private campaign pipeline

The exact matches here are also recorded in a private *campaign*: a hash-bound ledger that pins the toolchain
(wibo, `mwccpsp`, the PSPDEV binutils and the Sony `psp-gcc` kits), records each module and reviewed function
boundary, and rebuilds every source in `src/` with a pinned driver (`toolchain/drivers/` holds the first one). The
campaign's scripts, toolkit and handoff notes depend on workstation paths and private evidence, so they are kept
outside this repository. The tools in `tools/` need only the two campaign files named in `hst-config.json`, which `tools/hstbootstrap.py`
writes from your own decrypted executables.

## Licensing

The repository is licensed by path, following the [REUSE](https://reuse.software/) specification: `REUSE.toml` maps
path patterns to an SPDX licence identifier and a copyright statement, and the licence texts are in
[`LICENSES/`](LICENSES/). `python tools/hstreuse.py check` verifies that every tracked file is covered by exactly one
effective annotation.

| Paths | Licence |
|---|---|
| `src/` (except the newlib-derived sources below), `wip/`, `symbols/`: the reconstructed code | **GPL-3.0-or-later** ([`LICENSE`](LICENSE)) |
| `tools/`, `toolchain/`, `ghidra/scripts/`, `ghidra/run_commit_decompile.ps1`, `ghidra/boundaries-*.txt`, `include/`, `docs/`, `README.md`, `CONTRIBUTING.md`, `THIRD_PARTY.md`, `hst-config.example.json`, `.gitignore`, `.gitattributes`, `REUSE.toml`, `ORIGINS.json` | **MIT** |
| The newlib-derived sources in `src/` (exactly the files `tools/hstorigin.py` classifies as `newlib`) and `third_party/` | **their own terms** (BSD-style and similar notices kept in the files) |

- The GPL grant covers **only the project's own contributions**. It grants no rights in the original work of Sony
  Computer Entertainment, Clap Hanz or anyone else in *Hot Shots Tennis: Get a Grip*. The sources reconstruct a
  copyrighted program; they are provided for research, preservation and interoperability, and you need your own
  legally obtained copy of the game.
- Third-party code is under its own terms: the newlib-derived sources keep newlib's notices (each file's licence is
  recorded in `REUSE.toml`, the texts are `LicenseRef-Newlib-*` in `LICENSES/`), and the tools that are needed but not
  included have their vendors' licences. See [THIRD_PARTY.md](THIRD_PARTY.md) and [`REUSE.toml`](REUSE.toml).
  `wip/ieee754_powf_00008544.c` reconstructs newlib's `ef_pow.c` and carries Sun's fdlibm notice as well as the GPL.
- Sony SDK and system-library reconstructions are kept out of public releases (see
  [Origin classes and the publish filter](#origin-classes-and-the-publish-filter)).
- This is not legal advice.
