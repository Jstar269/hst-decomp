/* HSTMATCH module=hstp_trans_main.prx start=0x001b1868 end=0x001b1884 symbol=FUN_001b1868 lang=c99 */
/* Clone of src/eboot/FUN_001a429c.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/slot_select.h"

/* Remember the second list's cursor. */
void FUN_001b1868(SlotSelect *self)
{
  self->listCursorSaved.row = self->listCursor.row;
  self->listCursorSaved.index = self->listCursor.index;
  self->listCursorSaved.top = self->listCursor.top;
}
