/* HSTMATCH module=EBOOT.BIN start=0x000faf9c end=0x000fafb8 symbol=FUN_000faf9c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag u1ge) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/hud_scene.h"

/* Count the countdown down towards zero. */
void FUN_000faf9c(HudScene *self)
{
  if (0 < self->countdown) {
    self->countdown = self->countdown + -1;
  }
}
