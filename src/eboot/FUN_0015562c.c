/* HSTMATCH module=EBOOT.BIN start=0x0015562c end=0x00155688 symbol=FUN_0015562c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/cmd_base.h"

extern u8 DAT_0030840c;
extern u8 DAT_0030865c;
extern void FUN_00000a00();

/* Deleting destructor of a script command: steps the vtable back to the parent class, frees the object when delete_flag is positive. */
CmdBase * FUN_0015562c(CmdBase *self,short delete_flag)
{
  if (self != (CmdBase *)0x0) {
    self->vtable = &DAT_0030865c;
    if (self != (CmdBase *)0x0) {
      self->vtable = &DAT_0030840c;
    }
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
