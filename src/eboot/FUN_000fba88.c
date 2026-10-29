/* HSTMATCH module=EBOOT.BIN start=0x000fba88 end=0x000fbaf4 symbol=FUN_000fba88 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/mode_screen.h"

extern u8 DAT_00307744;
extern ModeScreen * DAT_00338c24;
extern void FUN_00000a00();
extern u32 * FUN_0001f0f0();
extern void FUN_000fbbf8();

/* Destructor: unregister the active instance; free the object when the flag is positive. */
ModeScreen * FUN_000fba88(ModeScreen *self,short deleteFlag)
{
  if (self != (ModeScreen *)0x0) {
    self->vtbl = &DAT_00307744;
    DAT_00338c24 = 0;
    FUN_000fbbf8();
    FUN_0001f0f0(self,0);
    if (0 < deleteFlag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
