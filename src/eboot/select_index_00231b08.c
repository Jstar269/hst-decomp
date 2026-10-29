/* HSTMATCH module=EBOOT.BIN start=0x00231b08 end=0x00231ba0 symbol=FUN_00231b08 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a3/v0) corrected by hand: typed the record tables as floats and used the short-circuit index guard; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/challenge_menu.h"

extern int DAT_002f3664;  /* index requested in advance, -1 when none */
extern u32 FUN_0022c194();

/* Choose the selected point (the requested one, else FUN_0022c194's), fall back to 0 when it is unusable, and copy its position. */
void FUN_00231b08(ChallengeMenu *self)
{
  u32 picked;
  
  if (DAT_002f3664 < 0) {
    picked = FUN_0022c194();
    self->selected = picked;
  }
  else {
    self->selected = DAT_002f3664;
    DAT_002f3664 = -1;
  }
  if (self->selected < 0 || self->count[self->selected] == 0) {
    self->selected = 0;
  }
  self->pos_x = self->x[self->selected];
  self->pos_y = self->y[self->selected];
}
