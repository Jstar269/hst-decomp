/* HSTMATCH module=hstp_trans_main.prx start=0x00123620 end=0x00123650 symbol=FUN_00123620 lang=c99 */
/* Clone of src/eboot/FUN_00118384.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/deque_owner.h"

extern u32 * FUN_00123650();

/* Container constructor: runs the base constructor and zeroes the two tail words. */
DequeBox * FUN_00123620(DequeBox *self)
{
  FUN_00123650();
  self->unk10 = 0;
  self->unk14 = 0;
  return self;
}
