/* HSTMATCH module=hstp_trans_main.prx start=0x0023ccd8 end=0x0023ccf0 symbol=FUN_0023ccd8 lang=c99 */
/* Clone of src/eboot/FUN_0022cbd4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 * DAT_003ea8e8;

u32 FUN_0023ccd8(void)
{
  return *(u32 *)(DAT_003ea8e8 + 0xd4d8);
}
