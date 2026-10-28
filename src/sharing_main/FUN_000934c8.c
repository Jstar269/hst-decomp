/* HSTMATCH module=hstp_trans_main.prx start=0x000934c8 end=0x00093544 symbol=FUN_000934c8 lang=c99 */
/* Clone of src/eboot/FUN_00091830.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b0530;
extern void FUN_0009378c();
extern void FUN_00093954();
extern u32 * FUN_00096370();

u32 * FUN_000934c8(u32 *param_1)
{
  *param_1 = (unsigned int)(&DAT_003b0530);
  FUN_00096370(param_1 + 0x20);
  FUN_00096370(param_1 + 0x2c);
  param_1[10] = 0;
  param_1[0xc] = 0xbf800000;
  param_1[0xd] = 0xbf800000;
  param_1[0xe] = 0xbf800000;
  param_1[0xf] = 0xbf800000;
  param_1[0x10] = 0;
  param_1[0x11] = 0x3f800000;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  FUN_0009378c(param_1);
  FUN_00093954(param_1);
  return param_1;
}
