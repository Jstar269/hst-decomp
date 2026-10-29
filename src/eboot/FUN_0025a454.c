/* HSTMATCH module=EBOOT.BIN start=0x0025a454 end=0x0025a4b8 symbol=FUN_0025a454 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/block_deque.h"

extern void FUN_00000a00();
extern void FUN_0025aa90();

/* Deleting destructor of a block map: tear down the blocks, free the block array, free self when flags > 0. */
BlockMap * FUN_0025a454(BlockMap *self,short flags)
{
  if (self != 0) {
    if (self->blocks != 0) {
      FUN_0025aa90();
      FUN_00000a00(self->blocks);
    }
    if (0 < flags) {
      FUN_00000a00(self);
    }
  }
  return self;
}
