/* HSTMATCH module=hstp_trans_main.prx start=0x00127df0 end=0x00127e74 symbol=FUN_00127df0 lang=c99 */
/* Clone of src/eboot/FUN_0011cc1c.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/block_deque.h"

extern void FUN_00000a00();
extern u32 * FUN_00128364();
extern void FUN_001295bc();
extern void FUN_00129ed8();

/* Deleting destructor of a block deque: destroy the elements from begin to end, tear down the map, free self when flags > 0. */
BlockDeque * FUN_00127df0(BlockDeque *self,short flags)
{
  BlockDequePos begin;
  BlockDequePos end;

  if (self != 0) {
    FUN_00129ed8(&end,self,self->length);
    FUN_00129ed8(&begin,self,0);
    FUN_001295bc(self,&begin,&end);
    FUN_00128364(self,0);
    if (0 < flags) {
      FUN_00000a00(self);
    }
  }
  return self;
}
