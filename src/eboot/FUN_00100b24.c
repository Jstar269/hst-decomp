/* HSTMATCH module=EBOOT.BIN start=0x00100b24 end=0x00100bb4 symbol=FUN_00100b24 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s256a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00307b6c;
extern void FUN_00000a00();
extern int * FUN_000fc284();
extern int * FUN_000fc2ec();
extern void FUN_00100bb4();

u32 * FUN_00100b24(u32 *param_1,short param_2)
{
  u32 *puVar1;
  
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_00307b6c);
    FUN_00100bb4();
    puVar1 = param_1 + 4;
    if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
      FUN_000fc2ec(puVar1,0);
    }
    puVar1 = param_1 + 1;
    if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
      FUN_000fc284(puVar1,0);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
