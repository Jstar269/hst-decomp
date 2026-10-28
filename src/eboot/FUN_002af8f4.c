/* HSTMATCH module=EBOOT.BIN start=0x002af8f4 end=0x002af920 symbol=FUN_002af8f4 lang=c99 */
/* Clone of src/eboot/FUN_001fd0e4.c (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_0034b5d4;
extern void FUN_002af6ec();

void FUN_002af8f4(void)
{
  if (DAT_0034b5d4 != 0) {
    FUN_002af6ec(DAT_0034b5d4);
  }
}
