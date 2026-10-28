/* HSTMATCH module=hstp_trans_main.prx start=0x00225dec end=0x00225e04 symbol=FUN_00225dec lang=c99 */
/* Clone of src/eboot/FUN_00216de8.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

int FUN_00225dec(u32 param_1)
{
  int iVar1;
  
  iVar1 = (int)param_1 >> 1;
  if ((param_1 & 1) != 0) {
    iVar1 = iVar1 + 1;
  }
  return iVar1;
}
