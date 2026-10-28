/* HSTMATCH module=EBOOT.BIN start=0x00158254 end=0x001582b0 symbol=FUN_00158254 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0030840c;
extern u8 DAT_003084ec;
extern void FUN_00000a00();

u32 * FUN_00158254(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003084ec);
    if (param_1 != (u32 *)0x0) {
      *param_1 = (unsigned int)(&DAT_0030840c);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
