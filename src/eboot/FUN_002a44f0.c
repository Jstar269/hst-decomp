/* HSTMATCH module=EBOOT.BIN start=0x002a44f0 end=0x002a4558 symbol=FUN_002a44f0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/state_owner.h"

extern RequestFlags * DAT_003415a8;
extern void FUN_002a2488();

/* First request only: switch to mode 1 and tell the handler, unless the owner is locked. */
void FUN_002a44f0(StateOwner *self,u32 unused2,u32 unused3,int *extra4,u32 extra5, u32 extra6,u32 extra7,u32 extra8)
{
  u32 *flags;
  
  flags = &DAT_003415a8->flags;
  if (((*flags & MODE_REQUESTED_1) == 0) && (*flags = *flags | MODE_REQUESTED_1, self->state != OWNER_STATE_LOCKED)) {
    self->prevMode = self->mode;
    self->mode = 1;
    self->unk1bc = 0;
    FUN_002a2488(self,1,flags,extra4,extra5,extra6,extra7,extra8);
  }
}
