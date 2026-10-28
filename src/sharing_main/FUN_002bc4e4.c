/* HSTMATCH module=hstp_trans_main.prx start=0x002bc4e4 end=0x002bc51c symbol=FUN_002bc4e4 lang=c99 */
/* Clone of src/eboot/FUN_002acd28.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002dc5b8;

bool FUN_002bc4e4(int param_1)
{
  bool bVar1;
  
  if (param_1 >= 0 && (param_1 < 0x28)) {
    bVar1 = (&DAT_002dc5b8)[param_1] != '\0';
  }
  else {
    bVar1 = false;
  }
  return bVar1;
}
