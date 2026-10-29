/* HSTMATCH module=EBOOT.BIN start=0x0021e25c end=0x0021e2d4 symbol=FUN_0021e25c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag u1ge) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/digit_panel.h"

extern void FUN_00103480();

/* Move every layer to (x, y); does nothing when the position is unchanged. */
void FUN_0021e25c(float x,float y,DigitPanel *self)
{
  if (self->pos_x == x) {
    if (self->pos_y == y) {
      return;
    }
    self->pos_x = x;
  }
  else {
    self->pos_x = x;
  }
  self->pos_y = y;
  self->layer[0]->x = x;
  self->layer[0]->y = y;
  self->layer[1]->x = x;
  self->layer[1]->y = y;
  self->layer[2]->x = x;
  self->layer[2]->y = y;
  FUN_00103480(self);
}
