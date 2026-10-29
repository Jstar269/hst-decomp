/* HSTMATCH module=EBOOT.BIN start=0x002a4a20 end=0x002a4a84 symbol=FUN_002a4a20 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/savedata_screen.h"

extern u8 DAT_00309ee0;
extern SaveScreen * DAT_0034b350;
extern void FUN_00000a00();
extern u32 * FUN_0001f0f0();

/* Destructor: unregister the active instance; free the object when the flag is positive. */
SaveScreen * FUN_002a4a20(SaveScreen *self,short deleteFlag)
{
  if (self != (SaveScreen *)0x0) {
    self->vtbl = &DAT_00309ee0;
    DAT_0034b350 = 0;
    FUN_0001f0f0(self,0);
    if (0 < deleteFlag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
