/* HSTMATCH module=hstp_trans_main.prx start=0x002a308c end=0x002a30f8 symbol=FUN_002a308c lang=c99 */
/* Clone of src/eboot/FUN_00291a80.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b30c4;

u32 * FUN_002a308c(u32 *param_1)
{
  *param_1 = (unsigned int)(&DAT_003b30c4);
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[5] = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0x3f800000;
  *(u8 *)(param_1 + 0x10) = 0;
  *(u8 *)((int)param_1 + 0x41) = 0;
  param_1[0x11] = 2;
  param_1[0x12] = 0;
  return param_1;
}
