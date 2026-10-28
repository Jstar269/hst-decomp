/* HSTMATCH module=hstp_trans_main.prx start=0x000ee9c4 end=0x000ee9d8 symbol=FUN_000ee9c4 lang=c99 */
/* Clone of src/eboot/FUN_000e98f0.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002d10e0;

int FUN_000ee9c4(int param_1)
{
  *(u8 **)(param_1 + 0x40) = &DAT_002d10e0;
  return param_1;
}
