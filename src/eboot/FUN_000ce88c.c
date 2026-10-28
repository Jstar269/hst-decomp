/* HSTMATCH module=EBOOT.BIN start=0x000ce88c end=0x000ce8e8 symbol=FUN_000ce88c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0030753c;
extern u8 DAT_00307550;
extern void FUN_00000a00();

u32 * FUN_000ce88c(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_00307550);
    if (param_1 != (u32 *)0x0) {
      *param_1 = (unsigned int)(&DAT_0030753c);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
