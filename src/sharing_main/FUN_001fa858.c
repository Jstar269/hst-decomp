/* HSTMATCH module=hstp_trans_main.prx start=0x001fa858 end=0x001fa8a4 symbol=FUN_001fa858 lang=c99 */
/* Clone of src/eboot/FUN_001ec518.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/overlay_obj.h"

extern void FUN_001f6b08();
extern void FUN_001f9c3c();

void FUN_001fa858(OverlayObj *self,int param_2)
{
  if (self->part_a != 0) {
    FUN_001f9c3c(self->part_a);
    FUN_001f6b08(*self->link,param_2);
  }
}
