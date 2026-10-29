/* HSTMATCH module=hstp_trans_main.prx start=0x0019d108 end=0x0019d16c symbol=FUN_0019d108 lang=c99 */
/* Clone of src/eboot/FUN_0011c828.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/block_deque.h"

extern void FUN_00000a00();
extern void FUN_0019d760();

/* Deleting destructor of a block map: tear down the blocks, free the block array, free self when flags > 0. */
BlockMap * FUN_0019d108(BlockMap *self,short flags)
{
  if (self != 0) {
    if (self->blocks != 0) {
      FUN_0019d760();
      FUN_00000a00(self->blocks);
    }
    if (0 < flags) {
      FUN_00000a00(self);
    }
  }
  return self;
}
