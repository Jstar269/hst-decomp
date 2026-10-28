/* HSTMATCH module=hstp_trans_main.prx start=0x001c340c end=0x001c3418 symbol=FUN_001c340c lang=c99 */
/* Clone of src/eboot/FUN_00103474.c (hstclone.py tag c32): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003eaad8;
extern void FUN_001c2a00();

void FUN_001c340c(void)
{
  FUN_001c2a00((int)&DAT_003eaad8);
}
