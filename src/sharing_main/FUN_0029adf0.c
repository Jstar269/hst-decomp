/* HSTMATCH module=hstp_trans_main.prx start=0x0029adf0 end=0x0029ae08 symbol=FUN_0029adf0 lang=c99 */
/* Clone of src/eboot/FUN_0014f314.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

u32 * FUN_0029adf0(u32 *param_1)
{
  *param_1 = 0;
  param_1[2] = (unsigned int)(param_1 + 1);
  param_1[1] = (unsigned int)(param_1 + 1);
  return param_1;
}
