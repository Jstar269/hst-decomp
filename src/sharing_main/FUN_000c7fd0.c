/* HSTMATCH module=hstp_trans_main.prx start=0x000c7fd0 end=0x000c803c symbol=FUN_000c7fd0 lang=c99 */
/* Clone of src/eboot/FUN_000c4734.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b06fc;
extern u32 DAT_003e1e30;
extern void FUN_00000a00();
extern u32 * FUN_0001ed28();
extern void FUN_000c803c();

u32 * FUN_000c7fd0(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b06fc);
    FUN_000c803c();
    DAT_003e1e30 = 0;
    FUN_0001ed28(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
