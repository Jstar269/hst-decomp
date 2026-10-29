/* HSTMATCH module=EBOOT.BIN start=0x001a47e8 end=0x001a4824 symbol=FUN_001a47e8 lang=c99 */
/* Hand-written reconstruction from the disassembly (range check written as one && condition); exact match verified; names and types await human review. */
#include "hst/slot_select.h"

/* Set the 0/1 mode; 0xff and out-of-range values select 0. */
void FUN_001a47e8(SlotSelect *self,int mode)
{
  if (mode == 0xff) {
    self->mode = 0;
  }
  else if (mode >= 0 && mode < 2) {
    self->mode = mode;
  }
  else {
    self->mode = 0;
  }
}
