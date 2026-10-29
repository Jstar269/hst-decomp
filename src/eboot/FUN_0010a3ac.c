/* HSTMATCH module=EBOOT.BIN start=0x0010a3ac end=0x0010a408 symbol=FUN_0010a3ac lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
extern u8 DAT_00307bcc;
extern void FUN_00000a00();
extern u32 * FUN_000510c0();

/* Deleting destructor: reset the vtable, run the base destructor, free the object when deleteFlag is positive. */
u32 * FUN_0010a3ac(u32 *self,short deleteFlag)
{
  if (self != (u32 *)0x0) {
    *self = (unsigned int)(&DAT_00307bcc);
    FUN_000510c0(self,0);
    if (0 < deleteFlag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
