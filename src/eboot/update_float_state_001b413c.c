/* HSTMATCH module=EBOOT.BIN start=0x001b413c end=0x001b41c8 symbol=FUN_001b413c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: fixed parameter types, helper prototype and call arguments, and the early-return flow; readability pass; exact match verified; names and types await human review. */
#include "hst/slot_fade.h"

extern void FUN_000628e4();
extern void FUN_00062b1c(int, float, int);

/* Apply `level` (0.0f to 1.0f, scaled to 0..128) to handle_a and record it. */
void FUN_001b413c(SlotFadeTable **ctx,float level,float amount)
{
  SlotFadeTable *self;
  
  self = *ctx;
  if (self->handle_a < 0) {
    return;
  }
  FUN_00062b1c(self->handle_a,amount,(int)(level * 128.0f));
  if (level <= 0.0f) {
    self->handle_cur = self->handle_a;
  }
  else if (self->handle_cur >= 0) {
    FUN_000628e4(self->handle_cur,0);
    self->handle_cur = -1;
  }
  self->level = level;
}
