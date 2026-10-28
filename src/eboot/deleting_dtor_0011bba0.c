/* HSTMATCH module=EBOOT.BIN start=0x0011bba0 end=0x0011bc2c symbol=FUN_0011bba0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: the cleared flag global DAT_0033b488 typed as a byte; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0030702c;
extern u8 DAT_00307fc4;
extern unsigned char DAT_0033b488;
extern u32 DAT_0033b48c;
extern void FUN_00000a00();
extern u32 * FUN_0001f0f0();
extern u32 * FUN_0005a410();

u32 * FUN_0011bba0(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_00307fc4);
    DAT_0033b488 = 0;
    DAT_0033b48c = 0;
    if (param_1 + 0x10 != (u32 *)0x0) {
      param_1[0x10] = (unsigned int)(&DAT_0030702c);
      FUN_0005a410(param_1 + 0x10,0);
    }
    FUN_0001f0f0(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
