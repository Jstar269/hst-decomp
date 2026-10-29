/* HSTMATCH module=EBOOT.BIN start=0x00118384 end=0x001183b4 symbol=FUN_00118384 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/deque_owner.h"

extern u32 * FUN_001183b4();

/* Container constructor: runs the base constructor and zeroes the two tail words. */
DequeBox * FUN_00118384(DequeBox *self)
{
  FUN_001183b4();
  self->unk10 = 0;
  self->unk14 = 0;
  return self;
}
