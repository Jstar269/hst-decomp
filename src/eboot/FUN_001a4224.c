/* HSTMATCH module=EBOOT.BIN start=0x001a4224 end=0x001a4278 symbol=FUN_001a4224 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/slot_select.h"

extern void FUN_0016b998();

/* Act on the selected slot's id, then remember the cursor. */
void FUN_001a4224(SlotSelect *self)
{
  FUN_0016b998(*self->slots[self->cursor.index]);
  self->cursorSaved.row = self->cursor.row;
  self->cursorSaved.index = self->cursor.index;
  self->cursorSaved.top = self->cursor.top;
}
