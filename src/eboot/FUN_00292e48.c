/* HSTMATCH module=EBOOT.BIN start=0x00292e48 end=0x00292e60 symbol=FUN_00292e48 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag u1ge) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/slot_list_obj.h"

/* Reset: both float fields to 30.0f, other fields cleared. */
void FUN_00292e48(SlotListObj *self)
{
  self->unk40 = 0;
  self->unk04 = 0x41f00000;
  self->unk08 = 0x41f00000;
  self->unk38 = 0;
}
