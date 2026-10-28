/* HSTMATCH module=hstp_trans_main.prx start=0x001aa7b4 end=0x001aa810 symbol=FUN_001aa7b4 lang=c99 */
/* Clone of src/eboot/FUN_0008b1e8.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b251c;
extern void FUN_00000a00();
extern u32 * FUN_0001ed28();

u32 * FUN_001aa7b4(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b251c);
    FUN_0001ed28(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
