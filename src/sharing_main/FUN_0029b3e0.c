/* HSTMATCH module=hstp_trans_main.prx start=0x0029b3e0 end=0x0029b3f4 symbol=FUN_0029b3e0 lang=c99 */
/* Clone of src/eboot/FUN_000b5ed4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_0029b3e0(u32 *param_1,u32 *param_2)
{
  u32 uVar1;
  
  uVar1 = param_2[1];
  *param_1 = *param_2;
  param_1[1] = uVar1;
}
