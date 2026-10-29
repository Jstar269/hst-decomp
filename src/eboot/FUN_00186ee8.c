/* HSTMATCH module=EBOOT.BIN start=0x00186ee8 end=0x00186f18 symbol=FUN_00186ee8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/slide_screen.h"

extern void FUN_00102c54();

/* Clears the flag and moves the pane at 0x28 to x = base - step * index. */
void FUN_00186ee8(SlideScreen *self,int index)
{
  self->unk1250 = 0;
  self->pos28->x = (float)(self->base - self->step * index);
  FUN_00102c54(self->pos28);
}
