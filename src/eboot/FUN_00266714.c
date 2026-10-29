/* HSTMATCH module=EBOOT.BIN start=0x00266714 end=0x0026672c symbol=FUN_00266714 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/mover.h"

/* Stores a float into the body at +0xc4. */
void FUN_00266714(float value,Mover *self)
{
  if (self->body != 0) {
    self->body->unkc4 = value;
  }
}
