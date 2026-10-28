/* HSTMATCH module=hstp_trans_main.prx start=0x0020aa8c end=0x0020aaf4 symbol=FUN_0020aa8c lang=c99 */
/* Clone of src/eboot/FUN_000f7950.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b2800;
extern void FUN_00000a00();
extern void FUN_0020ac00();
extern u32 * FUN_0001ed28();

u32 * FUN_0020aa8c(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b2800);
    FUN_0020ac00(param_1,1);
    FUN_0001ed28(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
