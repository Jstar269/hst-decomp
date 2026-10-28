/* HSTMATCH module=EBOOT.BIN start=0x00186d64 end=0x00186d7c symbol=FUN_00186d64 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_0010b980();

void FUN_00186d64(int param_1,int param_2,int param_3,int param_4)
{
  FUN_0010b980(*(u32 *)(param_1 + 0x285c),param_2 + (param_3 - param_4) * 4,0);
}
