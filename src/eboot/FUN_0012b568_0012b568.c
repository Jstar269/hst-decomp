/* HSTMATCH module=EBOOT.BIN start=0x0012b568 end=0x0012b678 symbol=FUN_0012b568 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: restored signed arithmetic and typed helper/global values; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int DAT_0033b4b0;
extern int DAT_0033b4b4;
extern int FUN_0012b72c(int,u32,int);

u32 FUN_0012b568(int param_1)
{
  int iVar1;
  u32 uVar2;
  int iVar3;
  int uVar5;
  u32 uVar4;
  
  iVar1 = FUN_0012b72c(param_1,*(u32 *)(param_1 + 0x35c),0);
  iVar3 = *(int *)(param_1 + 0x334);
  uVar5 = *(u32 *)(param_1 + 0x354);
  uVar4 = 0xffffffff;
  if (iVar3 >= 0 && iVar3 <= DAT_0033b4b4) {
    uVar2 = iVar3 - DAT_0033b4b0;
    iVar1 = (int)uVar2 / 2;
    uVar5 = (int)uVar2 % 2;
  }
  if ((iVar1 == 0) && (uVar5 == 0)) {
    uVar4 = 7;
  }
  else if ((iVar1 == 0) && (uVar5 == 1)) {
    uVar4 = 4;
  }
  else if ((iVar1 == 3) && (uVar5 == 1)) {
    uVar4 = 10;
  }
  else if ((iVar1 == 4) && (uVar5 == 0)) {
    uVar4 = 4;
  }
  else if ((iVar1 == 5) && (uVar5 == 1)) {
    uVar4 = 0xd;
  }
  return uVar4;
}
