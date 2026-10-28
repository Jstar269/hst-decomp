/* HSTMATCH module=EBOOT.BIN start=0x0027e748 end=0x0027e7d0 symbol=FUN_0027e748 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s256a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00309c7c;
extern void FUN_00000a00();
extern int * FUN_00054554();
extern int * FUN_0027f3cc();

u32 * FUN_0027e748(u32 *param_1,short param_2)
{
  u32 *puVar1;
  
  if (param_1 != (u32 *)0x0) {
    puVar1 = param_1 + 4;
    *param_1 = (unsigned int)(&DAT_00309c7c);
    if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
      FUN_00054554(puVar1,0);
    }
    puVar1 = param_1 + 1;
    if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
      FUN_0027f3cc(puVar1,0);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
