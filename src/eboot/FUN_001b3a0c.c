/* HSTMATCH module=EBOOT.BIN start=0x001b3a0c end=0x001b3b34 symbol=FUN_001b3a0c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: combined the range and slot-present tests and stored the incoming mode value; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_00062418();
extern void FUN_001b0ef8();

void FUN_001b3a0c(int *param_1,int param_2,int param_3)
{
  int bVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  iVar3 = *param_1;
  if ((*(int *)(iVar3 + 0x7a4) >= 0) && (param_3 != 0)) {
    iVar2 = *(int *)(iVar3 + 0x7a4) + 0x28;
    bVar1 = (iVar2 < 0x1da) && (*(int *)(iVar3 + iVar2 * 4) != 0);
    if (bVar1) {
      piVar4 = (int *)(iVar3 + iVar2 * 4);
      iVar2 = *piVar4;
      if (iVar2 != 0) {
        FUN_00062418(iVar2,1);
        *piVar4 = 0;
      }
    }
  }
  FUN_001b0ef8(iVar3,param_2 + 0x28,param_3,0,0);
  FUN_001b0ef8(iVar3,param_2 + 0x84,0,0,0);
  if (param_2 == 6) {
    FUN_001b0ef8(iVar3,0x81,0,0,0);
    *(u32 *)(iVar3 + 0x7a4) = param_2;
  }
  else {
    FUN_001b0ef8(iVar3,param_2 * 2 + 0x98,0,0,0);
    FUN_001b0ef8(iVar3,param_2 * 2 + 0x99,0,0,0);
    *(int *)(iVar3 + 0x7a4) = param_2;
  }
}
