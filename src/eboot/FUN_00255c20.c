/* HSTMATCH module=EBOOT.BIN start=0x00255c20 end=0x00255c68 symbol=FUN_00255c20 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_000ffb3c();

void FUN_00255c20(int param_1,int param_2,int param_3,u32 param_4)
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + param_2 * 0xa4 + param_3 * 4);
  if (iVar1 != 0) {
    FUN_000ffb3c(iVar1,param_4);
  }
}
