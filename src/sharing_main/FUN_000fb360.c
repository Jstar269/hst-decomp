/* HSTMATCH module=hstp_trans_main.prx start=0x000fb360 end=0x000fb3cc symbol=FUN_000fb360 lang=c99 */
/* Clone of src/eboot/FUN_000f5c6c.c (hstclone.py tag x11): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b0aac;
extern void FUN_00000788();
extern void FUN_00000a00();
extern void FUN_000519d4();

u32 * FUN_000fb360(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b0aac);
    FUN_00000788(param_1 + 1,FUN_000519d4,0x48,2);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
