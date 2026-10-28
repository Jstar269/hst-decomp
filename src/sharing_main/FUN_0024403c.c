/* HSTMATCH module=hstp_trans_main.prx start=0x0024403c end=0x002440c4 symbol=FUN_0024403c lang=c99 */
/* Clone of src/eboot/FUN_00233f3c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b2b28;
extern u32 DAT_003f3994;
extern u32 DAT_003f3998;
extern void FUN_00000a00();
extern u32 * FUN_0001ed28();
extern int FUN_00242d58();

u32 * FUN_0024403c(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b2b28);
    DAT_003f3998 = 0;
    if (DAT_003f3994 != 0) {
      FUN_00242d58(DAT_003f3994,1);
      DAT_003f3994 = 0;
    }
    FUN_0001ed28(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
