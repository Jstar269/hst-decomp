/* HSTMATCH module=EBOOT.BIN start=0x00255cf8 end=0x00255d34 symbol=FUN_00255cf8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_00255cf8(int param_1,int param_2,int param_3,u32 param_4)
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + param_2 * 0xa4 + param_3 * 4);
  if (iVar1 != 0) {
    *(u32 *)(iVar1 + 0x24) = param_4;
    *(u32 *)(iVar1 + 0x28) = param_4;
  }
}
