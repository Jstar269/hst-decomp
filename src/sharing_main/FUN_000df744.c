/* HSTMATCH module=hstp_trans_main.prx start=0x000df744 end=0x000df7a8 symbol=FUN_000df744 lang=c99 */
/* Clone of src/eboot/FUN_000db724.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b08c4;
extern u32 DAT_003e1e84;
extern void FUN_00000a00();
extern u32 * FUN_0001ed28();

u32 * FUN_000df744(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b08c4);
    DAT_003e1e84 = 0;
    FUN_0001ed28(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
