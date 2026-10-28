/* HSTMATCH module=EBOOT.BIN start=0x0015878c end=0x001587e8 symbol=FUN_0015878c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0030840c;
extern u8 DAT_003086e4;
extern void FUN_00000a00();

u32 * FUN_0015878c(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003086e4);
    if (param_1 != (u32 *)0x0) {
      *param_1 = (unsigned int)(&DAT_0030840c);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
