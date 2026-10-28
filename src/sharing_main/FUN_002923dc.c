/* HSTMATCH module=hstp_trans_main.prx start=0x002923dc end=0x00292408 symbol=FUN_002923dc lang=c99 */
/* Clone of src/eboot/FUN_00281064.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003e1e04;
extern void FUN_000c0c80();

void FUN_002923dc(void)
{
  if (DAT_003e1e04 != 0) {
    FUN_000c0c80(DAT_003e1e04,0xffffffff);
  }
}
