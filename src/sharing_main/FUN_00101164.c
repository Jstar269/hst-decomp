/* HSTMATCH module=hstp_trans_main.prx start=0x00101164 end=0x001011c4 symbol=FUN_00101164 lang=c99 */
/* Clone of src/eboot/FUN_000fba28.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/mode_screen.h"

extern u8 DAT_003b0a10;
extern ModeScreen * DAT_003e1f64;
extern u32 * FUN_0001ec44();

/* Constructor: set the vtable, register as the active instance and clear every field. */
ModeScreen * FUN_00101164(ModeScreen *self)
{
  FUN_0001ec44();
  self->vtbl = &DAT_003b0a10;
  self->core = 0;
  DAT_003e1f64 = self;
  self->slot[0] = 0;
  self->slot[1] = 0;
  self->slot[2] = 0;
  self->slot[3] = 0;
  self->slot[4] = 0;
  self->slot[5] = 0;
  self->active = 0;
  self->timer = 0;
  return self;
}
