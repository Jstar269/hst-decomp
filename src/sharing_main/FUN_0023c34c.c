/* HSTMATCH module=hstp_trans_main.prx start=0x0023c34c end=0x0023c364 symbol=FUN_0023c34c lang=c99 */
/* Clone of src/eboot/FUN_0022c878.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 * DAT_003ea8e8;

u8 FUN_0023c34c(void)
{
  return *(u8 *)(DAT_003ea8e8 + 0xe050);
}
