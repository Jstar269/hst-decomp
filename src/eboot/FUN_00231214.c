/* HSTMATCH module=EBOOT.BIN start=0x00231214 end=0x00231240 symbol=FUN_00231214 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/singleton_holder.h"

extern void FUN_00231248();

/* If the holder is pending, clear it (which notifies the target). */
void FUN_00231214(SingletonHolder *self)
{
  if (self->pending == HOLDER_PENDING_SET) {
    FUN_00231248(self,0);
  }
}
