/* HSTMATCH module=EBOOT.BIN start=0x00118384 end=0x001183b4 symbol=FUN_00118384 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 * FUN_001183b4();

int FUN_00118384(int param_1)
{
  FUN_001183b4();
  *(u32 *)(param_1 + 0x10) = 0;
  *(u32 *)(param_1 + 0x14) = 0;
  return param_1;
}
