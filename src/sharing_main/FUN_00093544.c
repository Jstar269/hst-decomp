/* HSTMATCH module=hstp_trans_main.prx start=0x00093544 end=0x000935b4 symbol=FUN_00093544 lang=c99 */
/* Clone of src/eboot/FUN_000918ac.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b0530;
extern void FUN_00000a00();
extern void FUN_00093860();
extern int FUN_000963a0();

u32 * FUN_00093544(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b0530);
    FUN_00093860();
    FUN_000963a0(param_1 + 0x2c,0xffffffff);
    FUN_000963a0(param_1 + 0x20,0xffffffff);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
