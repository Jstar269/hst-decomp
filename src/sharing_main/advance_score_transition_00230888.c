/* HSTMATCH module=hstp_trans_main.prx start=0x00230888 end=0x00230b04 symbol=FUN_00230888 lang=c99 */
/* Clone of src/eboot/advance_score_transition_00221314.c (hstclone.py tag c015707): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Ghidra pseudocode corrected by hand: typed float globals, preserved the shared input load, and matched the state/limit branch layout; readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/lay_pane.h"

extern u8 * DAT_003751d4;
extern int DAT_0039835c; /* hold check starts this many frames (plus a margin) in */
extern int DAT_00398360; /* timer value at which the animation ends */
extern float DAT_003990d8;
extern float DAT_003990dc;
extern u8 DAT_003eaad8;
extern float DAT_003f3570;
extern float DAT_003f3574;
extern float FUN_0000bd44(float param_1);
extern float FUN_000f3560(float param_1,float param_2,float param_3,float param_4);
extern void FUN_00105470(int, int);
extern void FUN_00108a2c(int);
extern void FUN_00108dac(int);
extern void FUN_00108f54(int, int);
extern int FUN_001bfc3c(int *, int);

/* Per-frame update: ease the entries towards the goals of the current phase, advance the timer, finish at the limit. */
void FUN_00230888(PaneA *self)
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
    x_goal = FUN_000f3560(input,0.0f,DAT_003990dc,0.01f);
    y_goal = FUN_000f3560(y_cur,0.0f,DAT_003990dc,0.01f);
    s_goal = FUN_000f3560(s_cur,1.0f,DAT_003990dc,0.01f);
  }
  else {
    x_goal = FUN_000f3560(input,-DAT_003f3570,DAT_003990dc,0.01f);
    y_goal = FUN_000f3560(y_cur,-DAT_003f3574,DAT_003990dc,0.01f);
    s_goal = FUN_000f3560(s_cur,DAT_003990d8,DAT_003990dc,0.01f);
  }
  for (i = 0; i < 5; i++) {
    eased = FUN_0000bd44(x_goal);
    self->ent[i]->unk60 = eased;
    eased = FUN_0000bd44(y_goal);
    self->ent[i]->unk64 = eased;
    self->ent[i]->unk78 = s_goal;
  }
  FUN_00108dac((int)self);
  if (self->timer >= DAT_0039835c + 0x14 && self->hold != 0) {
    FUN_00105470(self->handle80,0);
    FUN_00105470(self->handle84,0);
    /* the condition below tests a 2-bit field of the environment object */
    if (((int)*(char *)(DAT_003751d4 + 0x8b) << 0x1c) >> 0x1e == 0) {
      FUN_001bfc3c((int *)&DAT_003eaad8,3);
      self->hold = 0;
      self->timer = PANE_TIMER_SPLIT;
    }
  } else {
    FUN_00105470(self->handle80,1);
    FUN_00105470(self->handle84,1);
    self->timer = self->timer + 1;
  }
  if (!(self->timer < DAT_00398360)) {
    FUN_00108f54((int)self,1);
    self->unk58 = 1;
    self->timer = PANE_TIMER_IDLE;
  }
done:
  FUN_00108a2c((int)self);
}
