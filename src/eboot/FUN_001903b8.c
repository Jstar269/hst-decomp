/* HSTMATCH module=EBOOT.BIN start=0x001903b8 end=0x001903e8 symbol=FUN_001903b8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/deque_owner.h"

extern u32 * FUN_001903e8();

/* Constructor: base setup, then clears the two trailing words. */
DequeBox * FUN_001903b8(DequeBox *self)
{
  FUN_001903e8();
  self->unk10 = 0;
  self->unk14 = 0;
  return self;
}
