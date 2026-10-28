/* HSTMATCH module=EBOOT.BIN start=0x00115788 end=0x00115800 symbol=FUN_00115788 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00307bd8;
extern void FUN_00000a00();
extern u32 * FUN_00102ea4();
extern int * FUN_001163a8();

u32 * FUN_00115788(u32 *param_1,short param_2)
{
  u32 *puVar1;
  
  if (param_1 != (u32 *)0x0) {
    puVar1 = param_1 + 0x23;
    *param_1 = (unsigned int)(&DAT_00307bd8);
    if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
      FUN_001163a8(puVar1,0);
    }
    FUN_00102ea4(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
