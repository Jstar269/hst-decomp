/* HSTMATCH module=hstp_trans_main.prx start=0x001d8300 end=0x001d8310 symbol=FUN_001d8300 lang=c99 */
/* Clone of src/eboot/FUN_001c9e0c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003f39a8;
extern void FUN_00244258();

void FUN_001d8300(void)
{
  FUN_00244258(&DAT_003f39a8,0x21);
}
