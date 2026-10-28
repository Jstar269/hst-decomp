/* HSTMATCH module=hstp_trans_main.prx start=0x000e5aec end=0x000e5b78 symbol=FUN_000e5aec lang=c99 */
/* Clone of src/eboot/FUN_000e1584.c (hstclone.py tag c32): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0037d870;
extern u8 DAT_003b0978;
extern u32 * FUN_0001ec44();
extern void FUN_000e5bdc();
extern void FUN_000e5d60();

u32 * FUN_000e5aec(u32 *param_1,u32 param_2,u32 param_3,int param_4)
{
  FUN_0001ec44(param_1);
  *param_1 = (unsigned int)(&DAT_003b0978);
  param_1[0x15] = 0;
  param_1[0x10] = 0;
  param_1[0x16] = param_2;
  param_1[0x11] = param_3;
  param_1[0xf] = (unsigned int)(&DAT_0037d870);
  if (param_4 != 0) {
    param_1[0xf] = param_4;
  }
  FUN_000e5bdc((int)param_1);
  FUN_000e5d60(param_1);
  return param_1;
}
