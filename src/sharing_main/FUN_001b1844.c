/* HSTMATCH module=hstp_trans_main.prx start=0x001b1844 end=0x001b1860 symbol=FUN_001b1844 lang=c99 */
/* Clone of src/eboot/FUN_001a4278.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/slot_select.h"

void FUN_001b1844(SlotSelect *self)
{
  self->unk2e4Saved = self->unk2e4;
  self->unk2ecSaved = self->unk2ec;
  self->modeSaved = self->mode;
}
