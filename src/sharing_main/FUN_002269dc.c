/* HSTMATCH module=hstp_trans_main.prx start=0x002269dc end=0x002269e8 symbol=FUN_002269dc lang=c99 */
/* Clone of src/eboot/FUN_00217934.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/animator.h"

/* Clear the pair block's flags. */
void FUN_002269dc(Animator *self)
{
  self->pair.head.active = 0;
  self->pair.head.done = 0;
}
