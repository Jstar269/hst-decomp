/* HSTMATCH module=EBOOT.BIN start=0x00279b24 end=0x00279b34 symbol=FUN_00279b24 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/mode_menu.h"

#define COUNTDOWN_START 0x1e

/* Starts the countdown that FUN_00279b50 ticks. */
void FUN_00279b24(ModeMenu *self)
{
  self->countdown = COUNTDOWN_START;
  self->timedOut = 0;
}
