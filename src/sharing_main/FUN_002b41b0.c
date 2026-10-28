/* HSTMATCH module=hstp_trans_main.prx start=0x002b41b0 end=0x002b4214 symbol=FUN_002b41b0 lang=c99 */
/* Clone of src/eboot/FUN_000db724.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b31ac;
extern u32 DAT_003f469c;
extern void FUN_00000a00();
extern u32 * FUN_0001ed28();

u32 * FUN_002b41b0(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b31ac);
    DAT_003f469c = 0;
    FUN_0001ed28(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
