/* HSTMATCH module=hstp_trans_main.prx start=0x001c3400 end=0x001c340c symbol=FUN_001c3400 lang=c99 */
/* Clone of src/eboot/FUN_00103474.c (hstclone.py tag c32): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003eaad8;
extern void FUN_001c29f8();

void FUN_001c3400(void)
{
  FUN_001c29f8((int)&DAT_003eaad8);
}
