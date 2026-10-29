/* HSTMATCH module=EBOOT.BIN start=0x00190400 end=0x00190458 symbol=FUN_00190400 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/block_deque.h"

extern void FUN_00000a00();
extern BlockMap * FUN_001908f8();

/* Deleting destructor of the block map: runs the destructor, frees the object when delete_flag > 0. */
BlockMap * FUN_00190400(BlockMap *self,short delete_flag)
{
  if (self != 0) {
    if (self != 0) {
      FUN_001908f8(self,0);
    }
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
