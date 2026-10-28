/* HSTMATCH module=EBOOT.BIN start=0x001f4d44 end=0x001f4df0 symbol=FUN_001f4d44 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag not recorded in lane candidate inputs/generated/FUN_001f4d44.c) corrected by hand: inverted the likely-branch field test and ordered the locals to match the loop counter and cursor registers; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002c8f0c;
extern u8 * DAT_003386b0;
extern int FUN_001b5764();

void FUN_001f4d44(int param_1)
{
  int iVar4;
  int iVar3;
  int iVar2;
  int iVar1;
  
  iVar3 = 0;
  iVar4 = *(int *)(DAT_003386b0 + 0xa8);
  iVar2 = param_1;
  do {
    if (*(int *)(iVar2 + 0x3a0) != 0) {
      iVar1 = *(int *)(*(int *)(iVar2 + 0x3a0) + 0x58);
    } else {
      iVar1 = 0;
    }
    if (((iVar1 != 0) && (iVar4 != 0)) && (iVar3 == *(int *)(param_1 + 0x3cc))) {
      FUN_001b5764(iVar4,iVar3,*(u32 *)(&DAT_002c8f0c + *(int *)(param_1 + 0x524) * 4));
    }
    iVar3 = iVar3 + 1;
    iVar2 = iVar2 + 4;
  } while (iVar3 < 4);
}
