/* HSTMATCH module=EBOOT.BIN start=0x00225d54 end=0x00225d68 symbol=FUN_00225d54 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00220768();

void FUN_00225d54(int param_1,u32 param_2,u32 param_3)
{
  FUN_00220768(*(u32 *)(*(int *)(param_1 + 0x3c) + 0x1c),param_2,1,param_3);
}
