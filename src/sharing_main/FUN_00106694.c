/* HSTMATCH module=hstp_trans_main.prx start=0x00106694 end=0x001066f0 symbol=FUN_00106694 lang=c99 */
/* Clone of src/eboot/FUN_0008b1e8.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b0e24;
extern void FUN_00000a00();
extern u32 * FUN_000519d4();

u32 * FUN_00106694(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b0e24);
    FUN_000519d4(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
