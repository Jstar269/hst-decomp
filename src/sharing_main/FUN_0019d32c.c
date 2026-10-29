/* HSTMATCH module=hstp_trans_main.prx start=0x0019d32c end=0x0019d3b0 symbol=FUN_0019d32c lang=c99 */
/* Clone of src/eboot/FUN_0011cc1c.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/block_deque.h"

extern void FUN_00000a00();
extern u32 * FUN_0019d3b0();
extern void FUN_0019d810();
extern void FUN_0019e050();

/* Deleting destructor of a block deque: destroy the elements from begin to end, tear down the map, free self when flags > 0. */
BlockDeque * FUN_0019d32c(BlockDeque *self,short flags)
{
  BlockDequePos begin;
  BlockDequePos end;

  if (self != 0) {
    FUN_0019e050(&end,self,self->length);
    FUN_0019e050(&begin,self,0);
    FUN_0019d810(self,&begin,&end);
    FUN_0019d3b0(self,0);
    if (0 < flags) {
      FUN_00000a00(self);
    }
  }
  return self;
}
