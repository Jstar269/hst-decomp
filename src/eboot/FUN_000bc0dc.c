/* HSTMATCH module=EBOOT.BIN start=0x000bc0dc end=0x000bc108 symbol=FUN_000bc0dc lang=c99 */
/* Clone of src/eboot/FUN_001fd0e4.c (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_00338ac4;
extern void FUN_000bc13c();

void FUN_000bc0dc(void)
{
  if (DAT_00338ac4 != 0) {
    FUN_000bc13c(DAT_00338ac4);
  }
}
