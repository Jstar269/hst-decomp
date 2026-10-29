/* HSTMATCH module=EBOOT.BIN start=0x001e59f4 end=0x001e5a34 symbol=FUN_001e59f4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed FUN_001e2694 as receiver-only; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/result_scene.h"

extern void FUN_001e2694(ResultScene *);
extern void FUN_00222bb8();

/* Free the owned objects, then pass the part at 0x1954 and the value to the callback with flag 1. */
void FUN_001e59f4(ResultScene *self,u32 arg)
{
  FUN_001e2694(self);
  FUN_00222bb8(self->part1954,arg,1);
}
