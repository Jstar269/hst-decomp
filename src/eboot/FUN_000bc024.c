/* HSTMATCH module=EBOOT.BIN start=0x000bc024 end=0x000bc098 symbol=FUN_000bc024 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag q4); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003073d8;
extern void FUN_00000a00();
extern void FUN_000104e0();

u32 * FUN_000bc024(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003073d8);
    if ((param_1[3] != 0) && (param_1[3] != 0)) {
      FUN_000104e0(param_1[3]);
      param_1[3] = 0;
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
