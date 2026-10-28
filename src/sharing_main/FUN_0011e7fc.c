/* HSTMATCH module=hstp_trans_main.prx start=0x0011e7fc end=0x0011e8a8 symbol=FUN_0011e7fc lang=c99 */
/* Clone of src/eboot/FUN_00114024.c (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002cc260;
extern u8 DAT_003b0a68;
extern u8 DAT_003b0d5c;
extern u32 FUN_00056cac();
extern u32 * FUN_001016c0();
extern u32 * FUN_00101748();
extern u32 * FUN_001017dc();

u32 * FUN_0011e7fc(u32 *param_1,u32 param_2)
{
  FUN_001017dc(param_1);
  FUN_00056cac(param_1 + 0xc);
  *param_1 = (unsigned int)(&DAT_003b0a68);
  param_1[0x1c] = 0;
  param_1[0x1d] = 0xffffffff;
  param_1[0x1e] = 0x3f800000;
  param_1[0x1f] = 0x3f800000;
  FUN_00056cac(param_1 + 0x20);
  param_1[0x30] = param_2;
  FUN_00101748(param_1,&DAT_002cc260);
  FUN_001016c0(param_1 + 0x20,&DAT_002cc260);
  *param_1 = (unsigned int)(&DAT_003b0d5c);
  param_1[0x34] = 1;
  param_1[0x35] = 2;
  param_1[0x36] = 0;
  return param_1;
}
