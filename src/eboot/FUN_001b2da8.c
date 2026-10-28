/* HSTMATCH module=EBOOT.BIN start=0x001b2da8 end=0x001b2de8 symbol=FUN_001b2da8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_00062418();

void FUN_001b2da8(int *param_1)
{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1;
  iVar1 = *(int *)(iVar2 + 0x2c0);
  if ((iVar1 != 0) && (iVar1 != 0)) {
    FUN_00062418(iVar1,1);
    *(u32 *)(iVar2 + 0x2c0) = 0;
  }
}
