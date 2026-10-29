/* HSTMATCH module=EBOOT.BIN start=0x0011a004 end=0x0011a078 symbol=FUN_0011a004 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag p1) corrected by hand: readability pass (names, structs, constants); refined by hstperm.py random mutation (perm-p1/r00/f0475_0011a004_m03.c); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/track_slots.h"

extern u32 DAT_002d5ab0;
extern void FUN_0005f1e8();

void FUN_0011a004(TrackSlots *self)
{
  int index;
  
  if ((DAT_002d5ab0 & 0x800) != 0) {
    index = 0;
    do {
      if (self->active[index] != 0) {
        FUN_0005f1e8(self->handles[index],self->unkec);
      }
      index = index + 1;
    } while (index < TRACK_SLOT_COUNT);
  }
}
