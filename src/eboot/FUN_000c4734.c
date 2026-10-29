/* HSTMATCH module=EBOOT.BIN start=0x000c4734 end=0x000c47a0 symbol=FUN_000c4734 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00307430;
extern u32 DAT_00338af0;
extern void FUN_00000a00();
extern u32 * FUN_0001f0f0();
extern void FUN_000c47a0();

/* Destructor: resets the vtable word, runs the cleanup, clears the global instance pointer, frees the object when flags > 0. */
u32 * FUN_000c4734(u32 *self,short flags)
{
  if (self != (u32 *)0x0) {
    *self = (unsigned int)(&DAT_00307430);
    FUN_000c47a0();
    DAT_00338af0 = 0;
    FUN_0001f0f0(self,0);
    if (0 < flags) {
      FUN_00000a00(self);
    }
  }
  return self;
}
