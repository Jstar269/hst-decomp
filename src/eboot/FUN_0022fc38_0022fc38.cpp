/* HSTMATCH module=EBOOT.BIN start=0x0022fc38 end=0x0022fcdc symbol=FUN_0022fc38 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/stateful_pane.h"

extern "C" {
extern u32 DAT_0034a81c;
extern StateMgr * DAT_0034b350;
extern void FUN_001031e8(void *);
extern void FUN_0015df28(void *);
extern void FUN_002917ac(u32);
}

/* State 5: call FUN_002917ac on the global; otherwise, unless the object at DAT_0034b350 is busy (busy),
   refresh the pane, its sub record and (when the flag is set) slot 3 of node 214. */
extern "C" void FUN_0022fc38(StatefulPane *self)
{
  if (self->state == 5) {
    FUN_002917ac(DAT_0034a81c);
  }
  else if ((DAT_0034b350 == 0) || (DAT_0034b350->busy == 0)) {
    FUN_001031e8(self);
    if (self->sub != 0) {
      FUN_0015df28(self->sub);
    }
    if ((self->unk54 != 0) && (self->node214 != 0)) {
      self->node214->slot3();
    }
  }
}
