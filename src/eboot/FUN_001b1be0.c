/* HSTMATCH module=EBOOT.BIN start=0x001b1be0 end=0x001b1c44 symbol=FUN_001b1be0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: the handle tested first is FUN_00062a6c's argument (Ghidra dropped it, so retail loads it into a0); readability pass; exact match verified; names and types await human review. */
#include "hst/slot_fade.h"

extern void FUN_000628e4();
extern int FUN_00062a6c(int);
extern int FUN_00062b3c();

/* If handle_cur is set: clear it when FUN_00062a6c rejects it, otherwise call FUN_000628e4(handle, 1) when FUN_00062b3c reports less than 1. */
void FUN_001b1be0(SlotFadeTable **ctx)
{
  int handle;
  int ok;
  SlotFadeTable *self;
  
  self = *ctx;
  handle = self->handle_cur;
  if (handle <= 0) {
    return;
  }
  ok = FUN_00062a6c(handle);
  if (ok == 0) {
    self->handle_cur = -1;
  }
  else {
    ok = FUN_00062b3c(self->handle_cur);
    if (ok < 1) {
      FUN_000628e4(self->handle_cur,1);
    }
  }
}
