/* HSTMATCH module=hstp_trans_main.prx start=0x0011185c end=0x001118ac symbol=FUN_0011185c lang=c99 */
/* Clone of src/eboot/FUN_0010b684.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/mode_list.h"

extern void FUN_00110f78();
extern void FUN_00111474();

/* Reset the list, then set its highlight mode and refresh the shown items. */
void FUN_0011185c(ModeList *self,u32 mode,u8 flag)
{
  FUN_00111474(self,0);
  self->unk114 = flag;
  self->mode = mode;
  FUN_00110f78(self);
}
