/* HSTMATCH module=hstp_trans_main.prx start=0x000c3978 end=0x000c39a8 symbol=FUN_000c3978 lang=c99 */
/* Clone of src/eboot/FUN_000c02d8.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b06c8;

u32 * FUN_000c3978(u32 *param_1)
{
  *param_1 = (unsigned int)(&DAT_003b06c8);
  param_1[2] = 0xffffffff;
  param_1[1] = 0xffffffff;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  return param_1;
}
