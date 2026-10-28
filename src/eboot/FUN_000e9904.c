/* HSTMATCH module=EBOOT.BIN start=0x000e9904 end=0x000e9980 symbol=FUN_000e9904 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128b); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0030770c;
extern void FUN_00000788();
extern void FUN_00000a00();
extern u32 * FUN_0001f0f0();
extern void FUN_000e99d4();
extern void FUN_000e7494();

u32 * FUN_000e9904(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_0030770c);
    FUN_000e99d4();
    FUN_00000788(param_1 + 0x154,FUN_000e7494,0x50,2);
    FUN_0001f0f0(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
