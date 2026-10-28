/* HSTMATCH module=EBOOT.BIN start=0x001c2f90 end=0x001c30b8 symbol=FUN_001c2f90 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: vector member offset correction (w at 0xdc) and scalar field initialization avoiding .data section; readability pass; exact match verified; names and types await human review. */
#include "hst/menu_state.h"

extern "C" void *DAT_0034a2e0;
extern "C" void *DAT_0033b574;
extern "C" void *DAT_002ea2f0;

extern "C" void FUN_00225c40(void *, int, int, const void *);
extern "C" bool FUN_00225de4(void *);
extern "C" bool FUN_001c39f8(int);
extern "C" void FUN_002879e0(void *, int, void *, int, float, int);
extern "C" void FUN_001cd88c(void *, int, int);

/* State handler: once `time` reaches `triggerTime`, starts the effect (at effectPos, or a default
   position when unset), then waits for it to finish and moves on to `nextState`. */
extern "C" void FUN_001c2f90(MenuState *self)
{
  if (self->time >= self->triggerTime) {
    bool waiting = true; /* false while the effect was only just started */
    if (self->triggered == 0) {
      int effectId = self->effectId;
      if (effectId >= 0) {
        if (self->effectPos.w == 0.0f) {
          Vec4 pos;
          pos.y = -10.0f;
          pos.x = 0.0f;
          pos.z = 0.0f;
          pos.w = 0.0f;
          FUN_00225c40(DAT_0034a2e0, effectId, self->unkbc, &pos);
        } else {
          FUN_00225c40(DAT_0034a2e0, effectId, self->unkbc, &self->effectPos);
        }
        waiting = false;
      }
      self->triggered = 1;
      self->triggerTime = -1;
    }
    if (self->triggered != 0) {
      if (waiting) {
        if (FUN_00225de4(DAT_0034a2e0)) {
          if (FUN_001c39f8(self->effectId)) {
            FUN_002879e0((char *)DAT_0033b574 + 0x1320, 0, DAT_002ea2f0, 0, -1.0f, 0);
          }
          FUN_001cd88c(self, self->nextState, 1);
        }
      }
    }
  }
}
