/* HSTMATCH module=hstp_trans_main.prx start=0x0023bc90 end=0x0023bca8 symbol=FUN_0023bc90 lang=c99 */
/* Clone of src/eboot/FUN_0022c1dc.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 * DAT_003ea8e8;

u8 FUN_0023bc90(void)
{
  return *(u8 *)(DAT_003ea8e8 + 0xe04c);
}
