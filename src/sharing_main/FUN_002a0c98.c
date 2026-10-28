/* HSTMATCH module=hstp_trans_main.prx start=0x002a0c98 end=0x002a0cf4 symbol=FUN_002a0c98 lang=c99 */
/* Clone of src/eboot/FUN_0008b1e8.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b304c;
extern void FUN_00000a00();
extern u32 * FUN_00268630();

u32 * FUN_002a0c98(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b304c);
    FUN_00268630(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
