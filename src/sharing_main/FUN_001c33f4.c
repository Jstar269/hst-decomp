/* HSTMATCH module=hstp_trans_main.prx start=0x001c33f4 end=0x001c3400 symbol=FUN_001c33f4 lang=c99 */
/* Clone of src/eboot/FUN_00103474.c (hstclone.py tag c32): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003eaad8;
extern void FUN_001c1d84();

void FUN_001c33f4(void)
{
  FUN_001c1d84((int)&DAT_003eaad8);
}
