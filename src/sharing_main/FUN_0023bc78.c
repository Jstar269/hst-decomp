/* HSTMATCH module=hstp_trans_main.prx start=0x0023bc78 end=0x0023bc90 symbol=FUN_0023bc78 lang=c99 */
/* Clone of src/eboot/FUN_0022c1c4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 * DAT_003ea8e8;

u32 FUN_0023bc78(void)
{
  return *(u32 *)(DAT_003ea8e8 + 0xe020);
}
