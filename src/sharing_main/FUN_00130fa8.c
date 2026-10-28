/* HSTMATCH module=hstp_trans_main.prx start=0x00130fa8 end=0x00131004 symbol=FUN_00130fa8 lang=c99 */
/* Clone of src/eboot/FUN_0008b1e8.c (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b12e4;
extern void FUN_00000a00();
extern u32 * FUN_00061d00();

u32 * FUN_00130fa8(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b12e4);
    FUN_00061d00(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
