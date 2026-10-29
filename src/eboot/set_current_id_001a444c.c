/* HSTMATCH module=EBOOT.BIN start=0x001a444c end=0x001a44a4 symbol=FUN_001a444c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag p128a) corrected by hand: FUN_0016baa0 takes an int first parameter (no seh, the short cast dropped); readability pass; exact match verified; names and types await human review. */
#include "hst/slot_select.h"

extern int FUN_0016b534(void);
extern void FUN_0016baa0(int id,u8 wasUnset);

/* Apply the second list's selected id; a random one when it is unset. */
void FUN_001a444c(SlotSelect *self)
{
  bool wasUnset;
  int id;
  
  id = *self->idTable[self->listCursor.index];
  wasUnset = id == SLOT_SELECT_ID_NONE;
  if (wasUnset) {
    id = FUN_0016b534();
  }
  FUN_0016baa0(id,(u8)(wasUnset));
}
