/* HSTMATCH module=EBOOT.BIN start=0x0025e500 end=0x0025e568 symbol=FUN_0025e500 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v0) corrected by hand: modeled the resource pointer at +0x20 as a direct field store; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0030779c;
extern void FUN_00000a00();
extern u32 * FUN_00100b24();

struct ResourceSlot { char padding[0x20]; u8 *resource; };

int FUN_0025e500(int param_1,short param_2)
{
  if (param_1 != 0) {
    if (param_1 + 0x20 != 0) {
      ((struct ResourceSlot *)param_1)->resource = &DAT_0030779c;
      FUN_00100b24(param_1 + 0x20,0);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
