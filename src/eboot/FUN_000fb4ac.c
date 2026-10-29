/* HSTMATCH module=EBOOT.BIN start=0x000fb4ac end=0x000fb4d0 symbol=FUN_000fb4ac lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/mode_screen.h"

/* Store a byte in the core's first target, if there is one. */
void FUN_000fb4ac(ModeScreen *self,u8 value)
{
  ModeTarget *target;
  
  if ((self->core != 0) &&
     (target = self->core->targetA, target != 0)) {
    target->unk870 = value;
  }
}
