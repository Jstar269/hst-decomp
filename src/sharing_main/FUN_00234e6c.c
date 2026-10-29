/* HSTMATCH module=hstp_trans_main.prx start=0x00234e6c end=0x00234f04 symbol=FUN_00234e6c lang=c99 */
/* Clone of src/eboot/FUN_002258f8.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/mode_parts.h"

extern u8 DAT_003b28d4;
extern u32 DAT_003f3610;
extern u32 DAT_003f3b50;
extern void FUN_00000a00();
extern u32 * FUN_0001ed28();
extern int * FUN_002347fc();
extern void FUN_002a32e8();

/* Deleting destructor: drop the global instance pointer, delete the part set, then the base. */
ModeObj * FUN_00234e6c(ModeObj *self,short delete_flag)
{
  if (self != (ModeObj *)0x0) {
    self->vtbl = &DAT_003b28d4;
    DAT_003f3610 = 0;
    if (self->parts != (ModeParts *)0x0) {
      FUN_002347fc(self->parts,1);
      self->parts = 0;
    }
    if (DAT_003f3b50 != 0) {
      FUN_002a32e8(DAT_003f3b50);
    }
    FUN_0001ed28(self,0);
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
