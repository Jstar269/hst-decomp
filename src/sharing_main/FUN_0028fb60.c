/* HSTMATCH module=hstp_trans_main.prx start=0x0028fb60 end=0x0028fb8c symbol=FUN_0028fb60 lang=c99 */
/* Clone of src/eboot/FUN_0027e71c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b2f64;

u32 * FUN_0028fb60(u32 *param_1)
{
  *param_1 = (unsigned int)(&DAT_003b2f64);
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  return param_1;
}
