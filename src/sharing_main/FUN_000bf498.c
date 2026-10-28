/* HSTMATCH module=hstp_trans_main.prx start=0x000bf498 end=0x000bf50c symbol=FUN_000bf498 lang=c99 */
/* Clone of src/eboot/FUN_000bc024.c (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b06a4;
extern void FUN_00000a00();
extern void FUN_000104e0();

u32 * FUN_000bf498(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b06a4);
    if ((param_1[3] != 0) && (param_1[3] != 0)) {
      FUN_000104e0(param_1[3]);
      param_1[3] = 0;
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
