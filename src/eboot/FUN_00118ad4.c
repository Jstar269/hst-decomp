/* HSTMATCH module=EBOOT.BIN start=0x00118ad4 end=0x00118adc symbol=FUN_00118ad4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_0011d314();

void FUN_00118ad4(u32 param_1,int param_2)
{
  FUN_0011d314(param_1,param_2,*(u32 *)(param_2 + 0x14));
}
