/* HSTMATCH module=EBOOT.BIN start=0x001eab18 end=0x001eab2c symbol=FUN_001eab18 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/two_quad_screen.h"

/* Marks the screen active and restarts its counter. */
void FUN_001eab18(TwoQuadRef *ref)
{
  TwoQuadScreen *screen;
  
  screen = ref->screen;
  screen->active = 1;
  screen->counter = 0;
}
