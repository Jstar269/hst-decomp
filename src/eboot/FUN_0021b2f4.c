/* HSTMATCH module=EBOOT.BIN start=0x0021b2f4 end=0x0021b328 symbol=FUN_0021b2f4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64b); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_001031e8();

void FUN_0021b2f4(int param_1)
{
  if ((0 < *(int *)(param_1 + 0x8c)) && (*(u8 *)(param_1 + 0x5c) == '\0')) {
    FUN_001031e8();
  }
}
