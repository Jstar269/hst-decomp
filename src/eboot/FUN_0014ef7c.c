/* HSTMATCH module=EBOOT.BIN start=0x0014ef7c end=0x0014efd8 symbol=FUN_0014ef7c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003083f0;
extern u8 DAT_00308460;
extern void FUN_00000a00();

u32 * FUN_0014ef7c(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003083f0);
    if (param_1 != (u32 *)0x0) {
      *param_1 = (unsigned int)(&DAT_00308460);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
