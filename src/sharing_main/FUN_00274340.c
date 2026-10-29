/* HSTMATCH module=hstp_trans_main.prx start=0x00274340 end=0x002743d4 symbol=FUN_00274340 lang=c99 */
/* Clone of src/eboot/FUN_002634c4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/screen_obj.h"

extern u32 DAT_003ea8ec;
extern u8 DAT_003f39a8;
extern void FUN_00108f54();
extern void FUN_00244258();
extern void FUN_002929dc();

/* Copy the part value into the panel, refresh the panel, then pass 0x40 (panel mode 1 with value 2) or 0x3f to the helper. */
void FUN_00274340(ScreenObj *self)
{
  FUN_00108f54(DAT_003ea8ec,1);
  self->panel->unk61c = self->part->unkdc;
  FUN_002929dc(self->panel);
  if ((self->panel->unk80 == 1) &&
     (self->panel->unk61c == 2)) {
    FUN_00244258(&DAT_003f39a8,0x40);
  }
  else {
    FUN_00244258(&DAT_003f39a8,0x3f);
  }
}
