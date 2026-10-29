/* HSTMATCH module=EBOOT.BIN start=0x00279b50 end=0x00279b7c symbol=FUN_00279b50 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag u1ge) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/mode_menu.h"

/* Counts the countdown down; sets timedOut when it reaches zero. */
void FUN_00279b50(ModeMenu *self)
{
  int remaining;
  
  if ((0 < self->countdown) &&
     (remaining = self->countdown + -1, self->countdown = remaining, remaining < 1)) {
    self->countdown = 0;
    self->timedOut = 1;
  }
}
