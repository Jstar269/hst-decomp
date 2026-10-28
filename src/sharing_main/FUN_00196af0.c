/* HSTMATCH module=hstp_trans_main.prx start=0x00196af0 end=0x00196bb4 symbol=FUN_00196af0 lang=c99 */
/* Clone of src/eboot/FUN_0018a3a4.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002cc260;
extern u8 DAT_00387fac;
extern u8 DAT_003b0a68;
extern u8 DAT_003b23ac;
extern u8 DAT_003b23f0;
extern u32 FUN_00056cac();
extern u32 * FUN_001016c0();
extern u32 * FUN_00101748();
extern u32 * FUN_001017dc();
extern u32 * FUN_002264e8();

u32 * FUN_00196af0(u32 *param_1)
{
  FUN_001017dc();
  FUN_00056cac(param_1 + 0xc);
  *param_1 = (unsigned int)(&DAT_003b0a68);
  param_1[0x1c] = 0;
  param_1[0x1d] = 0xffffffff;
  param_1[0x1e] = 0x3f800000;
  param_1[0x1f] = 0x3f800000;
  FUN_00056cac(param_1 + 0x20);
  param_1[0x30] = (unsigned int)(&DAT_00387fac);
  FUN_00101748(param_1,&DAT_002cc260);
  FUN_001016c0(param_1 + 0x20,&DAT_002cc260);
  FUN_002264e8(param_1 + 0x34);
  *param_1 = (unsigned int)(&DAT_003b23ac);
  param_1[0x34] = (unsigned int)(&DAT_003b23f0);
  param_1[0x41] = 0;
  param_1[0x35] = 0;
  param_1[0x36] = 0;
  param_1[0x37] = 0;
  param_1[0x38] = 0;
  param_1[0x39] = 0;
  param_1[0x3a] = 0;
  return param_1;
}
