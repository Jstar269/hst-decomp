/* HSTMATCH module=hstp_trans_main.prx start=0x00063a00 end=0x00063a28 symbol=FUN_00063a00 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_00079c94();

u32 FUN_00063a00(int param_1)
{
  u32 uVar1;
  
  if (param_1 < 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_00079c94();
  }
  return uVar1;
}
