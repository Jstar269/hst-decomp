/* HSTMATCH module=EBOOT.BIN start=0x00153e0c end=0x00153e68 symbol=FUN_00153e0c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003083cc;
extern u8 DAT_0030899c;
extern void FUN_00000a00();

u32 * FUN_00153e0c(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_0030899c);
    if (param_1 != (u32 *)0x0) {
      *param_1 = (unsigned int)(&DAT_003083cc);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
