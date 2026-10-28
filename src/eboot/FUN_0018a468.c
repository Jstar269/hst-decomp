/* HSTMATCH module=EBOOT.BIN start=0x0018a468 end=0x0018a4f4 symbol=FUN_0018a468 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s256a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0030779c;
extern u8 DAT_003090e0;
extern u8 DAT_00309124;
extern void FUN_00000a00();
extern u32 * FUN_00100b24();
extern u32 * FUN_00217474();

u32 * FUN_0018a468(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003090e0);
    param_1[0x34] = (unsigned int)(&DAT_00309124);
    FUN_00217474(param_1 + 0x34,0);
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
