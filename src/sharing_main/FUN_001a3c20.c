/* HSTMATCH module=hstp_trans_main.prx start=0x001a3c20 end=0x001a3c4c symbol=FUN_001a3c20 lang=c99 */
/* Clone of src/eboot/FUN_001fd0e4.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003eaaa8;
extern void FUN_001a3818();

void FUN_001a3c20(void)
{
  if (DAT_003eaaa8 != 0) {
    FUN_001a3818(DAT_003eaaa8);
  }
}
