/* HSTMATCH module=EBOOT.BIN start=0x0018abec end=0x0018ad0c symbol=FUN_0018abec lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: const-reference clamp as in 0x18b2bc, the blend weight kept in a local (1.0f - clamped), second store of (1.0f - w) * 8.0f; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/phase_screen.h"

#define BLEND_FRAMES 3 /* frames the blend phase lasts */

/* Pane whose two float parameters are driven by the blend. */
struct BlendPane {
  char pad00[0x64];
  float inverse;  /* 0x64 (1 - weight) * 8 */
  char pad68[0x78 - 0x68];
  float weight;   /* 0x78 */
};

extern "C" {
extern float DAT_002e0b78; /* clamp lower bound */
extern float DAT_002e0b7c; /* clamp upper bound */
extern char DAT_002e0b44[];
extern float FUN_0000ce3c(float param_1,float param_2);
extern void FUN_00103480(PhaseScreen *);
extern BlendPane *FUN_001039d8(PhaseScreen *, u8 *, int);
extern void FUN_0018aa0c(PhaseScreen *, int);
}

static inline float Clamp(const float &value, const float &lo, const float &hi)
{
  return value < lo ? lo : (!(value > hi) ? value : hi);
}

/* Blend phase: ease the pane weight towards 1 over BLEND_FRAMES frames, then move on. */
extern "C" void FUN_0018abec(PhaseScreen *self)
{
  BlendPane *pane;
  float ratio;
  float clamped;
  float w;
  
  self->frame = self->frame + 1;
  ratio = FUN_0000ce3c(3.0f - (float)self->frame,2.0f);
  clamped = FUN_0000ce3c(3.0f,2.0f);
  ratio = ratio / clamped;
  clamped = Clamp(ratio,DAT_002e0b78,DAT_002e0b7c);
  w = 1.0f - clamped;
  pane = FUN_001039d8(self,(u8 *)DAT_002e0b44,0);
  pane->inverse = (1.0f - w) * 8.0f;
  pane->weight = w;
  FUN_00103480(self);
  if (self->frame < BLEND_FRAMES) {
  }
  else {
    FUN_0018aa0c(self,1);
  }
}
