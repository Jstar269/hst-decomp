/* HSTMATCH module=hstp_trans_main.prx start=0x0020a040 end=0x0020a080 symbol=FUN_0020a040 lang=c99 */
/* Clone of src/eboot/FUN_001cd88c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/flow_state.h"

extern void FUN_0020a090();

/* Enter `state`; a timer below 1 clears the timer, otherwise it is stored. */
void FUN_0020a040(FlowState *self,u32 state,int timer)
{
  self->state = state;
  if (timer < 1) {
    FUN_0020a090();
    self->unk08 = 0xffffffff;
  }
  else {
    self->timer = timer;
  }
}
