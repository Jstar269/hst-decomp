/* HSTMATCH module=EBOOT.BIN start=0x000f5c6c end=0x000f5cd8 symbol=FUN_000f5c6c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128b); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003077e0;
extern void FUN_00000788();
extern void FUN_00000a00();
extern void FUN_000510c0();

u32 * FUN_000f5c6c(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003077e0);
    FUN_00000788(param_1 + 1,FUN_000510c0,0x48,2);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
