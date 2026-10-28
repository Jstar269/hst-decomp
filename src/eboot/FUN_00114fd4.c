/* HSTMATCH module=EBOOT.BIN start=0x00114fd4 end=0x00114fdc symbol=FUN_00114fd4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_00114fd4(int param_1,u32 param_2)
{
  *(u32 *)(param_1 + 0xd0) = param_2;
}
