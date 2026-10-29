/* HSTMATCH module=hstp_trans_main.prx start=0x00123f3c end=0x00123f44 symbol=FUN_00123f3c lang=c99 */
/* Clone of src/eboot/FUN_00118ad4.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/deque_owner.h"

extern void FUN_00128280();

/* Forwards the container and its +0x14 word to FUN_00128280. */
void FUN_00123f3c(u32 self,DequeBox *box)
{
  FUN_00128280(self,box,box->unk14);
}
