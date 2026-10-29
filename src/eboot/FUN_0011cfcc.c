/* HSTMATCH module=EBOOT.BIN start=0x0011cfcc end=0x0011d050 symbol=FUN_0011cfcc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag p1) refined by hstperm.py random mutation (perm-p1/r00/f0305_0011cfcc_m02.c), then readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/block_deque.h"

extern void FUN_00000a00();
extern u32 * FUN_0011d3f8();
extern void FUN_0011e5bc();
extern void FUN_0011f35c();

/* Deleting destructor of a block deque: destroy the elements from begin to end, tear down the map, free self when flags > 0. */
BlockDeque * FUN_0011cfcc(BlockDeque *self,short flags)
{
  BlockDequePos begin;
  BlockDequePos end;

  if (0 != self) {
    FUN_0011f35c(&end,self,self->length);
    FUN_0011f35c(&begin,self,0);
    FUN_0011e5bc(self,&begin,&end);
    FUN_0011d3f8(self,0);
    if (0 < flags) {
      FUN_00000a00(self);
    }
  }
  return self;
}
