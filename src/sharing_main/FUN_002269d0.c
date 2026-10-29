/* HSTMATCH module=hstp_trans_main.prx start=0x002269d0 end=0x002269dc symbol=FUN_002269d0 lang=c99 */
/* Clone of src/eboot/FUN_00217928.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/animator.h"

/* Clear the colour block's flags. */
void FUN_002269d0(Animator *self)
{
  self->color.head.active = 0;
  self->color.head.done = 0;
}
