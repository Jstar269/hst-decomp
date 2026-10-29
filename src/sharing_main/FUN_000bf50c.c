/* HSTMATCH module=hstp_trans_main.prx start=0x000bf50c end=0x000bf550 symbol=FUN_000bf50c lang=c99 */
/* Clone of src/eboot/FUN_000bc098.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003e1e04;
extern void FUN_000bf720();

/* Forwards five arguments to the environment object's handler when the object exists. */
void FUN_000bf50c(u32 arg0,u32 arg1,u32 arg2,u32 arg3, u32 arg4)
{
  if (DAT_003e1e04 != 0) {
    FUN_000bf720(DAT_003e1e04,arg0,arg1,arg2,arg3,arg4);
  }
}
