/* HSTMATCH module=hstp_trans_main.prx start=0x00261018 end=0x00261040 symbol=FUN_00261018 lang=c99 */
/* Clone of src/eboot/FUN_00250cc4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

u32 FUN_00261018(int param_1)
{
  u32 uVar1;
  
  uVar1 = 1;
  if ((*(int *)(param_1 + 0x2f8) != 4) && (*(int *)(param_1 + 0x2f8) != 6)) {
    uVar1 = 0;
  }
  return uVar1;
}
