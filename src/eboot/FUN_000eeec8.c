/* HSTMATCH module=EBOOT.BIN start=0x000eeec8 end=0x000eeef4 symbol=FUN_000eeec8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00103628();

void FUN_000eeec8(int param_1)
{
  FUN_00103628(param_1,0);
  *(u8 *)(param_1 + 0x54) = 0;
}
