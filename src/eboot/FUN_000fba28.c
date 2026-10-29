/* HSTMATCH module=EBOOT.BIN start=0x000fba28 end=0x000fba88 symbol=FUN_000fba28 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/mode_screen.h"

extern u8 DAT_00307744;
extern ModeScreen * DAT_00338c24;
extern u32 * FUN_0001f06c();

/* Constructor: set the vtable, register as the active instance and clear every field. */
ModeScreen * FUN_000fba28(ModeScreen *self)
{
  FUN_0001f06c();
  self->vtbl = &DAT_00307744;
  self->core = 0;
  DAT_00338c24 = self;
  self->slot[0] = 0;
  self->slot[1] = 0;
  self->slot[2] = 0;
  self->slot[3] = 0;
  self->slot[4] = 0;
  self->slot[5] = 0;
  self->active = 0;
  self->timer = 0;
  return self;
}
