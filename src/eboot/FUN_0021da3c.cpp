/* HSTMATCH module=EBOOT.BIN start=0x0021da3c end=0x0021dad4 symbol=FUN_0021da3c lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/lobby_gauge.h"

extern "C" {
extern char DAT_00309744;
extern void FUN_00000a00(void *);
extern void FUN_00102ea4(void *, int);
extern void FUN_0021dbbc(LobbyGauge *);
}
struct VC_0 { virtual ~VC_0(); };

/* LobbyGauge deleting destructor: releases the sound handle, deletes the parts pane, destroys both pane bases. */
extern "C" LobbyGauge * FUN_0021da3c(LobbyGauge *self,short flag)
{
  PartsPane *parts;
  
  if (self != (LobbyGauge *)0x0) {
    self->vtbl = &DAT_00309744;
    FUN_0021dbbc(self);
    parts = self->parts;
    if (parts != (PartsPane *)0x0) {
      delete ((VC_0 *)(parts));
      self->parts = 0;
    }
    FUN_00102ea4(self->pane174,0xffffffff);
    FUN_00102ea4(self,0);
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
