/* HSTMATCH module=hstp_trans_main.prx start=0x0023bc48 end=0x0023bc60 symbol=FUN_0023bc48 lang=c99 */
/* Clone of src/eboot/FUN_0022c194.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 * DAT_003ea8e8;

u32 FUN_0023bc48(void)
{
  return *(u32 *)(DAT_003ea8e8 + 0xd4d4);
}
