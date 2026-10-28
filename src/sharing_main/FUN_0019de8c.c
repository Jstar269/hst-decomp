/* HSTMATCH module=hstp_trans_main.prx start=0x0019de8c end=0x0019deb4 symbol=FUN_0019de8c lang=c99 */
/* Clone of src/eboot/FUN_0011ecdc.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

u32 * FUN_0019de8c(u32 *param_1,u32 *param_2)
{
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[2] = param_2[2];
  param_1[3] = param_2[3];
  return param_1;
}
