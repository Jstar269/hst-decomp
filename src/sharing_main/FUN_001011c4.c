/* HSTMATCH module=hstp_trans_main.prx start=0x001011c4 end=0x00101230 symbol=FUN_001011c4 lang=c99 */
/* Clone of src/eboot/FUN_000fba88.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b0a10;
extern u32 DAT_003e1f64;
extern void FUN_00000a00();
extern u32 * FUN_0001ed28();
extern void FUN_00101334();

u32 * FUN_001011c4(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b0a10);
    DAT_003e1f64 = 0;
    FUN_00101334();
    FUN_0001ed28(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
