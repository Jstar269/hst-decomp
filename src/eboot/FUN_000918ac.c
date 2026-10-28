/* HSTMATCH module=EBOOT.BIN start=0x000918ac end=0x0009191c symbol=FUN_000918ac lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00307264;
extern void FUN_00000a00();
extern void FUN_00091bc8();
extern int FUN_0009447c();

u32 * FUN_000918ac(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_00307264);
    FUN_00091bc8();
    FUN_0009447c(param_1 + 0x2c,0xffffffff);
    FUN_0009447c(param_1 + 0x20,0xffffffff);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
