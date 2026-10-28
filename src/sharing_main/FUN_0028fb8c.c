/* HSTMATCH module=hstp_trans_main.prx start=0x0028fb8c end=0x0028fc14 symbol=FUN_0028fb8c lang=c99 */
/* Clone of src/eboot/FUN_0027e748.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b2f64;
extern void FUN_00000a00();
extern int * FUN_000550a0();
extern int * FUN_00290840();

u32 * FUN_0028fb8c(u32 *param_1,short param_2)
{
  u32 *puVar1;
  
  if (param_1 != (u32 *)0x0) {
    puVar1 = param_1 + 4;
    *param_1 = (unsigned int)(&DAT_003b2f64);
    if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
      FUN_000550a0(puVar1,0);
    }
    puVar1 = param_1 + 1;
    if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
      FUN_00290840(puVar1,0);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
