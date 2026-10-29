/* HSTMATCH module=hstp_trans_main.prx start=0x001b1a70 end=0x001b1af8 symbol=FUN_001b1a70 lang=c99 data=0x003895cc */
/* Clone of src/eboot/FUN_001a44a4.c (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x003895cc-0x003895dd) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/slot_select.h"

extern void FUN_00177c64();
extern int FUN_001aabec();
extern int FUN_001b1900();

/* Apply the second list's selected id (logging a random pick when unset), then remember its cursor. */
void FUN_001b1a70(SlotSelect *self)
{
  int wasUnset;
  int id;
  int randomId;
  
  id = *self->idTable[self->listCursor.index];
  wasUnset = id == SLOT_SELECT_ID_NONE;
  if (wasUnset) {
    randomId = FUN_001b1900();
    id = FUN_001aabec("RandomSinpan=%d\n",randomId);
  }
  FUN_00177c64(id,wasUnset);
  self->listCursorSaved.row = self->listCursor.row;
  self->listCursorSaved.index = self->listCursor.index;
  self->listCursorSaved.top = self->listCursor.top;
  return;
}
