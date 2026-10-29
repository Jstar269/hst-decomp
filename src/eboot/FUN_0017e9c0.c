/* HSTMATCH module=EBOOT.BIN start=0x0017e9c0 end=0x0017ea5c symbol=FUN_0017e9c0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed the helper with its object pointer between the second and final float parameters to preserve the retail EABI argument-register order; readability pass; exact match verified; names and types await human review. */
#include "hst/light_obj.h"

/* Global parameter block returned by the accessor. */
typedef struct {
  char pad0[0x54];
  float unk54, unk58, unk5c;
  char pad1[0x10];
  float fadeRate;   /* 0x70 progress added per update */
} Params;
extern Params *FUN_0016bc7c(void);
extern void FUN_0005c76c(float, float, void *, float, float);

/* Advance the fade progress while active (stopping at 1), then push the parameters and progress to the sub-object. */
void FUN_0017e9c0(LightObj *light) {
  if (light->active != 0) {
    float delta = FUN_0016bc7c()->fadeRate;
    float progress = light->progress + delta;
    light->progress = progress;
    if (progress >= 1.0f) {
      light->active = 0;
      light->progress = 1.0f;
    }
  }
  Params *a = FUN_0016bc7c();
  Params *b = FUN_0016bc7c();
  Params *c = FUN_0016bc7c();
  float progress = light->progress;
  float third = c->unk5c;
  FUN_0005c76c(a->unk54, b->unk58, light->sub10, third, progress);
}
