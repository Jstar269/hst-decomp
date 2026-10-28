/* HSTMATCH module=EBOOT.BIN start=0x002258f8 end=0x00225990 symbol=FUN_002258f8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag u1ge); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00309608;
extern u32 DAT_0034a2e0;
extern u32 DAT_0034a820;
extern void FUN_00000a00();
extern u32 * FUN_0001f0f0();
extern int * FUN_00225288();
extern void FUN_00291cdc();

u32 * FUN_002258f8(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_00309608);
    DAT_0034a2e0 = 0;
    if ((int *)param_1[0xf] != (int *)0x0) {
      FUN_00225288((int *)param_1[0xf],1);
      param_1[0xf] = 0;
    }
    if (DAT_0034a820 != 0) {
      FUN_00291cdc(DAT_0034a820);
    }
    FUN_0001f0f0(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
