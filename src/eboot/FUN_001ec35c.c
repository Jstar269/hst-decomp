/* HSTMATCH module=EBOOT.BIN start=0x001ec35c end=0x001ec3b8 symbol=FUN_001ec35c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/overlay_obj.h"

extern OverlayObj *DAT_0034a138;
extern void FUN_00000a00();
extern void FUN_001ec418();
extern void FUN_001eca5c();

/* Destructor: unregister the overlay, free its parts, reset the default view matrix, and delete it when flag > 0. */
OverlayObj * FUN_001ec35c(OverlayObj *self,short flag)
{
  if (self != 0) {
    DAT_0034a138 = 0;
    FUN_001ec418();
    FUN_001eca5c(self);
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
