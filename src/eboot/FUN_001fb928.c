/* HSTMATCH module=EBOOT.BIN start=0x001fb928 end=0x001fb968 symbol=FUN_001fb928 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/state_switch.h"

extern void FUN_001fb978(StateSwitch *self,u32 new_state);

/* Requests next_state: with length < 1 the switch is changed immediately (FUN_001fb978) and unk08 set to -1,
   otherwise duration is set to length. */
void FUN_001fb928(StateSwitch *self,u32 next_state,int length)
{
  self->next_state = next_state;
  if (length < 1) {
    FUN_001fb978(self,next_state);
    self->unk08 = 0xffffffff;
  }
  else {
    self->duration = length;
  }
}
