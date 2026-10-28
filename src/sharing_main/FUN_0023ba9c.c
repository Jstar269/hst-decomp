/* HSTMATCH module=hstp_trans_main.prx start=0x0023ba9c end=0x0023bab4 symbol=FUN_0023ba9c lang=c99 */
/* Clone of src/eboot/FUN_0022c02c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 * DAT_003ea8e8;

void FUN_0023ba9c(u16 param_1)
{
  *(u16 *)(DAT_003ea8e8 + 0xd4e4) = param_1;
}
