/* HSTMATCH module=hstp_trans_main.prx start=0x002b1740 end=0x002b1770 symbol=FUN_002b1740 lang=c99 */
/* Clone of src/eboot/FUN_002a23a8.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_002b136c();

void FUN_002b1740(int param_1)
{
  if (*(int *)(param_1 + 0x1b0) == 5) {
    FUN_002b136c(*(u32 *)(param_1 + 0x1d0),0);
  }
}
