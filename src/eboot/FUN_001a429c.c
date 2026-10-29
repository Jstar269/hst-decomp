/* HSTMATCH module=EBOOT.BIN start=0x001a429c end=0x001a42b8 symbol=FUN_001a429c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/slot_select.h"

/* Remember the second list's cursor. */
void FUN_001a429c(SlotSelect *self)
{
  self->listCursorSaved.row = self->listCursor.row;
  self->listCursorSaved.index = self->listCursor.index;
  self->listCursorSaved.top = self->listCursor.top;
}
