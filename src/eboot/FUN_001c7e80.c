/* HSTMATCH module=EBOOT.BIN start=0x001c7e80 end=0x001c7e8c symbol=FUN_001c7e80 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_001c7e80(int param_1,u32 param_2,u32 param_3)
{
  *(u32 *)(param_1 + 0x14c) = param_2;
  *(u32 *)(param_1 + 0x150) = param_3;
}
