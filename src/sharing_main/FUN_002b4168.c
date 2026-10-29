/* HSTMATCH module=hstp_trans_main.prx start=0x002b4168 end=0x002b41b0 symbol=FUN_002b4168 lang=c99 */
/* Clone of src/eboot/FUN_002a49d8.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/savedata_screen.h"

extern u8 DAT_003b31ac;
extern SaveScreen * DAT_003f469c;
extern u32 * FUN_0001ec44();
extern void FUN_002b46a8();

/* Constructor: set the vtable, register as the active instance, enter the idle state. */
SaveScreen * FUN_002b4168(SaveScreen *self)
{
  FUN_0001ec44();
  self->vtbl = &DAT_003b31ac;
  DAT_003f469c = self;
  FUN_002b46a8(self,SAVE_STATE_IDLE);
  return self;
}
