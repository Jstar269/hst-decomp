/* HSTMATCH module=hstp_trans_main.prx start=0x0022cfb0 end=0x0022d048 symbol=FUN_0022cfb0 lang=c++ */
/* Clone of src/eboot/FUN_0021da3c.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/lobby_gauge.h"

extern "C" {
extern char DAT_003b2a10;
extern void FUN_00000a00(void *);
extern void FUN_001087a8(void *, int);
extern void FUN_0022d130(LobbyGauge *);
}
struct VC_0 { virtual ~VC_0(); };

/* LobbyGauge deleting destructor: releases the sound handle, deletes the parts pane, destroys both pane bases. */
extern "C" LobbyGauge * FUN_0022cfb0(LobbyGauge *self,short flag)
{
  PartsPane *parts;
  
  if (self != (LobbyGauge *)0x0) {
    self->vtbl = &DAT_003b2a10;
    FUN_0022d130(self);
    parts = self->parts;
    if (parts != (PartsPane *)0x0) {
      delete ((VC_0 *)(parts));
      self->parts = 0;
    }
    FUN_001087a8(self->pane174,0xffffffff);
    FUN_001087a8(self,0);
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
