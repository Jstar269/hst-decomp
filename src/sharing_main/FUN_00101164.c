/* HSTMATCH module=hstp_trans_main.prx start=0x00101164 end=0x001011c4 symbol=FUN_00101164 lang=c99 */
/* Clone of src/eboot/FUN_000fba28.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b0a10;
extern u32 DAT_003e1f64;
extern u32 * FUN_0001ec44();

u32 * FUN_00101164(u32 *param_1)
{
  FUN_0001ec44();
  *param_1 = (unsigned int)(&DAT_003b0a10);
  param_1[0xf] = 0;
  DAT_003e1f64 = (unsigned int)(param_1);
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  *(u8 *)(param_1 + 0x16) = 0;
  param_1[0x17] = 0;
  return param_1;
}
