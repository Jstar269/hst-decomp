/* HSTMATCH module=hstp_trans_main.prx start=0x00108da0 end=0x00108dac symbol=FUN_00108da0 lang=c99 */
/* Clone of src/eboot/FUN_00103474.c (hstclone.py tag c32): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003e39c0;
extern void FUN_000522c0();

void FUN_00108da0(void)
{
  FUN_000522c0((int)&DAT_003e39c0);
}
