/* HSTMATCH module=hstp_trans_main.prx start=0x00068f7c end=0x00068f94 symbol=FUN_00068f7c lang=c99 */
/* Clone of src/eboot/FUN_0014f314.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

u32 * FUN_00068f7c(u32 *param_1)
{
  *param_1 = 0;
  param_1[2] = (unsigned int)(param_1 + 1);
  param_1[1] = (unsigned int)(param_1 + 1);
  return param_1;
}
