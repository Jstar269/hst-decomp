/* HSTMATCH module=EBOOT.BIN start=0x000d8474 end=0x000d84e0 symbol=FUN_000d8474 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128b); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003075e0;
extern void FUN_00000788();
extern void FUN_00000a00();
extern void FUN_000d8408();

u32 * FUN_000d8474(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003075e0);
    FUN_00000788(param_1 + 1,FUN_000d8408,0xc,6);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
