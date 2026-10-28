/* HSTMATCH module=EBOOT.BIN start=0x00266d04 end=0x00266d0c symbol=FUN_00266d04 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag u1ge); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_00266d04(int param_1,u32 param_2)
{
  *(u32 *)(param_1 + 0x1f8) = param_2;
}
