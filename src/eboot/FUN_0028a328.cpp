/* HSTMATCH module=EBOOT.BIN start=0x0028a328 end=0x0028a3f4 symbol=FUN_0028a328 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/effect_source.h"

extern "C" {
extern char DAT_00309d08;
extern void FUN_00000a00(...);
extern void * FUN_0028686c(...);
extern void * FUN_0028c870(...);
}
struct VC_0 { virtual ~VC_0(); };
struct VC_1 { virtual ~VC_1(); };

/* Deleting destructor: frees both model holders, the record vector, then the base. */
extern "C" EffectSource * FUN_0028a328(EffectSource *self,short flags)
{
  VC_0 *holder;
  VC_1 *holderA;
  EffectRecVec *recs;
  
  if (self != (EffectSource *)0x0) {
    self->vtable = &DAT_00309d08;
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
      FUN_0028c870(recs,0);
    }
    FUN_0028686c(self,0);
    if (0 < flags) {
      FUN_00000a00(self);
    }
  }
  return self;
}
