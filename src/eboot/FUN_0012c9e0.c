/* HSTMATCH module=EBOOT.BIN start=0x0012c9e0 end=0x0012c9e8 symbol=FUN_0012c9e0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag u1ge); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_0012c9e0(int param_1,u32 param_2)
{
  *(u32 *)(param_1 + 0x330) = param_2;
}
