/* HSTMATCH module=hstp_trans_main.prx start=0x0029bb1c end=0x0029bbe8 symbol=FUN_0029bb1c lang=c++ */
/* Clone of src/eboot/FUN_0028a328.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/effect_source.h"

extern "C" {
extern char DAT_003b2ff0;
extern void FUN_00000a00(...);
extern void * FUN_00297f98(...);
extern void * FUN_0029e038(...);
}
struct VC_0 { virtual ~VC_0(); };
struct VC_1 { virtual ~VC_1(); };

/* Deleting destructor: frees both model holders, the record vector, then the base. */
extern "C" EffectSource * FUN_0029bb1c(EffectSource *self,short flags)
{
  VC_0 *holder;
  VC_1 *holderA;
  EffectRecVec *recs;
  
  if (self != (EffectSource *)0x0) {
    self->vtable = &DAT_003b2ff0;
    holder = (VC_0 *)self->modelB;
    if (holder != (VC_0 *)0x0) {
      delete holder;
      self->modelB = 0;
    }
    holderA = (VC_1 *)self->modelA;
    if (holderA != (VC_1 *)0x0) {
      delete holderA;
      self->modelA = 0;
    }
    recs = &self->recs;
    if ((recs != (EffectRecVec *)0x0) && (recs != (EffectRecVec *)0x0)) {
      FUN_0029e038(recs,0);
    }
    FUN_00297f98(self,0);
    if (0 < flags) {
      FUN_00000a00(self);
    }
  }
  return self;
}
