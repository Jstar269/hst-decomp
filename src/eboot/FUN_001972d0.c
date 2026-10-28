/* HSTMATCH module=EBOOT.BIN start=0x001972d0 end=0x001972fc symbol=FUN_001972d0 lang=c99 */
/* Clone of src/eboot/FUN_001fd0e4.c (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_00341768;
extern void FUN_00196ef4();

void FUN_001972d0(void)
{
  if (DAT_00341768 != 0) {
    FUN_00196ef4(DAT_00341768);
  }
}
