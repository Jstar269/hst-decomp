/* HSTMATCH module=EBOOT.BIN start=0x0013086c end=0x0013096c symbol=FUN_0013086c lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/timed_obj.h"

extern "C" {
extern u8 DAT_003081f0;
extern u32 DAT_00340284;
extern void FUN_00000a00(...);
extern u32 * FUN_0001f0f0(...);
extern int * FUN_00063e44(...);
extern void FUN_0013096c(...);
}
struct VC_0 { virtual ~VC_0(); };
struct VC_1 { virtual ~VC_1(); };
struct VC_2 { virtual ~VC_2(); };

/* Destructor: clears the global timed-object pointer, runs the base teardown, deletes the three
   owned helpers and the effect, then frees the object when flag > 0. */
extern "C" TimedObj * FUN_0013086c(TimedObj *self,short flag)
{
  void *owned;
  void *effect;
  
  if (self != (TimedObj *)0x0) {
    self->vtable = &DAT_003081f0;
    DAT_00340284 = 0;
    FUN_0013096c(self,0);
    owned = self->unk7c;
    if (owned != (void *)0x0) {
      delete ((VC_0 *)(owned));
      self->unk7c = 0;
    }
    owned = self->sub;
    if (owned != (void *)0x0) {
      delete ((VC_1 *)(owned));
      self->sub = 0;
    }
    owned = self->unk84;
    if (owned != (void *)0x0) {
      delete ((VC_2 *)(owned));
      self->unk84 = 0;
    }
    effect = self->effect;
    if (effect != (void *)0x0) {
      FUN_00063e44(effect,1);
      self->effect = 0;
    }
    FUN_0001f0f0(self,0);
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
