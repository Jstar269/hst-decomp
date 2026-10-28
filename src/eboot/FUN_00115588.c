/* HSTMATCH module=EBOOT.BIN start=0x00115588 end=0x001155c0 symbol=FUN_00115588 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_001031e8();

void FUN_00115588(int param_1)
{
  if (((*(u32 *)(param_1 + 0x6c) & 8) == 0) || (*(int *)(param_1 + 0x88) < 1)) {
    FUN_001031e8();
  }
}
