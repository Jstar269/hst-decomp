/* HSTMATCH module=EBOOT.BIN start=0x001fb8fc end=0x001fb928 symbol=FUN_001fb8fc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/state_switch.h"

extern u8 DAT_00309510;

/* Constructor: no state selected yet, everything else cleared. */
StateSwitch * FUN_001fb8fc(StateSwitch *self)
{
  self->vtable = &DAT_00309510;
  self->state = STATE_SWITCH_NONE;
  self->unk08 = 0;
  self->duration = 0;
  self->next_state = 0;
  self->prev_state = 0;
  return self;
}
