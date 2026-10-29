/* HSTMATCH module=hstp_trans_main.prx start=0x002269c4 end=0x002269d0 symbol=FUN_002269c4 lang=c99 */
/* Clone of src/eboot/FUN_0021791c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/animator.h"

/* Clear the flags of the block at +0x3c. */
void FUN_002269c4(Animator *self)
{
  self->block3c.active = 0;
  self->block3c.done = 0;
}
