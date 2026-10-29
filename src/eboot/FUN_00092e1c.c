/* HSTMATCH module=EBOOT.BIN start=0x00092e1c end=0x00092e38 symbol=FUN_00092e1c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe1) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/char_model.h"

/* Sets the flag on model item 2, if present, to 1. */
void FUN_00092e1c(CharModel *self)
{
  if (self->item[2] != 0) {
    self->item[2]->unk170 = 1;
  }
}
