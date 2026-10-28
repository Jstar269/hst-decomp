/* HSTMATCH module=hstp_trans_main.prx start=0x001e0fcc end=0x001e0fdc symbol=FUN_001e0fcc lang=c99 */
/* Clone of src/eboot/FUN_001d31c8.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003eaad8;
extern void FUN_001c1f44();

void FUN_001e0fcc(void)
{
  FUN_001c1f44((int *)&DAT_003eaad8,1);
}
