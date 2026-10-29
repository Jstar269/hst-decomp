/* HSTMATCH module=hstp_trans_main.prx start=0x00226820 end=0x0022687c symbol=FUN_00226820 lang=c99 */
/* Clone of src/eboot/FUN_00217778.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/animator.h"

extern void FUN_002269c4();
extern void FUN_002269d0();
extern void FUN_002269dc();

/* Init the animator from a source id: start at (0, 0) when there is one and stop the blocks. */
void FUN_00226820(Animator *self,int src)
{
  self->src = src;
  self->node = 0;
  self->unk10 = 0;
  if (self->src != 0) {
    self->x = 0;
    self->y = 0;
    self->unk0c = 0x80;
  }
  FUN_002269c4(self);
  FUN_002269d0(self);
  FUN_002269dc(self);
}
