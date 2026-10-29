/* HSTMATCH module=EBOOT.BIN start=0x002667b8 end=0x002667f4 symbol=FUN_002667b8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/mover.h"

extern float DAT_002fdef8;

/* Stores the value into the mover, raised to the minimum DAT_002fdef8. */
void FUN_002667b8(float value,Mover *self)
{
  float *chosen;
  float local_4;

  local_4 = value;
  if (value < DAT_002fdef8) {
    chosen = &DAT_002fdef8;
  }
  else {
    chosen = &local_4;
  }
  self->unk110 = *chosen;
}
