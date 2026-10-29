/* HSTMATCH module=EBOOT.BIN start=0x000fbed0 end=0x000fbee4 symbol=FUN_000fbed0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/mode_screen.h"

/* Set the active flag; activating also resets the timer. */
void FUN_000fbed0(ModeScreen *self,int active)
{
  self->active = (char)active;
  if (active != 0) {
    self->timer = 0;
  }
}
