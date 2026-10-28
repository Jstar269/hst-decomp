/* HSTMATCH module=hstp_trans_main.prx start=0x001204a4 end=0x001204dc symbol=FUN_001204a4 lang=c99 */
/* Clone of src/eboot/FUN_00115588.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00108aec();

void FUN_001204a4(int param_1)
{
  if (((*(u32 *)(param_1 + 0x6c) & 8) == 0) || (*(int *)(param_1 + 0x88) < 1)) {
    FUN_00108aec();
  }
}
