/* HSTMATCH module=EBOOT.BIN start=0x001539bc end=0x00153a18 symbol=FUN_001539bc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003083cc;
extern u8 DAT_003089ec;
extern void FUN_00000a00();

/* Deleting destructor of a script command: restore the base vtable, free the object when flags > 0. */
u32 * FUN_001539bc(u32 *self,short flags)
{
  if (self != (u32 *)0x0) {
    *self = (unsigned int)(&DAT_003089ec); /* vtable of the derived command */
    if (self != (u32 *)0x0) {
      *self = (unsigned int)(&DAT_003083cc); /* vtable of the command base class */
    }
    if (0 < flags) {
      FUN_00000a00(self);
    }
  }
  return self;
}
