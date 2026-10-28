/* HSTMATCH module=hstp_trans_main.prx start=0x0023bf04 end=0x0023bf2c symbol=FUN_0023bf04 lang=c99 */
/* Clone of src/eboot/FUN_0022c484.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 * DAT_003ea8e8;

int FUN_0023bf04(void)
{
  int iVar1;
  
  if (*(int *)(DAT_003ea8e8 + 0xd4d0) < 0) {
    iVar1 = -*(int *)(DAT_003ea8e8 + 0xd4d0);
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}
