/* HSTMATCH module=hstp_trans_main.prx start=0x000b91c4 end=0x000b91d8 symbol=FUN_000b91c4 lang=c99 */
/* Clone of src/eboot/FUN_000b5ed4.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_000b91c4(u32 *param_1,u32 *param_2)
{
  u32 uVar1;
  
  uVar1 = param_2[1];
  *param_1 = *param_2;
  param_1[1] = uVar1;
}
