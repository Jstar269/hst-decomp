/* HSTMATCH module=EBOOT.BIN start=0x00292e60 end=0x00292eac symbol=FUN_00292e60 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/slot_list_obj.h"

extern u8 DAT_00309dcc;
extern u32 * FUN_00291a80();

SlotListObj * FUN_00292e60(SlotListObj *self)
{
  FUN_00291a80();
  self->vtable = (unsigned int)(&DAT_00309dcc);
  self->unk4c = 0;
  self->unk4d = 0;
  self->unk50 = 0;
  self->unk54 = 0;
  self->unk4e = 1;
  return self;
}
