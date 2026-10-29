/* HSTMATCH module=EBOOT.BIN start=0x00190b1c end=0x00190ba0 symbol=FUN_00190b1c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag p1) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/block_deque.h"

extern void FUN_00000a00();
extern u32 * FUN_00190ba0();
extern void FUN_00191000();
extern void FUN_00191840();

/* Deque destructor: destroys every element (first position to end position), then the block map; frees the object when delete_flag > 0. */
BlockDeque * FUN_00190b1c(BlockDeque *self,short delete_flag)
{
  u8 begin_pos [24];
  u8 end_pos [24];
  
  if (0 != self) {
    FUN_00191840(end_pos,self,self->length);
    FUN_00191840(begin_pos,self,0);
    FUN_00191000(self,begin_pos,end_pos);
    FUN_00190ba0(self,0);
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
