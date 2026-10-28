/* HSTMATCH module=EBOOT.BIN start=0x000e5650 end=0x000e56ac symbol=FUN_000e5650 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00307654;
extern void FUN_00000a00();
extern u32 * FUN_0001f0f0();

u32 * FUN_000e5650(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_00307654);
    FUN_0001f0f0(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
