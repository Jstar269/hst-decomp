/* HSTMATCH module=hstp_trans_main.prx start=0x0026d164 end=0x0026d1ac symbol=FUN_0026d164 lang=c99 */
/* Clone of src/eboot/FUN_0025ccb4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/adhoc_menu.h"

extern u32 DAT_003ea8ec;
extern void FUN_00108f54();
extern void FUN_00292408();

/* Clears the two menu flags, resets the menu and the object at DAT_003ea8ec, and restarts the menu helper. */
void FUN_0026d164(AdhocMenu *self)
{
  self->unk54 = 0;
  self->unk55 = 0;
  FUN_00108f54(self,1);
  FUN_00108f54(DAT_003ea8ec,1);
  FUN_00292408(self->unk5c);
}
