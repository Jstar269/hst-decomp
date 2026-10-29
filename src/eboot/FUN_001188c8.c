/* HSTMATCH module=EBOOT.BIN start=0x001188c8 end=0x00118908 symbol=FUN_001188c8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/deque_owner.h"

extern int FUN_0005ba00();

/* Releases the owned object at +0xec, if any. */
void FUN_001188c8(DequeOwner *self)
{
  void *owned;
  
  owned = self->unkec;
  if ((owned != 0) && (owned != 0)) {
    FUN_0005ba00(owned,1);
    self->unkec = 0;
  }
}
