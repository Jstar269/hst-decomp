/* HSTMATCH module=EBOOT.BIN start=0x0017e654 end=0x0017e6c0 symbol=FUN_0017e654 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003090d4;
extern void FUN_00000a00();
extern int FUN_0005ba00();

u32 * FUN_0017e654(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003090d4);
    FUN_0005ba00(param_1 + 0xb8,0xffffffff);
    FUN_0005ba00(param_1 + 4,0xffffffff);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
