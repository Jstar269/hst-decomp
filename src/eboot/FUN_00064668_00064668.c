/* HSTMATCH module=EBOOT.BIN start=0x00064668 end=0x000646e8 symbol=FUN_00064668 lang=c99 */
/* Clone of src/sharing_main/FUN_0006552c_0006552c.c (hstclone.py tag u5cr2e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: moved the common parent-flag load after the optional child update; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_00064668(u32 *param_1,u32 *param_2)
{
  u32 uVar1;
  int iVar2;
  u32 *puVar3;
  u32 uVar4;
  
  uVar4 = *param_1;
  if ((u32 *)*param_2 == param_1) {
    *param_2 = uVar4;
  }
  *param_1 = *(u32 *)(uVar4 + 4);
  iVar2 = *(int *)(uVar4 + 4);
  if (iVar2 != 0) {
    *(u32 *)(iVar2 + 8) = (u32)param_1 | *(u32 *)(iVar2 + 8) & 1;
  }
  uVar1 = *(u32 *)(uVar4 + 8);
  *(u32 *)(uVar4 + 8) = param_1[2] & 0xfffffffe | uVar1 & 1;
  puVar3 = (u32 *)(param_1[2] & 0xfffffffe);
  if (param_1 == (u32 *)*puVar3) {
    *puVar3 = uVar4;
  }
  else {
    puVar3[1] = uVar4;
  }
  *(u32 **)(uVar4 + 4) = param_1;
  param_1[2] = uVar4 | param_1[2] & 1;
}
