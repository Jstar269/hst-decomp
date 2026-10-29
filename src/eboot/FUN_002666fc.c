/* HSTMATCH module=EBOOT.BIN start=0x002666fc end=0x00266714 symbol=FUN_002666fc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/mover.h"

/* Stores a byte into the body at +0xc0. */
void FUN_002666fc(Mover *self,u8 value)
{
  if (self->body != 0) {
    self->body->unkc0 = value;
  }
}
