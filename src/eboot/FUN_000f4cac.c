/* HSTMATCH module=EBOOT.BIN start=0x000f4cac end=0x000f4cf0 symbol=FUN_000f4cac lang=c99 */
/* Clone of src/sharing_main/FUN_000fa3a0.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_000f4cac(int param_1)
{
  u32 uVar2;
  int iVar1;
  
  uVar2 = *(u32 *)(*(int *)(0x168 + param_1) + 0x24);
  iVar1 = *(int *)(param_1 + 0x160);
  *(u32 *)(iVar1 + 0x24) = uVar2;
  *(u32 *)(iVar1 + 0x28) = uVar2;
  *(u32 *)(param_1 + 0x208) = *(u32 *)(*(int *)(param_1 + 0x168) + 0x24);
  uVar2 = *(u32 *)(*(int *)(param_1 + 0x16c) + 0x24);
  iVar1 = *(int *)(0x164 + param_1);
  *(u32 *)(iVar1 + 0x24) = uVar2;
  *(u32 *)(iVar1 + 0x28) = uVar2;
  *(u32 *)(param_1 + 0x20c) = *(u32 *)(*(int *)(param_1 + 0x16c) + 0x24);
}
