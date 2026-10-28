/* HSTMATCH module=hstp_trans_main.prx start=0x0023bb88 end=0x0023bba8 symbol=FUN_0023bb88 lang=c99 */
/* Clone of src/eboot/FUN_0022c0d4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 * DAT_003ea8e8;

bool FUN_0023bb88(void)
{
  return (*(u16 *)(DAT_003ea8e8 + 0xd504) & 1) != 0;
}
