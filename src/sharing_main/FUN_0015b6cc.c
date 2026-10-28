/* HSTMATCH module=hstp_trans_main.prx start=0x0015b6cc end=0x0015b6e4 symbol=FUN_0015b6cc lang=c99 */
/* Clone of src/eboot/FUN_0014f314.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

u32 * FUN_0015b6cc(u32 *param_1)
{
  *param_1 = 0;
  param_1[2] = (unsigned int)(param_1 + 1);
  param_1[1] = (unsigned int)(param_1 + 1);
  return param_1;
}
