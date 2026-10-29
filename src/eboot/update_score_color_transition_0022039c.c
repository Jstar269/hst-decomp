/* HSTMATCH module=EBOOT.BIN start=0x0022039c end=0x002205e4 symbol=FUN_0022039c lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Ghidra pseudocode corrected by hand: typed float globals, hoisted the shared source float, and matched the color conversion and completion branches; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/fade_pane.h"

extern int DAT_002eff94;
extern float DAT_002f0b4c;
extern float DAT_002f0b50;
extern float DAT_0034a200;
extern float DAT_0034a204;
extern float FUN_0000bd2c(float value);
extern float FUN_000ede98(float value,float target,float rate,float eps);
extern void FUN_00103128(FadePane *);
extern void FUN_00103480(FadePane *);
extern void FUN_00103628(FadePane *, int);
extern void FUN_0027fc70(u32 *, u32 *, int);

/* One step of the fade: eases the node's offset and alpha toward their targets (reset targets during
   the first 100 steps, the saved targets afterwards), writes alpha into the colour once the timer has
   passed 90, advances the timer and finishes the fade when it reaches the limit. */
void FUN_0022039c(FadePane *self)
{
  FadeNode *node;
  int timer;
  float next_x;
  float next_y;
  float next_alpha;
  float cur_alpha;
  float cur_x;
  float cur_y;
  float adjusted;
  
  if (self->timer < 0) goto LAB_002205bc;
    node = self->node;
    cur_y = *(volatile float *)&node->y;
    cur_alpha = *(volatile float *)&node->alpha;
    cur_x = *(volatile float *)&node->x;
    if (self->timer < 100) {
      next_x = FUN_000ede98(cur_x,0.0f,DAT_002f0b50,0.01f);
      next_y = FUN_000ede98(cur_y,0.0f,DAT_002f0b50,0.01f);
      next_alpha = FUN_000ede98(cur_alpha,1.0f,DAT_002f0b50,0.01f);
    }
    else {
      next_x = FUN_000ede98(cur_x,DAT_0034a200,DAT_002f0b50,0.01f);
      next_y = FUN_000ede98(cur_y,DAT_0034a204,DAT_002f0b50,0.01f);
      next_alpha = FUN_000ede98(cur_alpha,DAT_002f0b4c,DAT_002f0b50,0.01f);
    }
    adjusted = FUN_0000bd2c(next_x);
    self->node->x = adjusted;
    adjusted = FUN_0000bd2c(next_y);
    self->node->y = adjusted;
    self->node->alpha = next_alpha;
    FUN_00103480(self);
    if (self->timer < 0x5a) {
      FUN_0027fc70((u32 *)self->unk70,self->color,1);
      timer = self->timer;
    }
    else {
      float scaled = next_alpha * 255.0f;
      int component;
      u32 *colorp = self->color;
      if (2.1474836e+09f <= scaled) goto LAB_00220540;
      component = (int)scaled;
      goto LAB_00220554;
LAB_00220540:
      scaled = scaled - 2.1474836e+09f;
      component = (int)scaled | -32768;
LAB_00220554:;
      u32 high = (u32)(component & 0xff) << 0x18;
      u32 old = *(volatile u32 *)colorp;
      *colorp = (old & 0xffffff) | high;
      timer = self->timer;
    }
    if (timer < FADE_TIMER_MAX) {
      self->timer = timer + 1;
    }
    if (!(self->timer < DAT_002eff94)) {
      FUN_00103628(self,1);
      self->unk54 = 1;
      self->timer = FADE_IDLE;
    }
LAB_002205bc:
  FUN_00103128(self);
}
