/* HSTMATCH module=hstp_trans_main.prx start=0x00239024 end=0x00239064 symbol=FUN_00239024 lang=c99 */
/* Clone of src/eboot/FUN_0022995c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00239698();

void FUN_00239024(u32 *param_1)
{
  if ((u32 *)param_1[1] != (u32 *)0x0) {
    FUN_00239698(param_1,(u32 *)param_1[1]);
    *param_1 = 0;
    param_1[1] = 0;
    param_1[3] = (unsigned int)(param_1 + 1);
  }
}
