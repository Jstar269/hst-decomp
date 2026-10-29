/* HSTMATCH module=EBOOT.BIN start=0x00155ed8 end=0x00155f34 symbol=FUN_00155ed8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/cmd_base.h"

extern u8 DAT_00308508;
extern void FUN_00000a00();
extern u32 * FUN_0014c40c();

/* Deleting destructor: sets this class's vtable, runs the base destructor, frees when delete_flag is positive. */
CmdBase * FUN_00155ed8(CmdBase *self,short delete_flag)
{
  if (self != (CmdBase *)0x0) {
    self->vtable = &DAT_00308508;
    FUN_0014c40c(self,0);
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
