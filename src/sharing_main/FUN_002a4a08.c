/* HSTMATCH module=hstp_trans_main.prx start=0x002a4a08 end=0x002a4a48 symbol=FUN_002a4a08 lang=c99 */
/* Clone of src/eboot/FUN_002933fc.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

u32 FUN_002a4a08(int param_1)
{
  u32 uVar1;
  
  uVar1 = 0;
  if (((*(u8 *)(param_1 + 0x4d) != '\0') && (*(u8 *)(param_1 + 0x40) == '\0')) &&
     (*(float *)(param_1 + 0x38) <= 31.0f)) {
    uVar1 = 1;
  }
  return uVar1;
}
