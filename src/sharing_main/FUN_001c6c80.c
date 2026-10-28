/* HSTMATCH module=hstp_trans_main.prx start=0x001c6c80 end=0x001c6c8c symbol=FUN_001c6c80 lang=c99 */
/* Clone of src/eboot/FUN_00103474.c (hstclone.py tag c32): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003eaad8;
extern void FUN_001c1ef4();

void FUN_001c6c80(void)
{
  FUN_001c1ef4((int)&DAT_003eaad8);
}
