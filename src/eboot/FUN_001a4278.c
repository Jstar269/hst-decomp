/* HSTMATCH module=EBOOT.BIN start=0x001a4278 end=0x001a4294 symbol=FUN_001a4278 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/slot_select.h"

void FUN_001a4278(SlotSelect *self)
{
  self->unk2e4Saved = self->unk2e4;
  self->unk2ecSaved = self->unk2ec;
  self->modeSaved = self->mode;
}
