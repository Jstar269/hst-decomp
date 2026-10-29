/* HSTMATCH module=EBOOT.BIN start=0x000f1b6c end=0x000f1c7c symbol=FUN_000f1b6c lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: float tests written with the parameter on the left (`p > 2.0f`, `p >= x`), which MWCC compiles to c.ngt.s/c.nge.s + bc1t where Ghidra's `2.0f < p` / `x <= p` gave c.lt.s/c.le.s + bc1f; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern void FUN_0010e5b8(...);
}
#define TIME_SWITCH 2.0f /* time above which the first mode is chosen */

/* Polymorphic widget; only the two setters used here are named (by their vtable slot). */
struct Widget {
  virtual void d0();
  virtual void Set1(int);
  virtual void d2();
  virtual void d3();
  virtual void Set4(int);
};

struct Self {
  char pad00[0x68];
  Widget *widget;   /* 0x68 */
  char pad6c[0x18];
  float limitLow;   /* 0x84 */
  float limitHigh;  /* 0x88 */
};

/* Picks a state for the widget from the time value: a mode (0 or 1) at the 2.0f switch, then one of three
   packed values by comparing against the two limits. */
extern "C" void FUN_000f1b6c(float time,Self *self)
{
  float limit;
  
  if (time > TIME_SWITCH) {
    self->widget->Set1(0);
    FUN_0010e5b8(self->widget,0,0,(int)time,7,0,0,3);
    limit = self->limitHigh;
  }
  else {
    self->widget->Set1(1);
    limit = self->limitHigh;
  }
  if (time >= limit) {
    self->widget->Set4((int)0x80673376);
  }
  else if (time >= self->limitLow) {
    self->widget->Set4((int)0x8000427f);
  }
  else {
    self->widget->Set4((int)0x801a1c75);
  }
}
