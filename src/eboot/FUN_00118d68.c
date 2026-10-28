/* HSTMATCH module=EBOOT.BIN start=0x00118d68 end=0x00118d70 symbol=FUN_00118d68 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_0011d0ac();

void FUN_00118d68(u32 param_1,int param_2)
{
  FUN_0011d0ac(param_1,param_2,*(u32 *)(param_2 + 0x14));
}
