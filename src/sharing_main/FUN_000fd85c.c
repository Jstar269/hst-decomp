/* HSTMATCH module=hstp_trans_main.prx start=0x000fd85c end=0x000fd8b8 symbol=FUN_000fd85c lang=c99 */
/* Clone of src/eboot/FUN_0008b1e8.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b0b60;
extern void FUN_00000a00();
extern u32 * FUN_001087a8();

u32 * FUN_000fd85c(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b0b60);
    FUN_001087a8(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
