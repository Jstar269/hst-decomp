/* HSTMATCH module=hstp_trans_main.prx start=0x0020a014 end=0x0020a040 symbol=FUN_0020a014 lang=c99 */
/* Clone of src/eboot/FUN_001cd810.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/flow_state.h"

extern u8 DAT_003b27dc;

/* Constructor of the state record's base part. */
FlowState * FUN_0020a014(FlowState *self)
{
  self->vtable = (unsigned int)(&DAT_003b27dc);
  self->unk04 = 0xffffffff;
  self->unk08 = 0;
  self->timer = 0;
  self->state = 0;
  self->unk14 = 0;
  return self;
}
