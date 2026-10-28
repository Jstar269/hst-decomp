/* HSTMATCH module=hstp_trans_main.prx start=0x0023bc10 end=0x0023bc30 symbol=FUN_0023bc10 lang=c99 */
/* Clone of src/eboot/FUN_0022c15c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 * DAT_003ea8e8;

bool FUN_0023bc10(void)
{
  return (*(u16 *)(DAT_003ea8e8 + 0xd504) & 2) != 0;
}
