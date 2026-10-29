/* HSTMATCH module=EBOOT.BIN start=0x001908f8 end=0x0019095c symbol=FUN_001908f8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/block_deque.h"

extern void FUN_00000a00();
extern void FUN_00190f50();

/* Destructor of the block map: clears and frees the block array, then frees the object when delete_flag > 0. */
BlockMap * FUN_001908f8(BlockMap *self,short delete_flag)
{
  if (self != 0) {
    if (self->blocks != 0) {
      FUN_00190f50();
      FUN_00000a00(self->blocks);
    }
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
