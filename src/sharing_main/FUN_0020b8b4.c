/* HSTMATCH module=hstp_trans_main.prx start=0x0020b8b4 end=0x0020b8e0 symbol=FUN_0020b8b4 lang=c99 */
/* Clone of src/eboot/FUN_001fd0e4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003f3474;
extern void FUN_0020c350();

void FUN_0020b8b4(void)
{
  if (DAT_003f3474 != 0) {
    FUN_0020c350(DAT_003f3474);
  }
}
