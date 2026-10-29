/* HSTMATCH module=EBOOT.BIN start=0x0026672c end=0x00266748 symbol=FUN_0026672c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/mover.h"

/* Copies the body's +0xc4 float to +0xd0. */
void FUN_0026672c(Mover *self)
{
  MoverBody *body;

  body = self->body;
  if (body != 0) {
    body->unkd0 = body->unkc4;
  }
}
