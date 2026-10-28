/* HSTMATCH module=hstp_trans_main.prx start=0x002b3c08 end=0x002b3c70 symbol=FUN_002b3c08 lang=c99 */
/* Clone of src/eboot/FUN_002a44f0.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 * DAT_003ea8e8;
extern void FUN_002b1820();

void FUN_002b3c08(int param_1,u32 param_2,u32 param_3,int *param_4,u32 param_5, u32 param_6,u32 param_7,u32 param_8)
{
  u32 *puVar1;
  
  puVar1 = (u32 *)(DAT_003ea8e8 + 0x86d10);
  if (((*puVar1 & 2) == 0) && (*puVar1 = *puVar1 | 2, *(int *)(param_1 + 0x1b0) != 5)) {
    *(u32 *)(param_1 + 0x1c0) = *(u32 *)(param_1 + 0x1b8);
    *(u32 *)(param_1 + 0x1b8) = 1;
    *(u32 *)(param_1 + 0x1bc) = 0;
    FUN_002b1820(param_1,1,puVar1,param_4,param_5,param_6,param_7,param_8);
  }
}
