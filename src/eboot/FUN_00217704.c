/* HSTMATCH module=EBOOT.BIN start=0x00217704 end=0x00217778 symbol=FUN_00217704 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/animator.h"

extern void FUN_0021791c();
extern void FUN_00217928();
extern void FUN_00217934();

/* Init the animator around a placed node: take its x/y as the start position and stop the blocks. */
void FUN_00217704(Animator *self,ModeNode *node)
{
  self->src = 0;
  self->node = node;
  self->unk10 = 0;
  if (self->node != 0) {
    self->x = (short)(int)node->x;
    self->y = (short)(int)node->y;
    self->unk0c = 0x80;
  }
  FUN_0021791c(self);
  FUN_00217928(self);
  FUN_00217934(self);
}
