/* HSTMATCH module=hstp_trans_main.prx start=0x00104c64 end=0x00104c88 symbol=FUN_00104c64 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh128a), refined by hstperm.py tag p4 random mutation from try/gen-sh128a/v0/FUN_00104c64.c; exact match verified; names and types await human review. */
#include "hst/types.h"

u32 FUN_00104c64(int param_1,u32 param_2)
{
  int uVar1;
  
  uVar1 = 0xffffffff;
  if (param_2 >= 0x14) {
    uVar1 = *(u32 *)(param_1 + 8) ^ 0x3456ff33;
  }
  return uVar1;
}
