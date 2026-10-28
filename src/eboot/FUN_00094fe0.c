/* HSTMATCH module=EBOOT.BIN start=0x00094fe0 end=0x0009503c symbol=FUN_00094fe0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00307278;
extern void FUN_00000a00();
extern u32 * FUN_00056cb0();

u32 * FUN_00094fe0(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_00307278);
    FUN_00056cb0(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
