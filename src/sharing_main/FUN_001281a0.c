/* HSTMATCH module=hstp_trans_main.prx start=0x001281a0 end=0x00128224 symbol=FUN_001281a0 lang=c99 */
/* Clone of src/eboot/FUN_0011cc1c.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/block_deque.h"

extern void FUN_00000a00();
extern u32 * FUN_001285cc();
extern void FUN_00129790();
extern void FUN_0012a530();

/* Deleting destructor of a block deque: destroy the elements from begin to end, tear down the map, free self when flags > 0. */
BlockDeque * FUN_001281a0(BlockDeque *self,short flags)
{
  BlockDequePos begin;
  BlockDequePos end;

  if (self != 0) {
    FUN_0012a530(&end,self,self->length);
    FUN_0012a530(&begin,self,0);
    FUN_00129790(self,&begin,&end);
    FUN_001285cc(self,0);
    if (0 < flags) {
      FUN_00000a00(self);
    }
  }
  return self;
}
