/* HSTMATCH module=hstp_trans_main.prx start=0x00169770 end=0x00169790 symbol=FUN_00169770 lang=c99 */
/* Clone of src/eboot/FUN_0015d1c8.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003e9740;

u8 FUN_00169770(u32 param_1,int param_2)
{
  u8 uVar1;
  
  uVar1 = 0;
  if (DAT_003e9740 != 0) {
    uVar1 = *(u8 *)(param_2 + DAT_003e9740 + 0x10);
  }
  return uVar1;
}
