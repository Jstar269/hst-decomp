/* HSTMATCH module=EBOOT.BIN start=0x002a4488 end=0x002a44f0 symbol=FUN_002a4488 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/state_owner.h"

extern RequestFlags * DAT_003415a8;
extern void FUN_002a2488();

/* First request only: switch to mode 0 and tell the handler, unless the owner is locked. */
void FUN_002a4488(StateOwner *self)
{
  u32 flags;
  
  flags = DAT_003415a8->flags;
  if (((flags & MODE_REQUESTED_0) == 0) &&
     (DAT_003415a8->flags = flags | MODE_REQUESTED_0, self->state != OWNER_STATE_LOCKED)) {
    self->prevMode = self->mode;
    self->mode = 0;
    self->unk1bc = 0;
    FUN_002a2488(self,1);
  }
}
