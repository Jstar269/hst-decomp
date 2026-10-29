/* HSTMATCH module=EBOOT.BIN start=0x00221314 end=0x00221590 symbol=FUN_00221314 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Ghidra pseudocode corrected by hand: typed float globals, preserved the shared input load, and matched the state/limit branch layout; readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/lay_pane.h"

extern u8 * DAT_002cfc8c;
extern int DAT_002eff90; /* hold check starts this many frames (plus a margin) in */
extern int DAT_002eff94; /* timer value at which the animation ends */
extern float DAT_002f0d0c;
extern float DAT_002f0d10;
extern u8 DAT_0034179c;
extern float DAT_0034a240;
extern float DAT_0034a244;
extern float FUN_0000bd2c(float param_1);
extern float FUN_000ede98(float param_1,float param_2,float param_3,float param_4);
extern void FUN_000ffb3c(int, int);
extern void FUN_00103128(int);
extern void FUN_00103480(int);
extern void FUN_00103628(int, int);
extern int FUN_001b1c44(int *, int);

/* Per-frame update: ease the entries towards the goals of the current phase, advance the timer, finish at the limit. */
void FUN_00221314(PaneA *self)
{
  PaneEnt *first;
  int i;
  float x_goal;
  float eased;
  float y_goal;
  float s_goal;
  float input;
  float y_cur;
  float s_cur;

  if (self->timer < 0) goto done;
  first = self->ent[0];
  y_cur = *(volatile float *)&first->unk64;
  s_cur = *(volatile float *)&first->unk78;
  input = *(volatile float *)&first->unk60;
  if (self->timer < PANE_TIMER_SPLIT) {
    x_goal = FUN_000ede98(input,0.0f,DAT_002f0d10,0.01f);
    y_goal = FUN_000ede98(y_cur,0.0f,DAT_002f0d10,0.01f);
    s_goal = FUN_000ede98(s_cur,1.0f,DAT_002f0d10,0.01f);
  }
  else {
    x_goal = FUN_000ede98(input,-DAT_0034a240,DAT_002f0d10,0.01f);
    y_goal = FUN_000ede98(y_cur,-DAT_0034a244,DAT_002f0d10,0.01f);
    s_goal = FUN_000ede98(s_cur,DAT_002f0d0c,DAT_002f0d10,0.01f);
  }
  for (i = 0; i < 5; i++) {
    eased = FUN_0000bd2c(x_goal);
    self->ent[i]->unk60 = eased;
    eased = FUN_0000bd2c(y_goal);
    self->ent[i]->unk64 = eased;
    self->ent[i]->unk78 = s_goal;
  }
  FUN_00103480((int)self);
  if (self->timer >= DAT_002eff90 + 0x14 && self->hold != 0) {
    FUN_000ffb3c(self->handle80,0);
    FUN_000ffb3c(self->handle84,0);
    /* the condition below tests a 2-bit field of the environment object */
    if (((int)*(char *)(DAT_002cfc8c + 0x8b) << 0x1c) >> 0x1e == 0) {
      FUN_001b1c44((int *)&DAT_0034179c,3);
      self->hold = 0;
      self->timer = PANE_TIMER_SPLIT;
    }
  } else {
    FUN_000ffb3c(self->handle80,1);
    FUN_000ffb3c(self->handle84,1);
    self->timer = self->timer + 1;
  }
  if (!(self->timer < DAT_002eff94)) {
    FUN_00103628((int)self,1);
    self->unk58 = 1;
    self->timer = PANE_TIMER_IDLE;
  }
done:
  FUN_00103128((int)self);
}
