/* HSTMATCH module=hstp_trans_main.prx start=0x001dbeec end=0x001dbf18 symbol=FUN_001dbeec lang=c99 */
/* Clone of src/eboot/FUN_001cd810.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/flow_state.h"

extern u8 DAT_003b261c;

/* Constructor of the state record's base part. */
FlowState * FUN_001dbeec(FlowState *self)
{
  self->vtable = (unsigned int)(&DAT_003b261c);
  self->unk04 = 0xffffffff;
  self->unk08 = 0;
  self->timer = 0;
  self->state = 0;
  self->unk14 = 0;
  return self;
}
