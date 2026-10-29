/* HSTMATCH module=EBOOT.BIN start=0x001b4464 end=0x001b4528 symbol=FUN_001b4464 lang=c99 */
/* Hand-written reconstruction from the disassembly; matching idiom: typed helper calls include their float and mode arguments, with an explicit negative early return; exact match verified; names and types await human review. */
#include "hst/slot_fade.h"

extern void FUN_000628e4(int handle,int arg);
extern void FUN_00062b1c(int handle,float amount,int level);

/* Switch between the two handles: nonzero `first` starts handle_a and quiets handle_b, zero does the reverse. */
void FUN_001b4464(SlotFadeTable **ctx,int first)
{
  SlotFadeTable *self = *ctx;

  if (first != 0) {
    if (self->handle_a >= 0) {
      FUN_00062b1c(self->handle_a,0.5f,0);
      self->handle_cur = self->handle_a;
      self->level = 0.0f;
    }
    if (self->handle_b >= 0) {
      FUN_00062b1c(self->handle_b,0.0f,128);
    }
  } else {
    if (self->handle_b >= 0) {
      FUN_00062b1c(self->handle_b,0.5f,0);
    }
    if (self->handle_a < 0) return;
    FUN_00062b1c(self->handle_a,0.0f,128);
    if (self->handle_cur >= 0) {
      FUN_000628e4(self->handle_cur,0);
      self->handle_cur = -1;
    }
    self->level = 1.0f;
  }
}
