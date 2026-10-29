/* HSTMATCH module=hstp_trans_main.prx start=0x001cf6dc end=0x001cf72c symbol=FUN_001cf6dc lang=c99 */
/* Clone of src/eboot/FUN_001c14c8.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/record_table.h"

extern void FUN_001ccd50();
extern void FUN_001cf558();

/* Reset the base part, refill the records and clear the byte pairs. */
void FUN_001cf6dc(RecordTable *self)
{
  int i;
  RecordTable *cur = self;
  
  FUN_001ccd50(cur->handle);
  self->unk410 = 0;
  FUN_001cf558(self);
  i = 0;
  do {
    cur->pair[0][0] = 0;
    i = i + 1;
    cur->pair[0][1] = 0;
    cur = (RecordTable *)((char *)cur + 2);
  } while (i < 2);
}
