/* HSTMATCH module=hstp_trans_main.prx start=0x002267ac end=0x00226820 symbol=FUN_002267ac lang=c99 */
/* Clone of src/eboot/FUN_00217704.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/animator.h"

extern void FUN_002269c4();
extern void FUN_002269d0();
extern void FUN_002269dc();

/* Init the animator around a placed node: take its x/y as the start position and stop the blocks. */
void FUN_002267ac(Animator *self,ModeNode *node)
{
  self->src = 0;
  self->node = node;
  self->unk10 = 0;
  if (self->node != 0) {
    self->x = (short)(int)node->x;
    self->y = (short)(int)node->y;
    self->unk0c = 0x80;
  }
  FUN_002269c4(self);
  FUN_002269d0(self);
  FUN_002269dc(self);
}
