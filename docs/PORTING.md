# Portable source measurement

`tools/hstport.py` measures whether each reconstructed source in `src/eboot/` and `src/sharing_main/` is accepted by
Clang for Windows x64, Windows x86, Android arm64, Android armv7, and Android x64. It does not change the game
sources. Each translation unit is compiled with `-c` to a temporary object outside the repository; the check does not
link an executable or run it. Unresolved platform functions are therefore outside this measurement.

The source language comes from the HSTMATCH `lang=` field. Legacy headers without that field follow the existing
matcher rule: `.c` is C99 and `.cpp` is C++17. C++17 is fixed so compiler defaults cannot change the result and every
target uses the same language baseline. The `port/include/` overlay comes before the locked PSP headers. Its integer,
pointer, size, varargs, limit, and floating-point types use the selected target's Clang builtins; declaration-only C
library headers let the freestanding compile parse standard calls without supplying a runtime implementation.

## Strict success

A source compiles for a target only when Clang exits zero and none of the fixed portability diagnostics below fires.
The warning groups are promoted to errors. Clang hard errors also fail even when they are outside this fixed list.

| Diagnostic or policy | What it catches |
| --- | --- |
| `int-to-pointer-cast` | Clang catches a non-constant integer-to-pointer cast when the integer type is narrower than the target pointer. Clang may suppress this warning for integer constant expressions, so `numeric-address` handles those separately. |
| `pointer-to-int-cast` | A pointer cast to an integer type narrower than the pointer. |
| `int-conversion` | An implicit incompatible pointer/integer conversion. |
| `incompatible-pointer-types` | Assignments, arguments, or returns using incompatible data pointer types. |
| `implicit-function-declaration` | A C call without a visible function declaration. |
| `implicit-int` | A declaration relying on C's obsolete implicit `int` rule. |
| `return-type` | A non-void function that can fall through without returning a value. |
| `shorten-64-to-32` | Implicit 64-to-32 bit integer narrowing on 64-bit targets only. |
| `pointer-integer-compare` | A comparison between pointer and integer operands. |
| `incompatible-function-pointer-types` | An assignment or argument passing incompatible function pointer types. |
| `numeric-address` | The AST detector finds a non-null integer constant expression converted to a pointer, including a value folded from arithmetic or an enum. It also finds module-range address constants used in pointer conversions or comparisons. |

The shared `tools/hstaddr.py` detector runs once per source with Clang's JSON AST for `x86_64-pc-windows-msvc`,
using that source's language, the same freestanding mode, host header overlay, and include paths as the compile check.
It recognizes C-style, C++ functional, `reinterpret_cast`, and implicit `IntegralToPointer` casts. Null pointer
constants such as `(T *)0` and `NULL` are excluded. The module-range check also catches an address constant inside a
non-constant integer-to-pointer expression or compared with a pointer value converted to an integer. Each finding
contains only its kind, line, and column; there is no source excerpt or numeric value. `hstport` retains a finding
count for every source in each report view and counts a source once under `numeric-address` in the first-failure
census.

Clang's `return-type-c-linkage` subdiagnostic is retained under the required `return-type` gate because it rejects
non-C-compatible return types crossing a C ABI boundary. Hard errors such as operator constraints and duplicate
definitions fail through Clang's exit status; they are reported by normalized reason with no source text. Other
warning groups are omitted from promotion because style, optimization, and target notes do not by themselves prove a
source portability defect; an actual compiler error still fails.

MWCC/MIPS-only constructs fail through a separate source policy even when Clang accepts or ignores them:

- Inline assembly is target instruction text and cannot be shared across these host architectures.
- MIPS register-bound variables name registers that do not exist on the host targets.
- `__attribute__` section assignments encode target-specific object and linker layout.
- MWCC optimization pragmas have no portable Clang semantics and can otherwise be silently ignored.
- MWCC/MIPS intrinsics have no equivalent host compiler contract.

## What the result proves

The run proves that the recorded source translation units pass the listed compiler checks for the named target triples
with the stated overlay and compiler versions. The overlay prevents the PSP headers' 32-bit `intptr_t` and related
typedefs from hiding pointer-width assumptions. The 64-bit targets expose non-constant integer-to-pointer and
pointer-to-integer casts, pointer/integer comparisons, and implicit 64-to-32-bit narrowing; explicit source assertions
about pointer width also evaluate against the target's actual compiler types. The AST detector separately rejects
fixed numeric addresses that the compiler may accept.

The result does not prove a Windows or Android executable can link or run. It does not validate a platform API layer,
PSP imports, runtime behavior, or equivalence to the original game. All five measured targets are little-endian, but
the check does not execute endian-sensitive code. Pointer size, alignment, structure layout, and plain `char`
signedness vary by target and are not compared with the PSP ABI. The platform layer must use fixed-width address and
serialization types, explicit signed or unsigned character types, and target-specific structure/alignment rules
where those differences matter.

## Measurement

The full run used `python tools/hstport.py --parallel 4 --host-clang "C:\Program Files\LLVM\bin\clang.exe" --android-ndk "C:\Users\Jstar\AppData\Local\Android\Sdk\ndk\30.0.16248370"` on 2026-10-21. It analyzed and measured all 11,893 sources for all five targets and took 1,219.979 seconds (20 minutes 19.979 seconds), including 263.697 seconds (4 minutes 23.697 seconds) for the AST numeric-address scan. The detector reported 8,651 findings across 2,451 public sources and 10,092 findings across 3,178 private sources. Public totals omit source origins listed in `tools/hstpublish.py` `EXCLUDED_CLASSES`; in this scope that excludes 1,310 `gcc-unattributed` sources and 58,620 function bytes. Private totals include them.

| View | Sources | Compile all 5 | Code bytes | Compiling bytes | Byte progress |
| --- | ---: | ---: | ---: | ---: | ---: |
| Public | 10,583 | 6,511 | 5,704,460 | 753,868 | 13.215% |
| Private | 11,893 | 6,970 | 5,763,080 | 781,436 | 13.559% |

Per-target source counts are shown as `ok / fail`:

| Target | Public | Private |
| --- | ---: | ---: |
| `x86_64-pc-windows-msvc` | 6,513 / 4,070 | 6,972 / 4,921 |
| `i686-pc-windows-msvc` | 7,562 / 3,021 | 8,096 / 3,797 |
| `aarch64-linux-android24` | 6,564 / 4,019 | 7,023 / 4,870 |
| `armv7a-linux-androideabi24` | 7,558 / 3,025 | 8,092 / 3,801 |
| `x86_64-linux-android24` | 6,564 / 4,019 | 7,023 / 4,870 |

The run used LLVM for the Windows targets and Android NDK r30 for Android:

| Targets | Compiler path | Version |
| --- | --- | --- |
| Windows x64 and x86 | `C:\Program Files\LLVM\bin\clang.exe` | `clang version 23.1.4 (https://github.com/llvm/llvm-project 7a941dfb2877a0b8cf30323fefa85ad019e0b0f5)` |
| Android arm64, armv7, and x64 | `C:\Users\Jstar\AppData\Local\Android\Sdk\ndk\30.0.16248370\toolchains\llvm\prebuilt\windows-x86_64\bin\clang.exe` | `Android (16134705, based on r574158c) clang version 21.0.0 (https://android.googlesource.com/toolchain/llvm-project 9f872551d3c681d06fd303b36f16ed5c274735eb)` |

The first-failure census counts each failing source once, at its first failing target. The complete sanitized reports in
ignored `try/port-report.json` and `try/port-private-report.json` retain each included source's numeric-address
finding count. Clang warning keys retain the emitted flag; `-Werror` reflects promotion.

Public census top ten:

| Census key | Sources | Portable remediation that preserves the PSP match |
| --- | ---: | --- |
| `numeric-address` | 2,451 | Replace the literal with a symbol from `symbols/<module>.txt`; the PSP build links that symbol at its recorded address and host builds receive a relocatable reference. |
| `-Werror,-Wpointer-to-int-cast` | 727 | Convert host pointers through `uintptr_t` and keep explicitly 32-bit PSP address fields at the PSP boundary. |
| `mwcc-pragma` | 449 | Keep the optimization directive in the MWCC PSP build profile or behind an MWCC-only guard. |
| `-Werror,-Wreturn-type-c-linkage` | 103 | Use a C-compatible host adapter at the C-linkage boundary while leaving the PSP C++ path intact. |
| `operator-arity` | 100 | Add a host-only standards-compliant overload adapter that delegates to the existing PSP implementation. |
| `-Werror,-Wint-to-pointer-cast` | 90 | Use `uintptr_t` for runtime integer-to-pointer conversions; name fixed addresses through their module symbols. |
| `duplicate-definition` | 82 | Consolidate duplicate host declarations and retain target-specific PSP definitions behind the existing compiler branch. |
| `-Werror,-Wshorten-64-to-32` | 46 | Make narrowing explicit at the PSP 32-bit address boundary and keep full-width host pointer values. |
| `-Werror,-Wint-to-void-pointer-cast` | 12 | Use `uintptr_t` for runtime conversions and the module symbol for fixed addresses. |
| `-Werror,-Wvoid-pointer-to-int-cast` | 6 | Convert host pointers through `uintptr_t` and narrow only in an explicit PSP address adapter. |

Private census top ten:

| Census key | Sources | Portable remediation that preserves the PSP match |
| --- | ---: | --- |
| `numeric-address` | 3,178 | Replace the literal with a symbol from `symbols/<module>.txt`; the PSP build links that symbol at its recorded address and host builds receive a relocatable reference. |
| `-Werror,-Wpointer-to-int-cast` | 794 | Convert host pointers through `uintptr_t` and keep explicitly 32-bit PSP address fields at the PSP boundary. |
| `mwcc-pragma` | 449 | Keep the optimization directive in the MWCC PSP build profile or behind an MWCC-only guard. |
| `-Werror,-Wreturn-type-c-linkage` | 103 | Use a C-compatible host adapter at the C-linkage boundary while leaving the PSP C++ path intact. |
| `operator-arity` | 100 | Add a host-only standards-compliant overload adapter that delegates to the existing PSP implementation. |
| `-Werror,-Wint-to-pointer-cast` | 98 | Use `uintptr_t` for runtime integer-to-pointer conversions; name fixed addresses through their module symbols. |
| `duplicate-definition` | 82 | Consolidate duplicate host declarations and retain target-specific PSP definitions behind the existing compiler branch. |
| `-Werror,-Wshorten-64-to-32` | 46 | Make narrowing explicit at the PSP 32-bit address boundary and keep full-width host pointer values. |
| `-Wint-conversion` | 44 | Make integer and pointer types explicit at the host API boundary while preserving PSP declarations in the PSP build. |
| `-Werror,-Wint-to-void-pointer-cast` | 12 | Use `uintptr_t` for runtime conversions and the module symbol for fixed addresses. |

The reports are ignored local artifacts and are not part of repository history.
