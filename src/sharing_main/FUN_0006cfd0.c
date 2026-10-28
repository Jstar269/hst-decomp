/* HSTMATCH module=hstp_trans_main.prx start=0x0006cfd0 end=0x0006d010 symbol=FUN_0006cfd0 lang=c99 */
/* Clone of src/eboot/FUN_0022995c.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_0006df1c();

void FUN_0006cfd0(u32 *param_1)
{
  if ((u32 *)param_1[1] != (u32 *)0x0) {
    FUN_0006df1c(param_1,(u32 *)param_1[1]);
    *param_1 = 0;
    param_1[1] = 0;
    param_1[3] = (unsigned int)(param_1 + 1);
  }
}
