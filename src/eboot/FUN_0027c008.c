/* HSTMATCH module=EBOOT.BIN start=0x0027c008 end=0x0027c018 symbol=FUN_0027c008 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_0027c008(int param_1)
{
  *(u32 *)(param_1 + 0x78) = 0xffffffff;
  *(u32 *)(param_1 + 0x7c) = 0xffffffff;
}
