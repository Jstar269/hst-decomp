/* HSTMATCH module=EBOOT.BIN start=0x001a41b4 end=0x001a41d0 symbol=FUN_001a41b4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/slot_select.h"

/* Remember the current cursor. */
void FUN_001a41b4(SlotSelect *self)
{
  self->cursorSaved.row = self->cursor.row;
  self->cursorSaved.index = self->cursor.index;
  self->cursorSaved.top = self->cursor.top;
}
