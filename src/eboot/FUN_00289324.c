/* HSTMATCH module=EBOOT.BIN start=0x00289324 end=0x00289330 symbol=FUN_00289324 lang=c99 */
/* Clone of src/eboot/FUN_00103474.c (hstclone.py tag c31): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002fec0c;
extern void FUN_00286acc();

void FUN_00289324(void)
{
  FUN_00286acc((int)&DAT_002fec0c);
}
