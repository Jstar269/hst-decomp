/* HSTMATCH module=hstp_trans_main.prx start=0x000663b8 end=0x00066400 symbol=FUN_000663b8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: typed the helper arguments, used pointer arithmetic for the object subobject, and reversed the comparison arms; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_000670b4(int *,u32 *,u32 *);

u32 FUN_000663b8(int param_1,u32 param_2)
{
  u32 uVar1;
  int local_8 [2];
  u32 local_c;
  
  local_c = param_2;
  FUN_000670b4(local_8,(u32 *)param_1 + 4,&local_c);
  if (local_8[0] != param_1 + 0x14) {
    uVar1 = *(u32 *)(local_8[0] + 0x10);
  } else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}
