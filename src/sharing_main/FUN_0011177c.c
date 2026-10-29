/* HSTMATCH module=hstp_trans_main.prx start=0x0011177c end=0x001117ec symbol=FUN_0011177c lang=c99 */
/* Clone of src/eboot/FUN_0010b5a4.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/mode_list.h"

extern void FUN_00110f78();
extern void FUN_00111474();

/* Reset the list (keep_position = 0), load the first two halfwords of the current record, refresh the shown items. */
void FUN_0011177c(ModeList *self)
{
  FUN_00111474(self,0);
  self->unkec = *(short *)((char *)self->recs + self->cur * 0xc);
  self->unkee = *(short *)((char *)self->recs + self->cur * 0xc + 2);
  FUN_00110f78(self);
  return;
}
