# Matching-agent brief (Hot Shots Tennis: Get a Grip decompilation)

This project's matching agents turn retail functions of the PSP game Hot Shots Tennis: Get a Grip into C/C++
sources that compile to the exact retail bytes. Work only as described here.

## Setup
- Workspace: the repository root (when you run as an external lane: your lane directory, a copy of the repository).
  Machine-specific paths are in `hst-config.json` (see `hst-config.example.json`); do not edit it.
  Use the Bash tool with POSIX syntax.
- Your batch file (given in your prompt) lists the functions: address, end, size, `family` (other functions
  with identical code apart from addresses; they are cloned automatically from your match, so you only
  match the listed address), Ghidra pseudocode path (advisory, often wrong in detail), and the best
  mechanically generated candidate if one exists (`best_generated.source`, a good starting point).
- Read `docs/MWCC-DIGEST.md` first (verified compiler behaviour, grouped by topic; it covers the first 245
  lines of the log), then only the newer log lines: `tail -n +246 docs/MWCC-NOTES.md`. Search the full
  log (`grep`) only when you need the original wording of a finding.
- Put ALL experiments under your own directory `try/agent-<your batch name>/` (build artifacts go to
  `build/<module>/<parent-dir-name>__<file-stem>`, so a unique directory avoids collisions with others).

## Tools
- `python tools/hstmatch.py <files...>` compiles (mwccpsp 3.0.1 build 219 under wibo/WSL, fixed flags
  `-c -O4,p -sdatathreshold 0`), links at the retail address and compares: EXACT / MISMATCH (with differing
  word count) / COMPILE_FAILED (compiler log) / MISSING_SYMBOLS / UNPLACED_SECTION / SECTION_MISMATCH.
  Use `--parallel 4` at most. `--flags` and header `extra=` are experiments only and never count.
- `python tools/hstdiff.py <file>` (after hstmatch) prints our disassembly next to retail's.
- `python tools/hstdis.py 0xADDR` prints retail disassembly of any reviewed function (callees too).
- Every source starts with a header line, e.g.
  `/* HSTMATCH module=EBOOT.BIN start=0x0011d894 end=0x0011dad8 symbol=FUN_0011d894 lang=c++ */`
  (`lang=c99` for C). `symbol` must be the name your source defines for the function.
- External references: address-named symbols (`FUN_xxxxxxxx`, `DAT_xxxxxxxx` with 8 hex digits) link at
  their address automatically; other names must be in `symbols/<module>.txt` (C++ runtime and vtables).
  If a match needs a NEW named symbol (a vtable `__vt__…`, a runtime helper, a mangled member name), verify its
  address in the disassembly, check the name is not already in the file (`grep`), and APPEND one line with
  `printf '%s\n' 'name = 0xADDR;   # <your src file> (agent)' >> symbols/<module>.txt`. Never edit or remove
  existing lines. List every symbol you added in your report.
- A function whose constants or jump table sit in .rodata needs `rodata=0xADDR` in the header (the address
  retail's lui/lo pair loads); hstmatch then also requires the placed bytes to equal retail.

## GCC (SDK) functions
Most game code is MWCC, but Sony SDK objects (most of EBOOT below 0x88000, some runs higher such as
0x2996xx) are GCC 3.3.3 output: ra saved at the frame top before s-registers, t-register temporaries,
movn/movz, `j` between blocks. Match those with header key `cc=gcc171-O2` or `cc=gcc171-Os` (also
`-O1`/`-O3`, and `gcc131-*` for the older Sony build); everything else (symbols, rodata=, checks) is the same.
Plain C, no MWCC pragmas. Retail `ext` without `ins rd,$zero` may match the `gcc171x-*` (`-mext`) profiles;
functions using `ins rd,$zero,...` need a newer Sony GCC we do not have: note them and move on.
Sony SDK reconstructions are kept out of public releases (newlib functions are published); this does not change how
agents match them.

## Method (per function)
1. `hstdis.py` the address; read the pseudocode; look at callees/callers (`hstdis.py` them) for types.
2. Start from `best_generated.source` (copy it into your directory) or write the function by hand; prefer
   natural C++ (structs with fields, member functions, loops with break) over Ghidra's pointer arithmetic.
3. Iterate with hstmatch + hstdiff. Budget about 40 compiles per function; when stuck, move on and come back
   at the end if budget remains.

## Source quality (the owner reviews every source at the end; aim for the code the developers wrote)
- Among exact variants, keep the most natural one: real control flow (loops, early returns, switch), structs
  and member access instead of `*(int *)(p + 0x14)` when the layout is clear, `bool`/enums where obvious.
- Avoid matching hacks: duplicated conditions, dummy locals or parameters that only steer register
  allocation, `volatile`, self-assignments, gratuitous casts or `goto`. When one is the ONLY exact form you
  found, keep it but name it in the note line ("matching idiom: <what>").
- Names: use a descriptive name only when the evidence supports it (strings, callers, documented
  research findings); otherwise keep the Ghidra address names. Never invent semantics.
- Note lines must be true: say "hand-written" only when you wrote it, name the generator tag you started from.

## When a function is EXACT
- Check nobody else covered it: `grep -l "start=0x<addr>" src/*/* wip/*` must find nothing (other than
  your own files). If found, keep theirs and move on.
- Write it to `src/eboot/` (EBOOT.BIN) or `src/sharing_main/` (hstp_trans_main.prx) as
  `<short_descriptive_name>_<addr8>.cpp` (or `.c`), and put exactly one of these as the second line:
  - written from scratch or heavily restructured:
    `/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */`
  - derived from a generated candidate with small corrections:
    `/* Ghidra pseudocode (hstgen.py tag <tag from the candidate path, e.g. s128a>) corrected by hand: <what you changed>; exact match verified; names and types await human review. */`
- Re-run hstmatch on the file in src/ and confirm EXACT.
- If it taught you something new about the compiler, append ONE dated line to `docs/MWCC-NOTES.md` with
  `cat >> docs/MWCC-NOTES.md <<'EOF' ... EOF` (never rewrite the file), naming the function address.

## Same-file static helpers (multi-function sources)
If retail's code depends on a `static` helper compiled EARLIER in the same file (e.g. MWCC keeping a0 live
across a call it knows preserves a0), match the whole contiguous run of retail functions from the helper
to your target in ONE source: header `start=` is the first function's start, `end=` the last function's
end, `symbol=` the first function; define the functions in address order. hstmatch then compares the whole
range. Name such files `<name>_<first addr8>_run.cpp` and say so in the note line.

## Helpers outside your batch
If you match other functions along the way (out-of-line helpers, callees), install them exactly like batch
functions (same checks, same note lines) and list them in your report.

## Near misses
If a function ends within ~6 differing words but not exact, save your best source to
`wip/<short_name>_<addr8>.cpp` (same header) with trailing `//` comments: what differs and what you ruled out.

## Never
- Touch anything outside your try directory, the src/wip files you create, appends to MWCC-NOTES.md, and
  symbol-file appends as described above.
- Edit `tools/`, edit or delete existing lines in `symbols/` (appending as described above is allowed), anything under `<campaign_root>` (the campaign directory named in `hst-config.json`), ledgers, or key files; use git;
  access the network; send retail bytes or disassembly to any external service.
- Run tools/hstgen.py, hstperm.py, hstclone.py, hsttmpl.py or hstqueue.py (the main session runs them).
- Search recursively outside `src/`, `wip/`, `docs/`, `symbols/`, `include/` and your own try directory
  (other trees hold multi-GB ledgers and logs).

## Report (concise)
Per function: EXACT (file name) / near miss (wip file, words left) / not matched (one-line reason). Then the
new compiler insights you appended.
