/* HSTMATCH module=hstp_trans_main.prx start=0x0023bab4 end=0x0023bacc symbol=FUN_0023bab4 lang=c99 */
/* Clone of src/eboot/FUN_0022c044.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 * DAT_003ea8e8;

int FUN_0023bab4(void)
{
  return (int)*(short *)(DAT_003ea8e8 + 0xd4e4);
}
