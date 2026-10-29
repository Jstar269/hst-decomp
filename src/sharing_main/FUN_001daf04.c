/* HSTMATCH module=hstp_trans_main.prx start=0x001daf04 end=0x001daf64 symbol=FUN_001daf04 lang=c99 */
/* Clone of src/eboot/FUN_001cc7d0.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/name_box_owner.h"

extern u32 * FUN_000149a8();
extern int FUN_00014a40();
extern void FUN_00197150();

/* Sets the second name buffer when `name` fits and tells the panel's widget. */
void FUN_001daf04(NameBoxOwner *self,u32 name)
{
  u32 length;
  PanelData *panel;
  
  length = FUN_00014a40(name);
  if (length < NAME_BOX_NAME_LIMIT) {
    FUN_000149a8(self->nameB,name);
    panel = self->panel;
    FUN_00197150(panel->unk20);
    panel->unk64 = 1;
  }
}
