/* HSTMATCH module=hstp_trans_main.prx start=0x0017454c end=0x00174574 symbol=FUN_0017454c lang=c99 */
/* Clone of src/eboot/FUN_00168388.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

u32 * FUN_0017454c(u32 *param_1)
{
  *param_1 = 0;
  param_1[1] = 0x3f800000;
  param_1[2] = 0;
  param_1[3] = 0x3f000000;
  param_1[4] = 0x40000000;
  return param_1;
}
