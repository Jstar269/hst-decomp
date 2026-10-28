/* HSTMATCH module=hstp_trans_main.prx start=0x00067694 end=0x000676d4 symbol=FUN_00067694 lang=c99 */
/* Clone of src/eboot/FUN_0022995c.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_0006811c();

void FUN_00067694(u32 *param_1)
{
  if ((u32 *)param_1[1] != (u32 *)0x0) {
    FUN_0006811c(param_1,(u32 *)param_1[1]);
    *param_1 = 0;
    param_1[1] = 0;
    param_1[3] = (unsigned int)(param_1 + 1);
  }
}
