/* HSTMATCH module=EBOOT.BIN start=0x000f0384 end=0x000f04dc symbol=FUN_000f0384 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/ingame_panes.h"

extern int DAT_00338c20;
extern void FUN_000fb06c(int);
extern void FUN_00103128(FadeCyclePane *);
extern void FUN_00103480(FadeCyclePane *);

/* Advance the fade cycle one frame: fade in, hold, fade out, then off after FADE_CYCLE_END frames. */
void FUN_000f0384(FadeCyclePane *self)
{
  float level;
  float rise;
  float old;

  if (self->base.shown == 0) {
    rise = 0.0f;
    old = self->scale;
    self->frame = self->frame + 1;
    level = (float)self->frame;
    if (level < FADE_CYCLE_IN) {
      level = level / FADE_CYCLE_IN;
      rise = (1.0f - level) * 18.0f;
    }
    else if (level < FADE_CYCLE_HOLD_END) {
      level = 1.0f;
    }
    else if (level < FADE_CYCLE_END) {
      level = 1.0f - (level - FADE_CYCLE_HOLD_END) / (FADE_CYCLE_END - FADE_CYCLE_HOLD_END);
    }
    else {
      level = 0.0f;
    }
    self->scale = level;
    self->node[0]->y = rise;
    self->node[0]->alpha = level;
    self->node[1]->y = rise;
    self->node[1]->alpha = level;
    self->node[2]->y = rise;
    self->node[2]->alpha = level;
    if (old > 0.0f || self->scale > 0.0f) {
      FUN_00103480(self);
    }
    if ((float)self->frame == FADE_CYCLE_END) {
      FUN_000fb06c(DAT_00338c20);
    }
    FUN_00103128(self);
  }
}
