/* HSTMATCH module=hstp_trans_main.prx start=0x001fa69c end=0x001fa6f8 symbol=FUN_001fa69c lang=c99 */
/* Clone of src/eboot/FUN_001ec35c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/overlay_obj.h"

extern OverlayObj *DAT_003f3470;
extern void FUN_00000a00();
extern void FUN_001fa758();
extern void FUN_001fadcc();

/* Destructor: unregister the overlay, free its parts, reset the default view matrix, and delete it when flag > 0. */
OverlayObj * FUN_001fa69c(OverlayObj *self,short flag)
{
  if (self != 0) {
    DAT_003f3470 = 0;
    FUN_001fa758();
    FUN_001fadcc(self);
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
