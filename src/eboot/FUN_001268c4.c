/* HSTMATCH module=EBOOT.BIN start=0x001268c4 end=0x001268d8 symbol=FUN_001268c4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/ring_owner.h"

/* Bytes available in the ring. */
int FUN_001268c4(RingOwner *self)
{
  return self->ring->unk10 - self->ring->unk0c;
}
