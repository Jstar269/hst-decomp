/* HSTMATCH module=EBOOT.BIN start=0x002891ec end=0x002891f8 symbol=FUN_002891ec lang=c99 */
/* Clone of src/eboot/FUN_00103474.c (hstclone.py tag c31): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002feb84;
extern void FUN_00286acc();

void FUN_002891ec(void)
{
  FUN_00286acc((int)&DAT_002feb84);
}
