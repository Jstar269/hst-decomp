/* HSTMATCH module=hstp_trans_main.prx start=0x00002d9c end=0x00002df8 symbol=FUN_00002d9c lang=c99 */
/* Clone of src/eboot/FUN_0008b1e8.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b01e8;
extern void FUN_00000a00();
extern u32 * FUN_00002c98();

u32 * FUN_00002d9c(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b01e8);
    FUN_00002c98(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
