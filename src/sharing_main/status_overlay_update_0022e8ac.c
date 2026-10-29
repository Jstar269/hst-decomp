/* HSTMATCH module=hstp_trans_main.prx start=0x0022e8ac end=0x0022eb10 symbol=FUN_0022e8ac lang=c99 */
/* Clone of src/eboot/status_overlay_update_0021f338.c (hstclone.py tag c015707): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag km4 near miss, wip/near_0022e8ac.cpp) corrected by hand: FUN_001c0010 takes the sound handle (self->sound) as a second argument (retail loads it into a1); readability pass; exact match verified; names and types await human review. */
#pragma opt_strength_reduction on
#include "hst/types.h"
#include "hst/status_overlay.h"

extern u8 * DAT_003751d4;
extern int DAT_0039835c;
extern int DAT_00398360;
extern float DAT_00398ce8;
extern float DAT_003f34f0;
extern float DAT_003f34f4;
extern float DAT_003f3500;
extern u8 DAT_003eaad8;
extern float FUN_0000bd44(float value);
extern float FUN_000f3560(float current,float target,float rate,float eps);
extern void FUN_00105470(void *, int);
extern void FUN_00108a2c(int);
extern void FUN_00108dac(int);
extern void FUN_00108f54(int, int);
extern int FUN_001bfc3c(int *, int);
extern int FUN_001c0010(void *, int);

/* Per-frame update: drop a finished sound handle, ease the entity toward its target values, advance the
   timer (or hold it) and finish the overlay when the timer reaches its limit. */
void FUN_0022e8ac(register StatusOverlay *self)
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
  if (FUN_001c0010(&DAT_003eaad8, sound) == 0) {
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
    next60 = FUN_000f3560(v60,0.0f,DAT_00398ce8,0.01f);
    v64 = FUN_000f3560(v64,0.0f,DAT_00398ce8,0.01f);
    v78 = FUN_000f3560(v78,1.0f,DAT_00398ce8,0.01f);
  }
  else {
    next60 = FUN_000f3560(v60,-DAT_003f34f0,DAT_00398ce8,0.01f);
    v64 = FUN_000f3560(v64,-DAT_003f34f4,DAT_00398ce8,0.01f);
    v78 = FUN_000f3560(v78,DAT_003f3500,DAT_00398ce8,0.01f);
  }
  next60 = FUN_0000bd44(next60);
  self->ent->unk60 = next60;
  v64 = FUN_0000bd44(v64);
  self->ent->unk64 = v64;
  self->ent->unk78 = v78;
  FUN_00108dac((int)self);
  if (self->timer >= DAT_0039835c + OVERLAY_HOLD_DELAY && self->hold != 0) {
    FUN_00105470(self->widget,0);
    if (((int)*(char *)(DAT_003751d4 + 0x8b) << 0x1c) >> 0x1e == 0) {
      FUN_001bfc3c((int *)&DAT_003eaad8,3);
      self->hold = 0;
      self->timer = OVERLAY_OUT_PHASE;
    }
  } else {
    FUN_00105470(self->widget,1);
    self->timer = self->timer + 1;
  }
  if (!(self->timer < DAT_00398360)) {
    FUN_00108f54((int)self,1);
    self->done = 1;
    self->timer = -1;
  }
done:
  FUN_00108a2c((int)self);
}
