/* HSTMATCH module=EBOOT.BIN start=0x000ee44c end=0x000ee510 symbol=FUN_000ee44c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag exp-gen3, variant v8) corrected by hand: the hoisted index temporary inlined and the array base written first; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002d6cbc;
extern u8 DAT_002d6cc0;
extern u8 DAT_00338b58;
extern u8 DAT_00338b5c;
extern u8 DAT_00338b60;
extern u8 DAT_00338b64;

void FUN_000ee44c(int param_1,int param_2,int param_3,int param_4,int param_5)
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = param_2 + param_4;
  *(int *)((int)&DAT_00338b58 + param_1 * 0x10) = iVar1 / 2;
  iVar2 = param_3 + param_5;
  *(int *)((int)&DAT_00338b5c + param_1 * 0x10) = iVar2 / 2;
  *(int *)((int)&DAT_00338b60 + param_1 * 0x10) = iVar1 / 2;
  *(int *)((int)&DAT_00338b64 + param_1 * 0x10) = iVar2 / 2;
  *(float *)(&DAT_002d6cbc + param_1 * 8) = (float)(param_4 - param_2) / 60.0f;
  *(float *)(&DAT_002d6cc0 + param_1 * 8) = (float)(param_5 - param_3) / 28.0f;
}
