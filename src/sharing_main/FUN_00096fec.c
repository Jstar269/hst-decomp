/* HSTMATCH module=hstp_trans_main.prx start=0x00096fec end=0x00097048 symbol=FUN_00096fec lang=c99 */
/* Clone of src/eboot/FUN_0008b1e8.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b0544;
extern void FUN_00000a00();
extern u32 * FUN_00057904();

u32 * FUN_00096fec(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b0544);
    FUN_00057904(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
