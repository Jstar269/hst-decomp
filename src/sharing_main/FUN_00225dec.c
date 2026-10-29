/* HSTMATCH module=hstp_trans_main.prx start=0x00225dec end=0x00225e04 symbol=FUN_00225dec lang=c99 */
/* Clone of src/eboot/FUN_00216de8.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

/* Half of `value`, rounded up. */
int FUN_00225dec(u32 value)
{
  int half;
  
  half = (int)value >> 1;
  if ((value & 1) != 0) {
    half = half + 1;
  }
  return half;
}
