/* HSTMATCH module=hstp_trans_main.prx start=0x0019cbc8 end=0x0019cbf8 symbol=FUN_0019cbc8 lang=c99 */
/* Clone of src/eboot/FUN_00118384.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/deque_owner.h"

extern u32 * FUN_0019cbf8();

/* Container constructor: runs the base constructor and zeroes the two tail words. */
DequeBox * FUN_0019cbc8(DequeBox *self)
{
  FUN_0019cbf8();
  self->unk10 = 0;
  self->unk14 = 0;
  return self;
}
