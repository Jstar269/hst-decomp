/* HSTMATCH module=hstp_trans_main.prx start=0x000bf550 end=0x000bf57c symbol=FUN_000bf550 lang=c99 */
/* Clone of src/eboot/FUN_001fd0e4.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003e1e04;
extern void FUN_000bf5b0();

void FUN_000bf550(void)
{
  if (DAT_003e1e04 != 0) {
    FUN_000bf5b0(DAT_003e1e04);
  }
}
