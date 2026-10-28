/* HSTMATCH module=hstp_trans_main.prx start=0x002b0264 end=0x002b0294 symbol=FUN_002b0264 lang=c99 */
/* Clone of src/eboot/FUN_002a0e58.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002dc598;

u32 * FUN_002b0264(u32 *param_1)
{
  *param_1 = (unsigned int)(&DAT_002dc598);
  *(u8 *)(param_1 + 1) = 0;
  param_1[0x41] = 0;
  param_1[0x42] = 0;
  *(u8 *)(param_1 + 0x43) = 0;
  param_1[0x42] = 0x7fffffff;
  return param_1;
}
