/* HSTMATCH module=EBOOT.BIN start=0x0021caa0 end=0x0021cacc symbol=FUN_0021caa0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/cell_sprite.h"

extern void FUN_00103628();

void FUN_0021caa0(CellSprite *self)
{
  FUN_00103628(self,0);
  self->hidden = 0;
}
