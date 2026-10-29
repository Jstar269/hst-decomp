/* HSTMATCH module=EBOOT.BIN start=0x000b3490 end=0x000b34d0 symbol=FUN_000b3490 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/chara_player.h"

/* True when the model's current motion id is in 118..129. */
int FUN_000b3490(CharaPlayer *self)
{
  MotionModel *model = self->model;
  MotionEffect *effect = model->effect;
  int motion = effect ? effect->motion : MOTION_UNSET;
  if (motion >= 118) {
    if (motion < 130) return 1;
  }
  return 0;
}
