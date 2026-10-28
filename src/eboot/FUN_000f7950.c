/* HSTMATCH module=EBOOT.BIN start=0x000f7950 end=0x000f79b8 symbol=FUN_000f7950 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0030777c;
extern void FUN_00000a00();
extern void FUN_000f7e30();
extern u32 * FUN_00102ea4();

u32 * FUN_000f7950(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_0030777c);
    FUN_000f7e30(param_1,1);
    FUN_00102ea4(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
