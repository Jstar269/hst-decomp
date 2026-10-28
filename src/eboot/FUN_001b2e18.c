/* HSTMATCH module=EBOOT.BIN start=0x001b2e18 end=0x001b2e78 symbol=FUN_001b2e18 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a1), refined by hstperm.py tag p4 random mutation from try/gen-a1/v0/FUN_001b2e18.c; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_00062418();

void FUN_001b2e18(int *param_1)
{
  int iVar2;
  int iVar1;
  
  iVar2 = *param_1;
  iVar1 = *(int *)(iVar2 + 0x2b0);
  if (iVar1 == 0) {
    iVar1 = *(int *)(iVar2 + 0x2b4);
  }
  else {
    if (iVar1 != 0) {
      FUN_00062418(iVar1,1);
      *(u32 *)(iVar2 + 0x2b0) = 0;
    }
  }
  if (((*(int *)(iVar2 + 0x2b4)) != 0) && ((*(int *)(iVar2 + 0x2b4)) != 0)) {
    FUN_00062418((*(int *)(iVar2 + 0x2b4)),1);
    *(u32 *)(iVar2 + 0x2b4) = 0;
  }
}
