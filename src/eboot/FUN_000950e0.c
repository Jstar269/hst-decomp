/* HSTMATCH module=EBOOT.BIN start=0x000950e0 end=0x00095104 symbol=FUN_000950e0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe1) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/keyed_state.h"

/* True when the frame matches, or when the mode is 3 or above (frame not compared). */
bool FUN_000950e0(KeyedState *self,int frame)
{
  bool same;
  
  if (self->mode < 3) {
    same = self->frame == frame;
  }
  else {
    same = true;
  }
  return same;
}
