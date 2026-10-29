/* HSTMATCH module=EBOOT.BIN start=0x001a42b8 end=0x001a4334 symbol=FUN_001a42b8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: inverted dispatch condition and widened comparison flag to int; readability pass; exact match verified; names and types await human review. */
#include "hst/slot_select.h"

extern void FUN_0016baa0();
extern int FUN_001a4334();

/* pick != 0: apply the second list's selected id (a random one when unset); otherwise restore its cursor. */
void FUN_001a42b8(SlotSelect *self,int pick)
{
  int wasUnset;
  int id;
  
  if (pick != 0) {
    id = *self->idTable[self->listCursor.index];
    wasUnset = id == SLOT_SELECT_ID_NONE;
    if (wasUnset) {
      id = FUN_001a4334();
    }
    FUN_0016baa0(id,wasUnset);
  }
  else {
    self->listCursor.row = self->listCursorSaved.row;
    self->listCursor.index = self->listCursorSaved.index;
    self->listCursor.top = self->listCursorSaved.top;
  }
}
