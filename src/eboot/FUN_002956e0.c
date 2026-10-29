/* HSTMATCH module=EBOOT.BIN start=0x002956e0 end=0x002956ec symbol=FUN_002956e0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/ring_owner.h"

/* Reset the ring: clear both positions. */
void FUN_002956e0(RingBuf *ring)
{
  ring->unk10 = 0;
  ring->unk0c = 0;
}
