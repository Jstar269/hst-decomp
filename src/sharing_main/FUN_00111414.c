/* HSTMATCH module=hstp_trans_main.prx start=0x00111414 end=0x00111474 symbol=FUN_00111414 lang=c99 */
/* Clone of src/eboot/FUN_0010b308.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/mode_list.h"

extern void FUN_00111474();
extern void FUN_00120e84();

#define MODE_REC_MIN_CAP 4 /* record table capacity reserved on init */

/* Initialise the list: first item shown, default mode, record table reserved. */
void FUN_00111414(ModeList *self)
{
  self->first = 0;
  self->orient = 0;
  self->start = 0;
  self->unk114 = 0;
  self->mode = 0;
  if (self->rec_cap < MODE_REC_MIN_CAP) {
    FUN_00120e84(&self->recs,MODE_REC_MIN_CAP);
  }
  self->unk12d = 1;
  FUN_00111474(self,0);
}
