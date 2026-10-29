/* HSTMATCH module=hstp_trans_main.prx start=0x001b1780 end=0x001b179c symbol=FUN_001b1780 lang=c99 */
/* Clone of src/eboot/FUN_001a41b4.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/slot_select.h"

/* Remember the current cursor. */
void FUN_001b1780(SlotSelect *self)
{
  self->cursorSaved.row = self->cursor.row;
  self->cursorSaved.index = self->cursor.index;
  self->cursorSaved.top = self->cursor.top;
}
