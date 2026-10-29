/* HSTMATCH module=EBOOT.BIN start=0x00266748 end=0x00266760 symbol=FUN_00266748 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/mover.h"

/* Zeroes the body's +0xd0 float. */
void FUN_00266748(Mover *self)
{
  if (self->body != 0) {
    *(u32 *)&self->body->unkd0 = 0;
  }
}
