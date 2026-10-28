/* HSTMATCH module=hstp_trans_main.prx start=0x0023cd54 end=0x0023cd64 symbol=FUN_0023cd54 lang=c99 */
/* Clone of src/eboot/FUN_0022cc54.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003ea8e8;

u32 FUN_0023cd54(void)
{
  return *(u32 *)(DAT_003ea8e8 + 0x80);
}
