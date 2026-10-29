/* HSTMATCH module=EBOOT.BIN start=0x00118b4c end=0x00118b8c symbol=FUN_00118b4c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag p64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern int * FUN_00118b8c();
extern u32 FUN_00118cc0();

/* Copy-constructs the container from another (the allocator argument is unused). */
u32 FUN_00118b4c(u32 self,u32 allocator,u32 other)
{
  FUN_00118cc0(self);
  FUN_00118b8c(self,other);
  return self;
}
