/* HSTMATCH module=EBOOT.BIN start=0x001fc374 end=0x001fc3dc symbol=FUN_001fc374 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00309534;
extern void FUN_00000a00();
extern u32 * FUN_0001f0f0();
extern void FUN_001fc4e8();

u32 * FUN_001fc374(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_00309534);
    FUN_001fc4e8(param_1,1);
    FUN_0001f0f0(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
