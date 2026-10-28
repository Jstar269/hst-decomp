/* HSTMATCH module=hstp_trans_main.prx start=0x0028b7b8 end=0x0028b7d0 symbol=FUN_0028b7b8 lang=c99 */
/* Clone of src/eboot/FUN_0014f314.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

u32 * FUN_0028b7b8(u32 *param_1)
{
  *param_1 = 0;
  param_1[2] = (unsigned int)(param_1 + 1);
  param_1[1] = (unsigned int)(param_1 + 1);
  return param_1;
}
