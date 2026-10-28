/* HSTMATCH module=EBOOT.BIN start=0x000e1584 end=0x000e1610 symbol=FUN_000e1584 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002d6b10;
extern u8 DAT_003076ac;
extern u32 * FUN_0001f06c();
extern void FUN_000e1674();
extern void FUN_000e1798();

u32 * FUN_000e1584(u32 *param_1,u32 param_2,u32 param_3,int param_4)
{
  FUN_0001f06c(param_1);
  *param_1 = (unsigned int)(&DAT_003076ac);
  param_1[0x15] = 0;
  param_1[0x10] = 0;
  param_1[0x16] = param_2;
  param_1[0x11] = param_3;
  param_1[0xf] = (unsigned int)(&DAT_002d6b10);
  if (param_4 != 0) {
    param_1[0xf] = param_4;
  }
  FUN_000e1674((int)param_1);
  FUN_000e1798(param_1);
  return param_1;
}
