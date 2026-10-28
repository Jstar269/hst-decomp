/* HSTMATCH module=hstp_trans_main.prx start=0x00128224 end=0x00128280 symbol=FUN_00128224 lang=c99 */
/* Clone of src/eboot/FUN_0011d050.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_001286f4();

void FUN_00128224(int param_1,int param_2)
{
  u32 uVar1;
  
  if (param_1 != param_2) {
    FUN_001286f4();
    uVar1 = *(u32 *)(param_1 + 0x10);
    *(u32 *)(param_1 + 0x10) = *(u32 *)(param_2 + 0x10);
    *(u32 *)(param_2 + 0x10) = uVar1;
    uVar1 = *(u32 *)(param_1 + 0x14);
    *(u32 *)(param_1 + 0x14) = *(u32 *)(param_2 + 0x14);
    *(u32 *)(param_2 + 0x14) = uVar1;
  }
}
