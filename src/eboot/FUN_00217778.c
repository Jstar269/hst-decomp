/* HSTMATCH module=EBOOT.BIN start=0x00217778 end=0x002177d4 symbol=FUN_00217778 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/animator.h"

extern void FUN_0021791c();
extern void FUN_00217928();
extern void FUN_00217934();

/* Init the animator from a source id: start at (0, 0) when there is one and stop the blocks. */
void FUN_00217778(Animator *self,int src)
{
  self->src = src;
  self->node = 0;
  self->unk10 = 0;
  if (self->src != 0) {
    self->x = 0;
    self->y = 0;
    self->unk0c = 0x80;
  }
  FUN_0021791c(self);
  FUN_00217928(self);
  FUN_00217934(self);
}
