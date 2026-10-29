/* HSTMATCH module=EBOOT.BIN start=0x0011844c end=0x0011847c symbol=FUN_0011844c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/deque_owner.h"

extern u32 * FUN_0011847c();

/* Container constructor: runs the base constructor and zeroes the two tail words. */
DequeBox * FUN_0011844c(DequeBox *self)
{
  FUN_0011847c();
  self->unk10 = 0;
  self->unk14 = 0;
  return self;
}
