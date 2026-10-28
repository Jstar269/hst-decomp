/* HSTMATCH module=hstp_trans_main.prx start=0x00128780 end=0x001287d0 symbol=FUN_00128780 lang=c99 */
/* Clone of src/eboot/FUN_0011d520.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_00128780(u32 *param_1,u32 *param_2)
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
