/* HSTMATCH module=EBOOT.BIN start=0x00278f7c end=0x00279138 symbol=FUN_00278f7c lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Ghidra pseudocode corrected by hand: used a signed divisor and positive loop bound to reproduce retail digit extraction; exact match verified; names and types await human review. */
#include "hst/types.h"

extern char DAT_002fe59c[];
extern void FUN_000143b0(void *, void *, int);
extern void FUN_000ffb3c(int, int);
extern int FUN_001026b8(int, void *);

void FUN_00278f7c(int param_1,int param_2,u8 param_3)
{
  bool bVar1;
  u32 uVar2;
  int iVar3;
  int iVar4;
  int divisor;
  int iVar6;
  u8 auStack_40 [64];
  u8 auStack_80 [64];
  
  if (param_3 == '\0') {
    iVar4 = 7;
    do {
      FUN_000143b0(auStack_40,DAT_002fe59c,iVar4);
      uVar2 = FUN_001026b8(*(u32 *)(param_1 + 0x488),auStack_40);
      FUN_000ffb3c(uVar2,1);
      iVar4 = iVar4 + 1;
    } while (iVar4 < 0xe);
  }
  else {
    bVar1 = false;
    divisor = 1000000;
    iVar4 = 7;
    do {
      iVar6 = param_2 / divisor;
      if (iVar6 != 0) {
        bVar1 = true;
      }
      if (bVar1) {
        FUN_000143b0(auStack_80,DAT_002fe59c,iVar4);
        iVar3 = FUN_001026b8(*(u32 *)(param_1 + 0x488),auStack_80);
        *(int *)(iVar3 + 0x24) = *(int *)(iVar3 + 0x28) + iVar6;
        uVar2 = FUN_001026b8(*(u32 *)(param_1 + 0x488),auStack_80);
        FUN_000ffb3c(uVar2,0);
      }
      else if (divisor == 1) {
        FUN_000143b0(auStack_80,DAT_002fe59c,iVar4);
        iVar3 = FUN_001026b8(*(u32 *)(param_1 + 0x488),auStack_80);
        *(u32 *)(iVar3 + 0x24) = *(u32 *)(iVar3 + 0x28);
        uVar2 = FUN_001026b8(*(u32 *)(param_1 + 0x488),auStack_80);
        FUN_000ffb3c(uVar2,0);
      }
      else {
        FUN_000143b0(auStack_80,DAT_002fe59c,iVar4);
        uVar2 = FUN_001026b8(*(u32 *)(param_1 + 0x488),auStack_80);
        FUN_000ffb3c(uVar2,1);
      }
      param_2 = param_2 - iVar6 * divisor;
      divisor = divisor / 10;
      iVar4 = iVar4 + 1;
    } while (divisor > 0);
  }
}
