/* HSTMATCH module=EBOOT.BIN start=0x0024759c end=0x002475bc symbol=FUN_0024759c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag u1ge) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/posed_obj.h"

/* Set the mode; when it changes, mark the object dirty. */
void FUN_0024759c(PosedObj *self,int mode)
{
  if (self->mode != mode) {
    self->mode = mode;
    self->dirty = 1;
  }
}
