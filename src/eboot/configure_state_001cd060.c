/* HSTMATCH module=EBOOT.BIN start=0x001cd060 end=0x001cd0d8 symbol=FUN_001cd060 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: used a signed status test and passed the third helper argument through the byte store; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/flow_state.h"

enum {
  FLOW_STATE_A = 7,
  FLOW_STATE_B = 0xb
};

extern int DAT_0034b590;
extern void FUN_001c2498();
extern void FUN_001cd88c();
extern void FUN_002ad938();

/* Enter state A (clearing two fields first) when DAT_0034b590 is positive, else state B. */
void FUN_001cd060(FlowOwner *self)
{
  u32 state_ptr;
  FlowState *state;
  
  FUN_002ad938();
  if (DAT_0034b590 > 0) {
    state = self->state;
    state->unke0 = 0;
    state->unke4 = 1;
    FUN_001cd88c(state,FLOW_STATE_A,1);
    FUN_001c2498(state);
  }
  else {
    state_ptr = (u32)self->state;
    FUN_001cd88c(state_ptr,FLOW_STATE_B,1);
    FUN_001c2498(state_ptr);
  }
  return;
}
