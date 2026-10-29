/* HSTMATCH module=hstp_trans_main.prx start=0x002b4674 end=0x002b46a8 symbol=FUN_002b4674 lang=c99 */
/* Clone of src/eboot/FUN_002a4ee4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/savedata_screen.h"

extern void FUN_001109a8();

/* While running, step the worker. */
void FUN_002b4674(SaveScreen *self)
{
  if (self->state == SAVE_STATE_RUN) {
    FUN_001109a8(self->worker,&self->unk5d4);
  }
}
