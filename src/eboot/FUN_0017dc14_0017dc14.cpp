/* HSTMATCH module=EBOOT.BIN start=0x0017dc14 end=0x0017dc8c symbol=FUN_0017dc14 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a1/v0) corrected by hand: this/float argument order and clamp access; readability pass; exact match verified; names and types await human review. */
#include "hst/slot_mgr.h"

extern "C" SlotSettings *FUN_0016bc7c();

static inline float Clamp(const float &value, const float &low, const float &high)
{
  return value < low ? low : (!(value > high) ? value : high);
}

static inline const float &Current(const SlotMgr *state)
{
  return state->value;
}

/* Add `delta` to the manager's value and clamp it to the settings' limits. */
extern "C" void FUN_0017dc14(SlotMgr *self,float delta)
{
  SlotSettings *settings;
  
  settings = FUN_0016bc7c();
  self->value = self->value + delta;
  self->value = Clamp(Current(self), settings->lo, settings->hi);
}
