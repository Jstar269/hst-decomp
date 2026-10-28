/* HSTMATCH module=EBOOT.BIN start=0x001903b8 end=0x001903e8 symbol=FUN_001903b8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 * FUN_001903e8();

int FUN_001903b8(int param_1)
{
  FUN_001903e8();
  *(u32 *)(param_1 + 0x10) = 0;
  *(u32 *)(param_1 + 0x14) = 0;
  return param_1;
}
