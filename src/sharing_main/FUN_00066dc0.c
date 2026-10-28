/* HSTMATCH module=hstp_trans_main.prx start=0x00066dc0 end=0x00066e1c symbol=FUN_00066dc0 lang=c99 */
/* Clone of src/eboot/FUN_000b7dd8.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b03a8;
extern u8 DAT_003b0414;
extern void FUN_00000a00();

u32 * FUN_00066dc0(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b03a8);
    if (param_1 != (u32 *)0x0) {
      *param_1 = (unsigned int)(&DAT_003b0414);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
