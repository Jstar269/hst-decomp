/* HSTMATCH module=EBOOT.BIN start=0x0017c344 end=0x0017c39c symbol=FUN_0017c344 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1/v0) corrected by hand: corrected the helper return type and short-circuit returns; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/pending_slots.h"

extern u32 FUN_001fe848();
extern int FUN_001fe974();

/* Returns 1 when both checks (copy slot, then current slot) return 0 for the state. */
int FUN_0017c344(PendingSlotsObj *self)
{
  int rejected;
  
  rejected = FUN_001fe974(&self->copy,self->state);
  if (rejected == 0) {
    rejected = FUN_001fe848(&self->current,self->state,0);
    if (rejected == 0) return 1;
  }
  return 0;
}
