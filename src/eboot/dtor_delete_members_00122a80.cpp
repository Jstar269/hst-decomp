/* HSTMATCH module=EBOOT.BIN start=0x00122a80 end=0x00122b48 symbol=FUN_00122a80 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: loop index declared before the member pointer (s-register order); readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/actor_state.h"

extern "C" {
extern u8 DAT_00308028;
extern void FUN_00000a00(...);
extern u32 * FUN_0001f0f0(...);
extern int FUN_002161c4(...);
}
struct VC_0 { virtual ~VC_0(); };

/* Destructor: deletes the three child objects and the helper object, runs the base destructor, frees when flag > 0. */
extern "C" ActorState * FUN_00122a80(ActorState *self,short flag)
{
  int i;
  ActorState *cursor;
  ActorChild *child;
  
  if (self != 0) {
    self->vtable = &DAT_00308028;
    i = 0;
    cursor = self; /* advances one word per child; children[0] is read relative to it */
    do {
      child = cursor->children[0];
      if (child != 0) {
        delete ((VC_0 *)(child));
        cursor->children[0] = 0;
      }
      i = i + 1;
      cursor = (ActorState *)((char *)cursor + 4);
    } while (i < ACTOR_CHILD_COUNT);
    if (self->unk54 != 0) {
      FUN_002161c4(self->unk54,1);
      self->unk54 = 0;
    }
    FUN_0001f0f0(self,0);
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
