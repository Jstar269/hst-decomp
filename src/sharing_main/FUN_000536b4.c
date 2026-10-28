/* HSTMATCH module=hstp_trans_main.prx start=0x000536b4 end=0x000537c8 symbol=FUN_000536b4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002cc260;
extern u32 DAT_003d44bc;
extern u32 * FUN_0003697c();
extern u32 * FUN_00036cd0();
extern u32 * FUN_00037324();
extern u32 * FUN_00053504();
extern u32 * FUN_00053588();

void FUN_000536b4(int param_1,u32 param_2,u32 param_3,u32 param_4, u32 param_5,u32 param_6,u32 param_7)
{
  u32 uVar1;
  u32 *puVar2;
  int iVar3;
  
  uVar1 = (unsigned int)(FUN_00036cd0(*(u32 *)(param_1 + 0x28),DAT_003d44bc));
  *(u32 *)(param_1 + 0x28) = uVar1;
  puVar2 = (u32 *)FUN_00037324(uVar1,DAT_003d44bc);
  *(u32 **)(param_1 + 0x28) = puVar2;
  *puVar2 = 0x17000000;
  iVar3 = *(int *)(param_1 + 0x28);
  *(int *)(param_1 + 0x28) = iVar3 + 4;
  *(u32 *)(iVar3 + 4) = *(int *)(param_1 + 4) < 0 ^ 1 | 0x1e000000;
  iVar3 = *(int *)(param_1 + 0x28);
  *(int *)(param_1 + 0x28) = iVar3 + 4;
  *(u32 *)(iVar3 + 4) = 0xc0000301;
  iVar3 = *(int *)(param_1 + 0x28) + 4;
  *(int *)(param_1 + 0x28) = iVar3;
  uVar1 = (unsigned int)(FUN_00053588(iVar3,&DAT_002cc260));
  *(u32 *)(param_1 + 0x28) = uVar1;
  uVar1 = (unsigned int)(FUN_00053504(uVar1,param_2));
  *(u32 *)(param_1 + 0x28) = uVar1;
  uVar1 = (unsigned int)(FUN_0003697c(uVar1,param_3,param_4,param_5,0,param_7));
  *(u32 *)(param_1 + 0x28) = uVar1;
}
