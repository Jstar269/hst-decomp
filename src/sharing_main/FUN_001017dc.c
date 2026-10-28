/* HSTMATCH module=hstp_trans_main.prx start=0x001017dc end=0x0010181c symbol=FUN_001017dc lang=c99 */
/* Clone of src/eboot/FUN_000fc0a0.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b0e38;

u32 * FUN_001017dc(u32 *param_1)
{
  *param_1 = (unsigned int)(&DAT_003b0e38);
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  *(u8 *)(param_1 + 7) = 0;
  param_1[8] = 0x47c35000;
  *(u8 *)(param_1 + 9) = 0;
  return param_1;
}
