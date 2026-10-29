/* HSTMATCH module=hstp_trans_main.prx start=0x002b3ba0 end=0x002b3c08 symbol=FUN_002b3ba0 lang=c99 */
/* Clone of src/eboot/FUN_002a4488.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/state_owner.h"

extern RequestFlags * DAT_003ea8e8;
extern void FUN_002b1820();

/* First request only: switch to mode 0 and tell the handler, unless the owner is locked. */
void FUN_002b3ba0(StateOwner *self)
{
  u32 flags;
  
  flags = DAT_003ea8e8->flags;
  if (((flags & MODE_REQUESTED_0) == 0) &&
     (DAT_003ea8e8->flags = flags | MODE_REQUESTED_0, self->state != OWNER_STATE_LOCKED)) {
    self->prevMode = self->mode;
    self->mode = 0;
    self->unk1bc = 0;
    FUN_002b1820(self,1);
  }
}
