/* HSTMATCH module=EBOOT.BIN start=0x00126884 end=0x001268b8 symbol=FUN_00126884 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/ring_owner.h"

extern u32 FUN_000ff678();

/* Read up to *len bytes from the ring into dst; *len receives the count read. */
void FUN_00126884(RingOwner *self,u32 dst,u32 *len)
{
  u32 count;
  
  count = FUN_000ff678(self->ring,dst,*len,0);
  *len = count;
}
