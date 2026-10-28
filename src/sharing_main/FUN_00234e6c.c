/* HSTMATCH module=hstp_trans_main.prx start=0x00234e6c end=0x00234f04 symbol=FUN_00234e6c lang=c99 */
/* Clone of src/eboot/FUN_002258f8.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b28d4;
extern u32 DAT_003f3610;
extern u32 DAT_003f3b50;
extern void FUN_00000a00();
extern u32 * FUN_0001ed28();
extern int * FUN_002347fc();
extern void FUN_002a32e8();

u32 * FUN_00234e6c(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b28d4);
    DAT_003f3610 = 0;
    if ((int *)param_1[0xf] != (int *)0x0) {
      FUN_002347fc((int *)param_1[0xf],1);
      param_1[0xf] = 0;
    }
    if (DAT_003f3b50 != 0) {
      FUN_002a32e8(DAT_003f3b50);
    }
    FUN_0001ed28(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
