/* HSTMATCH module=hstp_trans_main.prx start=0x0022d7d0 end=0x0022d848 symbol=FUN_0022d7d0 lang=c99 */
/* Clone of src/eboot/FUN_0021e25c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/digit_panel.h"

extern void FUN_00108dac();

/* Move every layer to (x, y); does nothing when the position is unchanged. */
void FUN_0022d7d0(float x,float y,DigitPanel *self)
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
  FUN_00108dac(self);
}
