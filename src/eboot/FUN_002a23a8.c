/* HSTMATCH module=EBOOT.BIN start=0x002a23a8 end=0x002a23d8 symbol=FUN_002a23a8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_002a1f60();

void FUN_002a23a8(int param_1)
{
  if (*(int *)(param_1 + 0x1b0) == 5) {
    FUN_002a1f60(*(u32 *)(param_1 + 0x1d0),0);
  }
}
