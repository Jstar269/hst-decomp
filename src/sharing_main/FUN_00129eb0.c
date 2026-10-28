/* HSTMATCH module=hstp_trans_main.prx start=0x00129eb0 end=0x00129ed8 symbol=FUN_00129eb0 lang=c99 */
/* Clone of src/eboot/FUN_0011ecdc.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

u32 * FUN_00129eb0(u32 *param_1,u32 *param_2)
{
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[2] = param_2[2];
  param_1[3] = param_2[3];
  return param_1;
}
