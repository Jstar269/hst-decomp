/* HSTMATCH module=hstp_trans_main.prx start=0x0019d6e0 end=0x0019d710 symbol=FUN_0019d6e0 lang=c99 */
/* Clone of src/eboot/FUN_00190ed0.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

u32 * FUN_0019d6e0(u32 *param_1,u32 *param_2,u32 param_3,u32 param_4)
{
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[2] = param_2[2];
  param_1[3] = param_2[3];
  param_1[4] = param_3;
  param_1[5] = param_4;
  return param_1;
}
