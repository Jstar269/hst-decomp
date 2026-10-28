/* HSTMATCH module=hstp_trans_main.prx start=0x002b3ba0 end=0x002b3c08 symbol=FUN_002b3ba0 lang=c99 */
/* Clone of src/eboot/FUN_002a4488.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 * DAT_003ea8e8;
extern void FUN_002b1820();

void FUN_002b3ba0(int param_1)
{
  u32 uVar1;
  
  uVar1 = *(u32 *)(DAT_003ea8e8 + 0x86d10);
  if (((uVar1 & 1) == 0) &&
     (*(u32 *)(DAT_003ea8e8 + 0x86d10) = uVar1 | 1, *(int *)(param_1 + 0x1b0) != 5)) {
    *(u32 *)(param_1 + 0x1c0) = *(u32 *)(param_1 + 0x1b8);
    *(u32 *)(param_1 + 0x1b8) = 0;
    *(u32 *)(param_1 + 0x1bc) = 0;
    FUN_002b1820(param_1,1);
  }
}
