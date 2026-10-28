/* HSTMATCH module=EBOOT.BIN start=0x0027cae4 end=0x0027cb40 symbol=FUN_0027cae4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00309c34;
extern void FUN_00000a00();
extern u32 * FUN_00060e7c();

u32 * FUN_0027cae4(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_00309c34);
    FUN_00060e7c(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
