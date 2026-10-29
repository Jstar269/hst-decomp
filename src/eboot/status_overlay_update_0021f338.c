/* HSTMATCH module=EBOOT.BIN start=0x0021f338 end=0x0021f59c symbol=FUN_0021f338 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag km4 near miss, wip/near_0021f338.cpp) corrected by hand: FUN_001b1f7c takes the sound handle (self->sound) as a second argument (retail loads it into a1); readability pass; exact match verified; names and types await human review. */
#pragma opt_strength_reduction on
#include "hst/types.h"
#include "hst/status_overlay.h"

extern u8 * DAT_002cfc8c;
extern int DAT_002eff90;
extern int DAT_002eff94;
extern float DAT_002f091c;
extern float DAT_0034a1c0;
extern float DAT_0034a1c4;
extern float DAT_0034a1d0;
extern u8 DAT_0034179c;
extern float FUN_0000bd2c(float value);
extern float FUN_000ede98(float current,float target,float rate,float eps);
extern void FUN_000ffb3c(void *, int);
extern void FUN_00103128(int);
extern void FUN_00103480(int);
extern void FUN_00103628(int, int);
extern int FUN_001b1c44(int *, int);
extern int FUN_001b1f7c(void *, int);

/* Per-frame update: drop a finished sound handle, ease the entity toward its target values, advance the
   timer (or hold it) and finish the overlay when the timer reaches its limit. */
void FUN_0021f338(register StatusOverlay *self)
{
  int timer;
  int sound;
  volatile OverlayEntity *src;
  float next60;
  float v64;
  float v78;
  float v60;
  
  sound = self->sound;
  if (sound < 0) goto check_timer;
  if (FUN_001b1f7c(&DAT_0034179c, sound) == 0) {
    self->sound = -1;
  }
check_timer:
  timer = self->timer;
  if (timer < 0) goto done;
  src = self->ent;
  v64 = src->unk64;
  v78 = src->unk78;
  v60 = src->unk60;
  if (timer < OVERLAY_OUT_PHASE) {
    next60 = FUN_000ede98(v60,0.0f,DAT_002f091c,0.01f);
    v64 = FUN_000ede98(v64,0.0f,DAT_002f091c,0.01f);
    v78 = FUN_000ede98(v78,1.0f,DAT_002f091c,0.01f);
  }
  else {
    next60 = FUN_000ede98(v60,-DAT_0034a1c0,DAT_002f091c,0.01f);
    v64 = FUN_000ede98(v64,-DAT_0034a1c4,DAT_002f091c,0.01f);
    v78 = FUN_000ede98(v78,DAT_0034a1d0,DAT_002f091c,0.01f);
  }
  next60 = FUN_0000bd2c(next60);
  self->ent->unk60 = next60;
  v64 = FUN_0000bd2c(v64);
  self->ent->unk64 = v64;
  self->ent->unk78 = v78;
  FUN_00103480((int)self);
  if (self->timer >= DAT_002eff90 + OVERLAY_HOLD_DELAY && self->hold != 0) {
    FUN_000ffb3c(self->widget,0);
    if (((int)*(char *)(DAT_002cfc8c + 0x8b) << 0x1c) >> 0x1e == 0) {
      FUN_001b1c44((int *)&DAT_0034179c,3);
      self->hold = 0;
      self->timer = OVERLAY_OUT_PHASE;
    }
  } else {
    FUN_000ffb3c(self->widget,1);
    self->timer = self->timer + 1;
  }
  if (!(self->timer < DAT_002eff94)) {
    FUN_00103628((int)self,1);
    self->done = 1;
    self->timer = -1;
  }
done:
  FUN_00103128((int)self);
}
