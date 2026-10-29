/* HSTMATCH module=EBOOT.BIN start=0x00153500 end=0x0015355c symbol=FUN_00153500 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003083cc;
extern u8 DAT_00308a8c;
extern void FUN_00000a00();

/* Deleting destructor of a script command: restore the base vtable, free the object when flags > 0. */
u32 * FUN_00153500(u32 *self,short flags)
{
  if (self != (u32 *)0x0) {
    *self = (unsigned int)(&DAT_00308a8c); /* vtable of the derived command */
    if (self != (u32 *)0x0) {
      *self = (unsigned int)(&DAT_003083cc); /* vtable of the command base class */
    }
    if (0 < flags) {
      FUN_00000a00(self);
    }
  }
  return self;
}
