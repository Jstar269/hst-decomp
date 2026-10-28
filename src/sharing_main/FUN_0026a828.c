/* HSTMATCH module=hstp_trans_main.prx start=0x0026a828 end=0x0026a858 symbol=FUN_0026a828 lang=c99 */
/* Clone of src/eboot/FUN_00190ed0.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

u32 * FUN_0026a828(u32 *param_1,u32 *param_2,u32 param_3,u32 param_4)
{
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[2] = param_2[2];
  param_1[3] = param_2[3];
  param_1[4] = param_3;
  param_1[5] = param_4;
  return param_1;
}
