/* HSTMATCH module=hstp_trans_main.prx start=0x000fa3a0 end=0x000fa3e4 symbol=FUN_000fa3a0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag p3), refined by hstperm.py random mutation from try/gen-sh128a/v0/FUN_000fa3a0.c; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_000fa3a0(int param_1)
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
