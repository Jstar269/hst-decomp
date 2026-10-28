/* HSTMATCH module=EBOOT.BIN start=0x001d6aa0 end=0x001d6ab0 symbol=FUN_001d6aa0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00103628();

void FUN_001d6aa0(int param_1)
{
  *(u8 *)(param_1 + 0x54) = 0;
  *(u8 *)(param_1 + 0x55) = 0;
  FUN_00103628(param_1,1);
}
