/* HSTMATCH module=hstp_trans_main.prx start=0x001dbc38 end=0x001dbc60 symbol=FUN_001dbc38 lang=c99 */
/* Clone of src/eboot/FUN_001cd55c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/flow_state.h"

extern void FUN_0028d264();

/* Release the owner's resource, if any. */
void FUN_001dbc38(FlowOwner *self)
{
  if (self->res != 0) {
    FUN_0028d264(self->res->unk3c);
  }
}
