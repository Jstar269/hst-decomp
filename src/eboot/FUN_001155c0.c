/* HSTMATCH module=EBOOT.BIN start=0x001155c0 end=0x0011564c symbol=FUN_001155c0 lang=c99 rodata=0x002c11e0 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/pane_mode.h"

/* Per-mode boolean query; 0 while the flagged count is 1 or 2. */
int FUN_001155c0(PaneModeObj *self)
{
  if ((self->flags & 8) != 0) {
    int count = self->unk88;
    if (count > 0 && count < 3) return 0;
  }
  switch (self->mode) {
  case 1:
    return 1 < self->owner->unk68;
  case 2:
  case 5:
    return self->unk7c;
  case 6:
    return self->unk84;
  case 0:
  case 3:
  case 4:
  default:
    return 0;
  }
}
