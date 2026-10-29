/* HSTMATCH module=EBOOT.BIN start=0x001a41d0 end=0x001a4224 symbol=FUN_001a41d0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: inverted dispatch condition; readability pass; exact match verified; names and types await human review. */
#include "hst/slot_select.h"

extern void FUN_0016b998();

/* restore == 0: put the saved cursor back; otherwise act on the selected slot's id. */
void FUN_001a41d0(SlotSelect *self,int restore)
{
  if (restore != 0) {
    FUN_0016b998(*self->slots[self->cursor.index]);
  }
  else {
    self->cursor.row = self->cursorSaved.row;
    self->cursor.index = self->cursorSaved.index;
    self->cursor.top = self->cursorSaved.top;
  }
}
