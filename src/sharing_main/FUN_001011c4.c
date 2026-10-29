/* HSTMATCH module=hstp_trans_main.prx start=0x001011c4 end=0x00101230 symbol=FUN_001011c4 lang=c99 */
/* Clone of src/eboot/FUN_000fba88.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/mode_screen.h"

extern u8 DAT_003b0a10;
extern ModeScreen * DAT_003e1f64;
extern void FUN_00000a00();
extern u32 * FUN_0001ed28();
extern void FUN_00101334();

/* Destructor: unregister the active instance; free the object when the flag is positive. */
ModeScreen * FUN_001011c4(ModeScreen *self,short deleteFlag)
{
  if (self != (ModeScreen *)0x0) {
    self->vtbl = &DAT_003b0a10;
    DAT_003e1f64 = 0;
    FUN_00101334();
    FUN_0001ed28(self,0);
    if (0 < deleteFlag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
