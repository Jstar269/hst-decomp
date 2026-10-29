/* HSTMATCH module=EBOOT.BIN start=0x001cd810 end=0x001cd83c symbol=FUN_001cd810 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/flow_state.h"

extern u8 DAT_00309350;

/* Constructor of the state record's base part. */
FlowState * FUN_001cd810(FlowState *self)
{
  self->vtable = (unsigned int)(&DAT_00309350);
  self->unk04 = 0xffffffff;
  self->unk08 = 0;
  self->timer = 0;
  self->state = 0;
  self->unk14 = 0;
  return self;
}
