/* HSTMATCH module=EBOOT.BIN start=0x0018a68c end=0x0018a6e8 symbol=FUN_0018a68c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0030913c;
extern void FUN_00000a00();
extern u32 * FUN_00102ea4();

/* Deleting destructor: set the vtable, run the base destructor, free the object when flags > 0. */
u32 * FUN_0018a68c(u32 *self,short flags)
{
  if (self != (u32 *)0x0) {
    *self = (unsigned int)(&DAT_0030913c); /* vtable */
    FUN_00102ea4(self,0);
    if (0 < flags) {
      FUN_00000a00(self);
    }
  }
  return self;
}
