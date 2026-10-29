/* HSTMATCH module=EBOOT.BIN start=0x0011cc1c end=0x0011cca0 symbol=FUN_0011cc1c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag p1) refined by hstperm.py random mutation (perm-p1/r00/f0304_0011cc1c_m03.c), then readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/block_deque.h"

extern void FUN_00000a00();
extern u32 * FUN_0011d190();
extern void FUN_0011e3e8();
extern void FUN_0011ed04();

/* Deleting destructor of a block deque: destroy the elements from begin to end, tear down the map, free self when flags > 0. */
BlockDeque * FUN_0011cc1c(BlockDeque *self,short flags)
{
  BlockDequePos begin;
  BlockDequePos end;

  if (self != 0) {
    FUN_0011ed04(&end,self,self->length);
    FUN_0011ed04(&begin,self,0);
    FUN_0011e3e8(self,&begin,&end);
    FUN_0011d190(self,0);
    if (0 < flags) {
      FUN_00000a00(self);
    }
  }
  return self;
}
