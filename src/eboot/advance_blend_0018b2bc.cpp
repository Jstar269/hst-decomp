/* HSTMATCH module=EBOOT.BIN start=0x0018b2bc end=0x0018b3d4 symbol=FUN_0018b2bc lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a2/v0) corrected by hand: reconstructed the const-reference clamp and comparison shape; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/phase_screen.h"
#include "hst/fade_pane.h"

enum {
  BLEND_FRAMES = 3,   /* frames the blend runs before the phase ends */
  PHASE_IDLE = 4      /* phase entered when the blend is done */
};

extern "C" {
extern float DAT_002e0bb0;
extern float DAT_002e0bb4;
extern char DAT_002e0b44[];
extern float FUN_0000ce3c(float param_1,float param_2);
extern void FUN_00103480(PhaseScreen *);
extern FadeNode *FUN_001039d8(PhaseScreen *, u8 *, int);
extern void FUN_0018aa0c(PhaseScreen *, int);
}

static inline float Clamp(const float &value, const float &lo, const float &hi)
{
  return value < lo ? lo : (!(value > hi) ? value : hi);
}

/* One step of the blend-in: advances the frame counter, eases the node's alpha and slide offset, and ends the phase after BLEND_FRAMES. */
extern "C" void FUN_0018b2bc(PhaseScreen *self)
{
  FadeNode *node;
  float ease;
  float blend;
  
  self->frame = self->frame + 1;
  ease = FUN_0000ce3c(3.0f - (float)self->frame,2.0f);
  blend = FUN_0000ce3c(3.0f,2.0f);
  ease = ease / blend;
  blend = Clamp(ease,DAT_002e0bb0,DAT_002e0bb4);
  node = FUN_001039d8(self,(u8 *)DAT_002e0b44,0);
  node->y = -(1.0f - blend) * 8.0f;
  node->alpha = blend;
  FUN_00103480(self);
  if (self->frame < BLEND_FRAMES) {
  }
  else {
    FUN_0018aa0c(self,PHASE_IDLE);
  }
}
