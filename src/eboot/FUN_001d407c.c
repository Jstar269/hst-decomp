/* HSTMATCH module=EBOOT.BIN start=0x001d407c end=0x001d4088 symbol=FUN_001d407c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_001d407c(int param_1,u32 param_2)
{
  *(u32 *)(param_1 + 0x24) = param_2;
  *(u32 *)(param_1 + 0x28) = param_2;
}
