/* HSTMATCH module=EBOOT.BIN start=0x0021ca18 end=0x0021ca68 symbol=FUN_0021ca18 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag p128a) corrected by hand: typed the integer count and float-one fields; readability pass; exact match verified; names and types await human review. */
#include "hst/cell_sprite.h"

extern void FUN_00103480();

/* Copies the position into both state objects and sets their unk78 to 1.0f. */
void FUN_0021ca18(CellSprite *self)
{
  self->unk64 = 100;
  self->stateA->x = self->x;
  self->stateA->y = self->y;
  self->stateA->unk78 = 1.0f;
  self->stateB->x = self->x;
  self->stateB->y = self->y;
  self->stateB->unk78 = 1.0f;
  FUN_00103480(self);
  return;
}
