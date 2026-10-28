/* HSTMATCH module=hstp_trans_main.prx start=0x0012848c end=0x001284e8 symbol=FUN_0012848c lang=c99 */
/* Clone of src/eboot/FUN_0011d050.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00128780();

void FUN_0012848c(int param_1,int param_2)
{
  u32 uVar1;
  
  if (param_1 != param_2) {
    FUN_00128780();
    uVar1 = *(u32 *)(param_1 + 0x10);
    *(u32 *)(param_1 + 0x10) = *(u32 *)(param_2 + 0x10);
    *(u32 *)(param_2 + 0x10) = uVar1;
    uVar1 = *(u32 *)(param_1 + 0x14);
    *(u32 *)(param_1 + 0x14) = *(u32 *)(param_2 + 0x14);
    *(u32 *)(param_2 + 0x14) = uVar1;
  }
}
