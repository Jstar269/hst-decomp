/* HSTMATCH module=hstp_trans_main.prx start=0x000d26a0 end=0x000d2718 symbol=FUN_000d26a0 lang=c99 */
/* Clone of src/eboot/FUN_000ceaa4.c (hstclone.py tag x11): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b07ec;
extern void FUN_00000788();
extern void FUN_00000a00();
extern u32 * FUN_0001ed28();
extern void FUN_00057904();

u32 * FUN_000d26a0(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b07ec);
    FUN_00000788(param_1 + 0x10,FUN_00057904,0x1b0,3);
    FUN_0001ed28(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
