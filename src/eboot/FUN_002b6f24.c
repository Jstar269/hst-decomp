/* HSTMATCH module=EBOOT.BIN start=0x002b6f24 end=0x002b6fac symbol=FUN_002b6f24 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s256a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00309ff0;
extern void FUN_00000a00();
extern int * FUN_00054554();
extern int * FUN_002b73e4();

u32 * FUN_002b6f24(u32 *param_1,short param_2)
{
  u32 *puVar1;
  
  if (param_1 != (u32 *)0x0) {
    puVar1 = param_1 + 4;
    *param_1 = (unsigned int)(&DAT_00309ff0);
    if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
      FUN_00054554(puVar1,0);
    }
    puVar1 = param_1 + 1;
    if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
      FUN_002b73e4(puVar1,0);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
