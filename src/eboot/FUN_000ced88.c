/* HSTMATCH module=EBOOT.BIN start=0x000ced88 end=0x000cede4 symbol=FUN_000ced88 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003074f8;
extern void FUN_00000a00();
extern u32 * FUN_00056cb0();

u32 * FUN_000ced88(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003074f8);
    FUN_00056cb0(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
