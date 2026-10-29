/* HSTMATCH module=EBOOT.BIN start=0x0010b308 end=0x0010b368 symbol=FUN_0010b308 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/mode_list.h"

extern void FUN_0010b368();
extern void FUN_00115f68();

#define MODE_REC_MIN_CAP 4 /* record table capacity reserved on init */

/* Initialise the list: first item shown, default mode, record table reserved. */
void FUN_0010b308(ModeList *self)
{
  self->first = 0;
  self->orient = 0;
  self->start = 0;
  self->unk114 = 0;
  self->mode = 0;
  if (self->rec_cap < MODE_REC_MIN_CAP) {
    FUN_00115f68(&self->recs,MODE_REC_MIN_CAP);
  }
  self->unk12d = 1;
  FUN_0010b368(self,0);
}
