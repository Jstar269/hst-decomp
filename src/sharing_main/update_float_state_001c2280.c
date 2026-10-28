/* HSTMATCH module=hstp_trans_main.prx start=0x001c2280 end=0x001c230c symbol=FUN_001c2280 lang=c99 */
/* Clone of src/eboot/update_float_state_001b413c.c (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: fixed parameter types, helper prototype and call arguments, and the early-return flow; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_000637a8();
extern void FUN_000639e0(int, float, int);

void FUN_001c2280(int *param_3,float param_1,float param_2)
{
  int iVar1;
  
  iVar1 = *param_3;
  if (*(int *)(iVar1 + 0x7ac) < 0) {
    return;
  }
  FUN_000639e0(*(int *)(iVar1 + 0x7ac),param_2,(int)(param_1 * 128.0f));
  if (param_1 <= 0.0f) {
    *(u32 *)(iVar1 + 2000) = *(u32 *)(iVar1 + 0x7ac);
  }
  else if (*(int *)(iVar1 + 2000) >= 0) {
    FUN_000637a8(*(int *)(iVar1 + 2000),0);
    *(u32 *)(iVar1 + 2000) = 0xffffffff;
  }
  *(float *)(iVar1 + 0x7d4) = param_1;
}
