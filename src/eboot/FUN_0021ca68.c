/* HSTMATCH module=EBOOT.BIN start=0x0021ca68 end=0x0021caa0 symbol=FUN_0021ca68 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/cell_sprite.h"

extern void FUN_00103628();

void FUN_0021ca68(CellSprite *self)
{
  FUN_00103628(self,1);
  self->hidden = 1;
  self->unk64 = -1;
}
