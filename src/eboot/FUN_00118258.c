/* HSTMATCH module=EBOOT.BIN start=0x00118258 end=0x001182ac symbol=FUN_00118258 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/deque_owner.h"

extern u8 DAT_00307ffc;
extern DequeOwner * DAT_0033b460;
extern u32 * FUN_0001f06c();
extern u32 FUN_0011835c();
extern u32 FUN_00118424();
extern void FUN_00118598();

/* Constructor: builds the two containers and registers the object in the global DAT_0033b460. */
DequeOwner * FUN_00118258(DequeOwner *self)
{
  FUN_0001f06c();
  self->vtable = &DAT_00307ffc;
  FUN_00118424(&self->deque2e0);
  FUN_0011835c(&self->deque2f8);
  DAT_0033b460 = self;
  FUN_00118598(self);
  return self;
}
