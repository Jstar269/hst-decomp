/* HSTMATCH module=EBOOT.BIN start=0x000b33d0 end=0x000b342c symbol=FUN_000b33d0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1/v0) corrected by hand: separated the inner pointer from its loaded value and kept the nested positive range checks; readability pass; exact match verified; names and types await human review. */
#include "hst/chara_player.h"

extern int FUN_00093b00();

/* True when the model's current motion is in 5..8 and the extra check on the model fails. */
int FUN_000b33d0(CharaPlayer *self)
{
  MotionModel *model = self->model;
  MotionEffect *effect = model->effect;
  int motion;
  if (effect != 0) motion = effect->motion;
  else motion = MOTION_UNSET;
  if (motion >= 5) {
    if (motion < 9) {
      if (FUN_00093b00(model,0) == 0) return 1;
    }
  }
  return 0;
}
