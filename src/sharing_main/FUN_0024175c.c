/* HSTMATCH module=hstp_trans_main.prx start=0x0024175c end=0x0024177c symbol=FUN_0024175c lang=c99 */
/* Clone of src/eboot/FUN_0023165c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_0039bf2c;
extern u8 DAT_0039bf30;

void FUN_0024175c(int param_1)
{
  DAT_0039bf2c = *(u32 *)(&DAT_0039bf30 + param_1 * 4);
}
