/* HSTMATCH module=EBOOT.BIN start=0x001268b8 end=0x001268c4 symbol=FUN_001268b8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/ring_owner.h"

extern u32 FUN_000ff678();

/* Same ring call as the read above with the last argument set to 1. */
void FUN_001268b8(RingOwner *self,u32 buf,u32 len)
{
  FUN_000ff678(self->ring,buf,len,1);
}
