/* HSTMATCH module=hstp_trans_main.prx start=0x001369d4 end=0x00136ae4 symbol=FUN_001369d4 lang=c99 */
/* Clone of src/eboot/FUN_0012b568_0012b568.c (hstclone.py tag u3r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: restored signed arithmetic and typed helper/global values; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int DAT_003e47f0;
extern int DAT_003e47f4;
extern int FUN_00136b98(int,u32,int);

u32 FUN_001369d4(int param_1)
{
  int iVar1;
  u32 uVar2;
  int iVar3;
  int uVar5;
  u32 uVar4;
  
  iVar1 = FUN_00136b98(param_1,*(u32 *)(param_1 + 0x35c),0);
  iVar3 = *(int *)(param_1 + 0x334);
  uVar5 = *(u32 *)(param_1 + 0x354);
  uVar4 = 0xffffffff;
  if (iVar3 >= 0 && iVar3 <= DAT_003e47f4) {
    uVar2 = iVar3 - DAT_003e47f0;
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
