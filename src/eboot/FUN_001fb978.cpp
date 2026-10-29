/* HSTMATCH module=EBOOT.BIN start=0x001fb978 end=0x001fb9dc symbol=FUN_001fb978 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */

#include "hst/state_switch.h"

/* Hooks reached through the vtable: the first sees the old state id, the second the new one. */
struct VC_0 { virtual void d0(); virtual void d1(); virtual void leave(int); };
struct VC_1 { virtual void d0(); virtual void enter(int); };

/* Changes to new_state: runs the leave hook, remembers the old state, resets the counters, runs the enter hook. */
extern "C" void FUN_001fb978(StateSwitch *self,int new_state)
{
  ((VC_0 *)(self))->leave(self->state);
  self->prev_state = self->state;
  self->state = new_state;
  self->unk08 = 0;
  self->duration = 0;
  ((VC_1 *)(self))->enter(new_state);
}
