/* HSTMATCH module=EBOOT.BIN start=0x001b413c end=0x001b41c8 symbol=FUN_001b413c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: fixed parameter types, helper prototype and call arguments, and the early-return flow; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_000628e4();
extern void FUN_00062b1c(int, float, int);

void FUN_001b413c(int *param_3,float param_1,float param_2)
{
  int iVar1;
  
  iVar1 = *param_3;
  if (*(int *)(iVar1 + 0x7ac) < 0) {
    return;
  }
  FUN_00062b1c(*(int *)(iVar1 + 0x7ac),param_2,(int)(param_1 * 128.0f));
  if (param_1 <= 0.0f) {
    *(u32 *)(iVar1 + 2000) = *(u32 *)(iVar1 + 0x7ac);
  }
  else if (*(int *)(iVar1 + 2000) >= 0) {
    FUN_000628e4(*(int *)(iVar1 + 2000),0);
    *(u32 *)(iVar1 + 2000) = 0xffffffff;
  }
  *(float *)(iVar1 + 0x7d4) = param_1;
}
