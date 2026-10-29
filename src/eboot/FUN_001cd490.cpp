/* HSTMATCH module=EBOOT.BIN start=0x001cd490 end=0x001cd55c symbol=FUN_001cd490 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a6) corrected by hand: preserve the positive guard and type the global manager virtual dispatch; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/flow_state.h"

struct Manager { virtual void f0(); virtual void f1(); };
extern "C" {
  extern Manager *DAT_0033b580;
  void FUN_0012de6c(...);
  void FUN_0012f3f0(...);
}

/* value > 0 sets the state flag and notifies the manager; otherwise it clears it and, depending on mode, notifies or shuts the manager down. */
extern "C" int FUN_001cd490(FlowOwner *self, int value, int mode, u32 arg4, u32 arg5, u32 arg6, u32 arg7, u32 arg8)
{
  FlowState *state;
  if (value > 0) {
    self->state->unk60 = 1;
    if (DAT_0033b580 != 0) {
      FUN_0012de6c((int)DAT_0033b580, 4, value, mode, arg5, arg6, arg7, arg8);
    }
  } else {
    state = self->state;
    state->unk60 = 0;
    state->sub->unk6d = 1;
    if (DAT_0033b580 != 0 && mode > 0) {
      FUN_0012de6c((int)DAT_0033b580, 0, 0, 0, arg5, arg6, arg7, arg8);
    }
    if (mode == 2 && DAT_0033b580 != 0) {
      DAT_0033b580->f1();
      FUN_0012f3f0((int)DAT_0033b580);
    }
  }
}
