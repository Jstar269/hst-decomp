/* HSTMATCH module=EBOOT.BIN start=0x0006078c end=0x000607b8 symbol=FUN_0006078c lang=c99 */
/* Clone of src/eboot/FUN_001fd0e4.c (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003313cc;
extern void FUN_00060334();

void FUN_0006078c(void)
{
  if (DAT_003313cc != 0) {
    FUN_00060334(DAT_003313cc);
  }
}
