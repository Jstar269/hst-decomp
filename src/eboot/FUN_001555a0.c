/* HSTMATCH module=EBOOT.BIN start=0x001555a0 end=0x001555fc symbol=FUN_001555a0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/cmd_base.h"

extern u8 DAT_003083cc;
extern u8 DAT_00308694;
extern void FUN_00000a00();

/* Deleting destructor of a script command: steps the vtable back to the parent class, frees the object when delete_flag is positive. */
CmdBase * FUN_001555a0(CmdBase *self,short delete_flag)
{
  if (self != (CmdBase *)0x0) {
    self->vtable = &DAT_00308694;
    if (self != (CmdBase *)0x0) {
      self->vtable = &DAT_003083cc;
    }
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
