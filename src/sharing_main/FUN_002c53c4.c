/* HSTMATCH module=hstp_trans_main.prx start=0x002c53c4 end=0x002c5450 symbol=FUN_002c53c4 lang=c99 */
/* Clone of src/eboot/FUN_002b56ec.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b32a0;
extern u32 DAT_003f491c;
extern void FUN_00000788();
extern void FUN_00000a00();
extern u32 * FUN_0001ed28();
extern u32 * FUN_000519d4();
extern void FUN_0005bbd8();

u32 * FUN_002c53c4(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b32a0);
    DAT_003f491c = 0;
    FUN_00000788(param_1 + 0x24,FUN_0005bbd8,0x70,0x14);
    FUN_000519d4(param_1 + 0x10,0xffffffff);
    FUN_0001ed28(param_1,0);
    if (param_2 > 0) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
