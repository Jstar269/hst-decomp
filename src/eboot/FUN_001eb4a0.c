/* HSTMATCH module=EBOOT.BIN start=0x001eb4a0 end=0x001eb4fc symbol=FUN_001eb4a0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003094a0;
extern void FUN_00000a00();
extern u32 * FUN_00102ea4();

u32 * FUN_001eb4a0(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003094a0);
    FUN_00102ea4(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
