/* HSTMATCH module=EBOOT.BIN start=0x001a44a4 end=0x001a452c symbol=FUN_001a44a4 lang=c99 data=0x002e1cfc */
/* Ghidra pseudocode (hstgen.py tag q4) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002e1cfc-0x002e1d0d) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/slot_select.h"

extern void FUN_0016baa0();
extern int FUN_0019ee24();
extern int FUN_001a4334();

/* Apply the second list's selected id (logging a random pick when unset), then remember its cursor. */
void FUN_001a44a4(SlotSelect *self)
{
  int wasUnset;
  int id;
  int randomId;
  
  id = *self->idTable[self->listCursor.index];
  wasUnset = id == SLOT_SELECT_ID_NONE;
  if (wasUnset) {
    randomId = FUN_001a4334();
    id = FUN_0019ee24("RandomSinpan=%d\n",randomId);
  }
  FUN_0016baa0(id,wasUnset);
  self->listCursorSaved.row = self->listCursor.row;
  self->listCursorSaved.index = self->listCursor.index;
  self->listCursorSaved.top = self->listCursor.top;
  return;
}
