/* HSTMATCH module=hstp_trans_main.prx start=0x002a4a94 end=0x002a4af8 symbol=FUN_002a4a94 lang=c99 */
/* Clone of src/eboot/FUN_000e1610.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b30d4;
extern void FUN_00000a00();
extern u32 * FUN_00297f98();
extern void FUN_002a4af8();

u32 * FUN_002a4a94(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b30d4);
    FUN_002a4af8();
    FUN_00297f98(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
