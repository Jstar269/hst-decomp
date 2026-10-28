/* HSTMATCH module=hstp_trans_main.prx start=0x00051da4 end=0x00051df0 symbol=FUN_00051da4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003ba4b0;
extern u32 FUN_00050aec();

void FUN_00051da4(int param_1,u8 param_2,u8 param_3)
{
  int iVar1;
  
  iVar1 = FUN_00050aec((int)&DAT_003ba4b0,*(u32 *)(param_1 + 4));
  if (iVar1 != 0) {
    *(u8 *)(iVar1 + 0x92) = param_2;
    *(u8 *)(iVar1 + 0x93) = param_3;
  }
}
