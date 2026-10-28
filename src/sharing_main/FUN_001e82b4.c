/* HSTMATCH module=hstp_trans_main.prx start=0x001e82b4 end=0x001e835c symbol=FUN_001e82b4 lang=c99 */
/* Clone of src/eboot/FUN_001da1d0.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b26d4;
extern u32 * FUN_0001ec44();

u32 * FUN_001e82b4(u32 *param_1)
{
  FUN_0001ec44();
  *param_1 = (unsigned int)(&DAT_003b26d4);
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[0x30] = 0;
  *(u8 *)(param_1 + 0x31) = 1;
  param_1[0x32] = 0;
  *(u8 *)(param_1 + 0x33) = 1;
  *(u8 *)((int)param_1 + 0xcd) = 0;
  param_1[0x24] = 0;
  param_1[0x25] = 0;
  param_1[0x26] = 0;
  param_1[0x27] = 0x3f800000;
  param_1[0x28] = 0;
  param_1[0x29] = 0;
  param_1[0x2a] = 0;
  param_1[0x2b] = 0x3f800000;
  param_1[0x2c] = 0;
  param_1[0x2d] = 0;
  param_1[0x2e] = 0;
  param_1[0x2f] = 0x3f800000;
  param_1[0x34] = 0;
  param_1[0x35] = 0;
  param_1[0x36] = 0;
  param_1[0x37] = 0x3f800000;
  param_1[0x38] = 0;
  param_1[0x39] = 0;
  param_1[0x3a] = 0;
  param_1[0x3b] = 0;
  return param_1;
}
