/* HSTMATCH module=EBOOT.BIN start=0x00115c24 end=0x00115c90 symbol=FUN_00115c24 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0030779c;
extern u8 DAT_00307e7c;
extern void FUN_00000a00();
extern u32 * FUN_00100b24();

u32 * FUN_00115c24(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_00307e7c);
    if (param_1 != (u32 *)0x0) {
      *param_1 = (unsigned int)(&DAT_0030779c);
      FUN_00100b24(param_1,0);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
