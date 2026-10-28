/* HSTMATCH module=hstp_trans_main.prx start=0x0005360c end=0x000536b4 symbol=FUN_0005360c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002cc260;
extern u32 DAT_003d44bc;
extern u32 * FUN_00036cd0();
extern u32 * FUN_00037324();
extern u32 * FUN_00053588();

void FUN_0005360c(int param_1)
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
}
