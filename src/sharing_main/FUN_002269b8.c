/* HSTMATCH module=hstp_trans_main.prx start=0x002269b8 end=0x002269c4 symbol=FUN_002269b8 lang=c99 */
/* Clone of src/eboot/FUN_00217910.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/animator.h"

/* Clear the position block's flags. */
void FUN_002269b8(Animator *self)
{
  self->pos.head.active = 0;
  self->pos.head.done = 0;
}
