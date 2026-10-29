/* HSTMATCH module=EBOOT.BIN start=0x000e1610 end=0x000e1674 symbol=FUN_000e1610 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003076ac;
extern void FUN_00000a00();
extern u32 * FUN_0001f0f0();
extern void FUN_000e172c();

/* Destructor: resets the vtable word, runs the member and base destructors, frees the object when flags > 0. */
u32 * FUN_000e1610(u32 *self,short flags)
{
  if (self != (u32 *)0x0) {
    *self = (unsigned int)(&DAT_003076ac);
    FUN_000e172c();
    FUN_0001f0f0(self,0);
    if (0 < flags) {
      FUN_00000a00(self);
    }
  }
  return self;
}
