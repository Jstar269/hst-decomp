/* HSTMATCH module=hstp_trans_main.prx start=0x00104c88 end=0x00104cac symbol=FUN_00104c88 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh128a), refined by hstperm.py tag p4 random mutation from try/gen-sh128a/v0/FUN_00104c88.c; exact match verified; names and types await human review. */
#include "hst/types.h"

u32 FUN_00104c88(int param_1,u32 param_2)
{
  u32 uVar1;
  
  uVar1 = 0xffffffff;
  if (param_2 >= 0x14) {
    uVar1 = *(u32 *)(param_1 + 0xc) ^ 0x8729382e;
  }
  return uVar1;
}
