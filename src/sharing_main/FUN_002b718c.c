/* HSTMATCH module=hstp_trans_main.prx start=0x002b718c end=0x002b7198 symbol=FUN_002b718c lang=c99 */
/* Clone of src/eboot/FUN_002a79fc.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/mode_panel_obj.h"

extern void FUN_00111aa4();

void FUN_002b718c(ModePanel *self,u32 value)
{
  FUN_00111aa4(self->gfx,value,0);
}
