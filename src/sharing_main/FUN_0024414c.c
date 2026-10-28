/* HSTMATCH module=hstp_trans_main.prx start=0x0024414c end=0x00244178 symbol=FUN_0024414c lang=c99 */
/* Clone of src/eboot/FUN_001fd0e4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003f3994;
extern void FUN_00243d48();

void FUN_0024414c(void)
{
  if (DAT_003f3994 != 0) {
    FUN_00243d48(DAT_003f3994);
  }
}
