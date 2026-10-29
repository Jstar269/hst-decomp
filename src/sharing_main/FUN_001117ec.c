/* HSTMATCH module=hstp_trans_main.prx start=0x001117ec end=0x0011185c symbol=FUN_001117ec lang=c99 */
/* Clone of src/eboot/FUN_0010b614.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/mode_list.h"

extern void FUN_00110f78();
extern void FUN_00111474();

/* Reset the list (keep_position = 1), load the first two halfwords of the current record, refresh the shown items. */
void FUN_001117ec(ModeList *self)
{
  FUN_00111474(self,1);
  self->unkec = *(short *)((char *)self->recs + self->cur * 0xc);
  self->unkee = *(short *)((char *)self->recs + self->cur * 0xc + 2);
  FUN_00110f78(self);
  return;
}
