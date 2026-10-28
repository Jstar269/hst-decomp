<div align="center">

<picture>
  <source media="(prefers-color-scheme: dark)" srcset="docs/images/brand/hst-decomp-mark-dark.svg">
  <img src="docs/images/brand/hst-decomp-mark-light.svg" width="96" height="96" alt="hst-decomp mark">
</picture>

# Hot Shots Tennis: Get a Grip — matching decompilation

**C and C++ that compiles back to the exact bytes of the PSP game, one function at a time.**

A Nakagawa project, alongside [Nakagawa Recomp](https://github.com/Jstar269/nakagawa-recomp), the PSP-to-native recompiler and player.

[![Code matched](https://img.shields.io/badge/dynamic/json?url=https%3A%2F%2Fraw.githubusercontent.com%2FJstar269%2Fhst-decomp%2Fmain%2Fdocs%2Fobjdiff-report.json&query=%24.measures.matched_code_percent&suffix=%25&label=code%20matched&color=6E9600)](#progress-at-a-glance)
[![License: GPL-3.0-or-later](https://img.shields.io/badge/license-GPL--3.0--or--later-blue.svg)](#license)
[![REUSE status](https://api.reuse.software/badge/github.com/Jstar269/hst-decomp)](https://api.reuse.software/info/github.com/Jstar269/hst-decomp)
[![Platform: PSP (UCUS98701)](https://img.shields.io/badge/PSP-UCUS98701-555555.svg)](#what-is-this)

</div>

## What is this?

A PSP game ships as machine code: instructions for the console's processor, not readable source. This project
rebuilds that code as C and C++, the kind of source the developers originally wrote, for *Hot Shots Tennis: Get a
Grip* (PlayStation Portable, UCUS98701), also known as *Everybody's Tennis Portable*.

"Matching" means every rebuilt function is proven: compiled with the same compiler the developers used, it produces
exactly the same bytes as the original game. A function that doesn't match yet isn't counted.

The game has two program files, and this project rebuilds both: the main game (`EBOOT.BIN`) and the Sharing Version
(`hstp_trans_main.prx`), the trial copy of the game that one PSP sends to a friend's PSP over wireless Game Sharing.

Why it matters: readable source lets people study how the game works, fix bugs, and run it natively on other
systems. Nakagawa Recomp can already start the game on Windows from its original code, and the decompiled source
will let more of it run as real, readable code over time.

## Progress at a glance

<!-- hstprogress:begin readme-glance -->

| | Progress | What it means |
|---|---|---|
| **Code matched** | **36.2%** | 12,334 of the 19,634 game functions are rewritten as C or C++ that compiles to the game's exact bytes. This is the figure decompilation trackers such as [recomp.fyi](https://recomp.fyi) show. |
| **Built from source** | **29.4%** | The share of the game's program files that the full build already reproduces, byte for byte, from this source. |

The project's own finish line is stricter: the whole build must also work when moved to another address, and every source must be reviewed by a person. That figure is 0.0%. Measured 2026-10-28.

<!-- hstprogress:end -->

Decompilation projects usually count a game as done when both numbers reach 100%. More detail, charts and history:
[Progress report](docs/PROGRESS.md).

## See it running

[Nakagawa Recomp](https://github.com/Jstar269/nakagawa-recomp) runs the game's own PSP code natively on Windows.
This presentation capture shows the title screen in that build. It is the only game imagery in this repository; the
logo, artwork and on-screen text belong to their owners, are shown only to identify the game, and are not covered by
this project's licences.

![Title screen of Hot Shots Tennis: Get a Grip running natively in Nakagawa Recomp](docs/media/hst-title-screen.png)

<div align="center"><sub>Hot Shots Tennis: Get a Grip belongs to its publisher. This repository contains no game data: you need your own copy of the game, and nothing here downloads one.</sub></div>

## Can I play it?

Not from this repository: it holds source code only, with no game files, and doesn't build a playable game on its
own. To play on a PC, use [Nakagawa Recomp](https://github.com/Jstar269/nakagawa-recomp) with your own copy of the
game.

## How is it made?

Mostly by machines, and every result is checked by machines.

- **Tools** produce most of the sources. Where the game contains the same code more than once, a tool reuses a
  function that already matches; other tools translate decompiler output into C.
- **AI agents** take on the functions those tools can't match, under the maintainer's direction.
- **Nothing is accepted on trust.** A function is accepted only when an automatic checker compiles it with the
  original compiler and proves it produces exactly the original bytes, and a second gate rejects fake matches, such
  as machine code pasted in as assembly instead of written as C. A source that fails either check isn't counted,
  whoever or whatever wrote it.

How the sources break down, by the way they were made: [What the sources are](docs/GUIDE.md#what-the-sources-are).

## How can I follow along?

The repository isn't open to outside contributions yet ([CONTRIBUTING.md](CONTRIBUTING.md)). You can still follow
the progress, and check every published match for yourself.

Matching a function is a puzzle: you write C until the compiler's output equals the original bytes exactly. To
re-check the published matches on your own machine:

1. Bring your own copy of the game. The tools need its two executables in decrypted form; this repository contains
   no decryption code and does not explain how to decrypt them.
2. Install the compilers in WSL and set up the campaign directory: [Setup](docs/GUIDE.md#setup).
3. Check that everything matches: `python tools/hstmatch.py --all`.

How a function is matched is described in [CONTRIBUTING.md](CONTRIBUTING.md), and the compiler lessons are in
[`docs/MWCC-NOTES.md`](docs/MWCC-NOTES.md).

## Progress in detail

<!-- hstprogress:begin readme-progress -->

**12,331 exact sources** (12,334 functions) and 1,045 near misses, measured 2026-10-28 with `python tools/hstcov.py`
and counted in code bytes:

| Module | Matched / functions | Matched / code bytes | Share of bytes |
|---|---|---|---|
| `EBOOT.BIN` | 6,269 / 9,804 | 1,081,440 / 2,849,076 | 37.958 % |
| `hstp_trans_main.prx` (Sharing Version) | 6,065 / 9,830 | 1,002,888 / 2,914,004 | 34.416 % |
| **Both** | 12,334 / 19,634 | 2,084,328 / 5,763,080 | 36.167 % |

<!-- hstprogress:end -->

The Sharing Version is the Game Sharing trial copy described in [What is this?](#what-is-this). Every source is
re-verified with `python tools/hstmatch.py` before it is published. These figures count each function matched on its
own. The stricter tiers (the whole executables rebuilt from source, data included, relocatable and reviewed) are
defined in [`docs/COMPLETION.md`](docs/COMPLETION.md), and [`docs/PROGRESS.md`](docs/PROGRESS.md) charts them.

## Legal

No game assets, executables, keys, decryption code or compilers are in this repository, except the presentation
screenshot described above, and nothing in it lets you obtain the game. You install the compilers yourself from
[decomp.me's kits](https://github.com/decompme/compilers) and [wibo](https://github.com/decompals/wibo), under their
vendors' licences ([THIRD_PARTY.md](THIRD_PARTY.md)).

This is an unofficial fan project, not affiliated with or endorsed by Sony Interactive Entertainment or Clap Hanz.
Hot Shots Tennis, Everybody's Tennis, PlayStation and PSP are trademarks of Sony Interactive Entertainment Inc. or its
affiliates, used here only to identify the game and platform.

Rights holders with a concern about anything in this repository can contact the maintainer privately through
[GitHub private reporting](https://github.com/Jstar269/hst-decomp/security/advisories/new) or the contact on the
[maintainer's profile](https://github.com/Jstar269). We aim to respond promptly and will remove material where
appropriate.

## License

Licensed by path ([REUSE](https://reuse.software/)): the reconstructed code (`src/`, `wip/`, `symbols/`) is
**GPL-3.0-or-later**, the tools and docs are **MIT** (except the title-screen image, which belongs to its owners), and newlib-derived code
keeps its own notices. The GPL covers
only the project's own work, not the original game. Sony SDK reconstructions are not published here. Full table:
[Licensing](docs/GUIDE.md#licensing).

## Learn more

[Progress report](docs/PROGRESS.md) · [Project guide](docs/GUIDE.md) · [Contributing](CONTRIBUTING.md) ·
[Compiler notes](docs/MWCC-NOTES.md) · [Security](SECURITY.md) · [Code of conduct](CODE_OF_CONDUCT.md) ·
[Nakagawa Recomp](https://github.com/Jstar269/nakagawa-recomp)
