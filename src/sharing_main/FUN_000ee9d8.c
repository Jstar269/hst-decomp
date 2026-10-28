/* HSTMATCH module=hstp_trans_main.prx start=0x000ee9d8 end=0x000eea54 symbol=FUN_000ee9d8 lang=c99 */
/* Clone of src/eboot/FUN_000e9904.c (hstclone.py tag x11): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b09d8;
extern void FUN_00000788();
extern void FUN_00000a00();
extern u32 * FUN_0001ed28();
extern void FUN_000eeaa8();
extern void FUN_000ec490();

u32 * FUN_000ee9d8(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b09d8);
    FUN_000eeaa8();
    FUN_00000788(param_1 + 0x154,FUN_000ec490,0x50,2);
    FUN_0001ed28(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
