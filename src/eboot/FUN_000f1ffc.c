/* HSTMATCH module=EBOOT.BIN start=0x000f1ffc end=0x000f2024 symbol=FUN_000f1ffc lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64b); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_001031e8();

void FUN_000f1ffc(int param_1)
{
  if (*(u8 *)(param_1 + 0x78) == '\0') {
    FUN_001031e8();
  }
}
