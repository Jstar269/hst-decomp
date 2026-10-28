/* HSTMATCH module=hstp_trans_main.prx start=0x0019edb0 end=0x0019ee00 symbol=FUN_0019edb0 lang=c99 */
/* Clone of src/eboot/FUN_0011d520.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_0019edb0(u32 *param_1,u32 *param_2)
{
  u32 uVar1;
  
  if (param_1 != param_2) {
    uVar1 = *param_1;
    *param_1 = *param_2;
    *param_2 = uVar1;
    uVar1 = param_1[1];
    param_1[1] = param_2[1];
    param_2[1] = uVar1;
    uVar1 = param_1[2];
    param_1[2] = param_2[2];
    param_2[2] = uVar1;
    uVar1 = param_1[3];
    param_1[3] = param_2[3];
    param_2[3] = uVar1;
  }
}
