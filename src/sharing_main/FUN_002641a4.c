/* HSTMATCH module=hstp_trans_main.prx start=0x002641a4 end=0x002641d4 symbol=FUN_002641a4 lang=c99 */
/* Clone of src/eboot/FUN_00118384.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/deque_owner.h"

extern u32 * FUN_002641d4();

/* Container constructor: runs the base constructor and zeroes the two tail words. */
DequeBox * FUN_002641a4(DequeBox *self)
{
  FUN_002641d4();
  self->unk10 = 0;
  self->unk14 = 0;
  return self;
}
