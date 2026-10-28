/* HSTMATCH module=EBOOT.BIN start=0x00155ed8 end=0x00155f34 symbol=FUN_00155ed8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00308508;
extern void FUN_00000a00();
extern u32 * FUN_0014c40c();

u32 * FUN_00155ed8(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_00308508);
    FUN_0014c40c(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
