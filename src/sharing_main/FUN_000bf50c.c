/* HSTMATCH module=hstp_trans_main.prx start=0x000bf50c end=0x000bf550 symbol=FUN_000bf50c lang=c99 */
/* Clone of src/eboot/FUN_000bc098.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003e1e04;
extern void FUN_000bf720();

void FUN_000bf50c(u32 param_1,u32 param_2,u32 param_3,u32 param_4, u32 param_5)
{
  if (DAT_003e1e04 != 0) {
    FUN_000bf720(DAT_003e1e04,param_1,param_2,param_3,param_4,param_5);
  }
}
