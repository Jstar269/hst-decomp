/* HSTMATCH module=hstp_trans_main.prx start=0x002bf344 end=0x002bf370 symbol=FUN_002bf344 lang=c99 */
/* Clone of src/eboot/FUN_001fd0e4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003f4914;
extern void FUN_002bf13c();

void FUN_002bf344(void)
{
  if (DAT_003f4914 != 0) {
    FUN_002bf13c(DAT_003f4914);
  }
}
