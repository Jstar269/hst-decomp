/* HSTMATCH module=hstp_trans_main.prx start=0x001b17f0 end=0x001b1844 symbol=FUN_001b17f0 lang=c99 */
/* Clone of src/eboot/FUN_001a4224.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/slot_select.h"

extern void FUN_00177b5c();

/* Act on the selected slot's id, then remember the cursor. */
void FUN_001b17f0(SlotSelect *self)
{
  FUN_00177b5c(*self->slots[self->cursor.index]);
  self->cursorSaved.row = self->cursor.row;
  self->cursorSaved.index = self->cursor.index;
  self->cursorSaved.top = self->cursor.top;
}
