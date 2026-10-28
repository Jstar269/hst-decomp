/* HSTMATCH module=hstp_trans_main.prx start=0x000655ac end=0x0006562c symbol=FUN_000655ac lang=c99 */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: moved the common parent-flag load after the optional child update; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_000655ac(u32 param_1,u32 *param_2)
{
  u32 uVar1;
  u32 *puVar2;
  u32 *puVar3;
  
  puVar3 = *(u32 **)(param_1 + 4);
  if (*param_2 == param_1) {
    *param_2 = (u32)puVar3;
  }
  *(u32 *)(param_1 + 4) = *puVar3;
  uVar1 = *puVar3;
  if (uVar1 != 0) {
    *(u32 *)(uVar1 + 8) = param_1 | *(u32 *)(uVar1 + 8) & 1;
  }
  uVar1 = puVar3[2];
  puVar3[2] = *(u32 *)(param_1 + 8) & 0xfffffffe | uVar1 & 1;
  puVar2 = (u32 *)(*(u32 *)(param_1 + 8) & 0xfffffffe);
  if (param_1 == *puVar2) {
    *puVar2 = (u32)puVar3;
  }
  else {
    puVar2[1] = (u32)puVar3;
  }
  *puVar3 = param_1;
  *(u32 *)(param_1 + 8) = (u32)puVar3 | *(u32 *)(param_1 + 8) & 1;
}
