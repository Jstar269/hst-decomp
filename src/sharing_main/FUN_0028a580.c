/* HSTMATCH module=hstp_trans_main.prx start=0x0028a580 end=0x0028a58c symbol=FUN_0028a580 lang=c99 */
/* Clone of src/eboot/FUN_0027929c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/mode_menu.h"

extern void FUN_00111aa4();

/* Forwards a key to the sub object. */
void FUN_0028a580(ModeMenu *self,u32 key)
{
  FUN_00111aa4(self->sub,key,0);
}
