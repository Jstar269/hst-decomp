/* HSTMATCH module=EBOOT.BIN start=0x0017dc8c end=0x0017dcfc symbol=FUN_0017dc8c lang=c++ */
/* Ghidra pseudocode (hstgen.py tag p128a/v2) corrected by hand: this/float argument order and clamp access; readability pass; exact match verified; names and types await human review. */
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

/* Set the manager's value and clamp it to the settings' limits. */
extern "C" void FUN_0017dc8c(SlotMgr *self,float value)
{
  SlotSettings *settings;
  
  settings = FUN_0016bc7c();
  self->value = value;
  self->value = Clamp(Current(self), settings->lo, settings->hi);
  return;
}
