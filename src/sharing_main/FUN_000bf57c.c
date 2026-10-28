/* HSTMATCH module=hstp_trans_main.prx start=0x000bf57c end=0x000bf5b0 symbol=FUN_000bf57c lang=c99 */
/* Clone of src/eboot/FUN_000bc108.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003e1e04;
extern void FUN_000bf8a8();

void FUN_000bf57c(u32 param_1,u32 param_2)
{
  if (DAT_003e1e04 != 0) {
    FUN_000bf8a8(DAT_003e1e04,param_1,param_2);
  }
}
