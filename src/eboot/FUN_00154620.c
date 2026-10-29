/* HSTMATCH module=EBOOT.BIN start=0x00154620 end=0x0015467c symbol=FUN_00154620 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/cmd_base.h"

extern unsigned char DAT_003083cc; /* base class vtable */
extern unsigned char DAT_003088a4; /* derived class vtable */
extern void FUN_00000a00(void *);

/* Deleting destructor of a script command: restore the base vtable and free the object when flags > 0. */
CmdBase * FUN_00154620(CmdBase *self,short flags)
{
  if (self != (CmdBase *)0x0) {
    self->vtable = &DAT_003088a4;
    if (self != (CmdBase *)0x0) {
      self->vtable = &DAT_003083cc;
    }
    if (0 < flags) {
      FUN_00000a00(self);
    }
  }
  return self;
}
