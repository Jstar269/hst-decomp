/* HSTMATCH module=EBOOT.BIN start=0x0023404c end=0x00234078 symbol=FUN_0023404c lang=c99 */
/* Clone of src/eboot/FUN_001fd0e4.c (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_0034a664;
extern void FUN_00233c48();

void FUN_0023404c(void)
{
  if (DAT_0034a664 != 0) {
    FUN_00233c48(DAT_0034a664);
  }
}
