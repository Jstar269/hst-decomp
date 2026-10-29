/* HSTMATCH module=EBOOT.BIN start=0x001cd88c end=0x001cd8cc symbol=FUN_001cd88c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/flow_state.h"

extern void FUN_001ce864();

/* Enter `state`; a timer below 1 clears the timer, otherwise it is stored. */
void FUN_001cd88c(FlowState *self,u32 state,int timer)
{
  self->state = state;
  if (timer < 1) {
    FUN_001ce864();
    self->unk08 = 0xffffffff;
  }
  else {
    self->timer = timer;
  }
}
