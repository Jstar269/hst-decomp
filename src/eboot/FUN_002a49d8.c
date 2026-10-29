/* HSTMATCH module=EBOOT.BIN start=0x002a49d8 end=0x002a4a20 symbol=FUN_002a49d8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/savedata_screen.h"

extern u8 DAT_00309ee0;
extern SaveScreen * DAT_0034b350;
extern u32 * FUN_0001f06c();
extern void FUN_002a4f18();

/* Constructor: set the vtable, register as the active instance, enter the idle state. */
SaveScreen * FUN_002a49d8(SaveScreen *self)
{
  FUN_0001f06c();
  self->vtbl = &DAT_00309ee0;
  DAT_0034b350 = self;
  FUN_002a4f18(self,SAVE_STATE_IDLE);
  return self;
}
