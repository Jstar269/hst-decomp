/* HSTMATCH module=EBOOT.BIN start=0x00250f48 end=0x00250f58 symbol=FUN_00250f48 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_002fbef4;

void FUN_00250f48(int param_1,u32 param_2)
{
  *(u32 *)(param_1 + 0x304) = param_2;
  DAT_002fbef4 = param_2;
}
