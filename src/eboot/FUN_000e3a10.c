/* HSTMATCH module=EBOOT.BIN start=0x000e3a10 end=0x000e3a74 symbol=FUN_000e3a10 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00307690;
extern void FUN_00000a00();
extern u32 * FUN_0001f0f0();
extern void FUN_000e3b2c();

u32 * FUN_000e3a10(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_00307690);
    FUN_000e3b2c();
    FUN_0001f0f0(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
