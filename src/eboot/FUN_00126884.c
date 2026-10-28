/* HSTMATCH module=EBOOT.BIN start=0x00126884 end=0x001268b8 symbol=FUN_00126884 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 FUN_000ff678();

void FUN_00126884(int param_1,u32 param_2,u32 *param_3)
{
  u32 uVar1;
  
  uVar1 = FUN_000ff678(*(u32 *)(param_1 + 0x1c),param_2,*param_3,0);
  *param_3 = uVar1;
}
