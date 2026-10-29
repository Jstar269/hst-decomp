/* HSTMATCH module=EBOOT.BIN start=0x00060138 end=0x00060224 symbol=FUN_00060138 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag g2) corrected by hand: switched to MWCC C++ (removed cc=gcc171-Os), added #pragma opt_strength_reduction off for the indexed loop, and restored inline member destructor null check; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/vbtexanim.h"

extern u8 DAT_00307070;
extern u8 DAT_00311170;
extern "C" void FUN_00000a00(void *);
extern "C" void FUN_0004fe04(void *, u32);
extern "C" void * FUN_00054554(void *, short);
extern "C" void FUN_00060224(void *, int);

#pragma opt_strength_reduction off

/* Deleting destructor (short flag) of the texture animation: switches it off, frees its buffer and handles. */
extern "C" VbTexAnim * FUN_00060138(VbTexAnim *self, short flag)
{
  int **handle_vec;
  u32 i;
  
  if (self != 0) {
    self->vptr = &DAT_00307070;
    FUN_00060224(self, 0);
    if (self->buf != 0) {
      FUN_00000a00(self->buf);
      self->buf = 0;
    }
    for (i = 0; i < self->count; i++) {
      FUN_0004fe04(&DAT_00311170, self->handles[i]);
      self->handles[i] = -1;
    }
    handle_vec = &self->handles;
    if (handle_vec != 0 && handle_vec != 0) {
      FUN_00054554(handle_vec, 0);
    }
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
