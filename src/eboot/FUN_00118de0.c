/* HSTMATCH module=EBOOT.BIN start=0x00118de0 end=0x00118e20 symbol=FUN_00118de0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag p64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern int * FUN_00118e20();
extern u32 FUN_00118f54();

/* Copy-constructs the container from another (the allocator argument is unused). */
u32 FUN_00118de0(u32 self,u32 allocator,u32 other)
{
  FUN_00118f54(self);
  FUN_00118e20(self,other);
  return self;
}
