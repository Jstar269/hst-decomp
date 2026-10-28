/* HSTMATCH module=hstp_trans_main.prx start=0x0018ad48 end=0x0018adb4 symbol=FUN_0018ad48 lang=c99 */
/* Clone of src/eboot/FUN_0017e654.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b23a0;
extern void FUN_00000a00();
extern int FUN_0005c688();

u32 * FUN_0018ad48(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b23a0);
    FUN_0005c688(param_1 + 0xb8,0xffffffff);
    FUN_0005c688(param_1 + 4,0xffffffff);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
