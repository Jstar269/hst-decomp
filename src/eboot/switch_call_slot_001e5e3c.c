/* HSTMATCH module=EBOOT.BIN start=0x001e5e3c end=0x001e5f00 symbol=FUN_001e5e3c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: readability pass; the else-if ladder on param_2 is a switch with cases 1-4 in source order (tests come out reversed), typed ResultScene/Animator views of the four consecutive 0x8c-byte records, and an inline helper for the shared call; exact match verified; names and types await human review. */
#include "hst/result_scene.h"

extern void FUN_002177d4(Animator *anim, int a, int b, int c, int d, int e);

static inline void Call(Animator *anim)
{
  FUN_002177d4(anim, anim->x + 0x15e, anim->y, anim->x, anim->y, 5);
}

/* Run the shared animator call for animator number `which` (1 to 4). */
void FUN_001e5e3c(ResultScene *self, int which)
{
  switch (which) {
  case 1:
    Call(&self->anim1fb4);
    break;
  case 2:
    Call(&self->anim2040);
    break;
  case 3:
    Call(&self->anim20cc);
    break;
  case 4:
    Call(&self->anim2158);
    break;
  }
}
