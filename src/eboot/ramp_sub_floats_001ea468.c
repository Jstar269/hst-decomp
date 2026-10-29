/* HSTMATCH module=EBOOT.BIN start=0x001ea468 end=0x001ea5d4 symbol=FUN_001ea468 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s512a) corrected by hand: typed structs, branch order swapped (flag set first), the first sub-object's float read before the flag test, loops over the 8 sub-objects; readability pass; exact match verified; names and types await human review. */
#include "hst/two_quad_screen.h"

extern float DAT_002ed274;
extern float DAT_002ed278;
extern void FUN_00103128(TwoQuadScreen *);
extern void FUN_00103480(TwoQuadScreen *);
extern void FUN_001e995c(TwoQuadScreen *);
extern void FUN_001e9e80(TwoQuadScreen *, int);

/* Per-frame update: while the screen is active, sets the alpha of all sprites to a ramp of the counter (0 up to
   the first threshold, 1 from the second) until the counter passes the second threshold; while inactive,
   sets every alpha to 1 unless the first is already 1. */
void FUN_001ea468(TwoQuadScreen *screen)
{
  float alpha;
  float frame;
  int i;
  float first_alpha;
  FUN_001e9e80(screen, 0);
  first_alpha = screen->spr[0]->alpha;
  if (screen->active != 0) {
    FUN_001e995c(screen);
    alpha = 1.0f;
    frame = (float)screen->counter;
    if (frame <= DAT_002ed274) {
      alpha = 0.0f;
    } else if (frame <= DAT_002ed278) {
      alpha = (frame - DAT_002ed274) / (DAT_002ed278 - DAT_002ed274);
    }
    if ((float)screen->counter <= DAT_002ed278) {
      for (i = 0; i < TWO_QUAD_SPRITE_COUNT; i++) {
        screen->spr[i]->alpha = alpha;
      }
      FUN_00103480(screen);
    }
  } else {
    if (first_alpha != 1.0f) {
      for (i = 0; i < TWO_QUAD_SPRITE_COUNT; i++) {
        screen->spr[i]->alpha = 1.0f;
      }
      FUN_00103480(screen);
    }
  }
  FUN_00103128(screen);
}
