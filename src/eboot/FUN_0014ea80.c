/* HSTMATCH module=EBOOT.BIN start=0x0014ea80 end=0x0014eadc symbol=FUN_0014ea80 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/script_node.h"

extern u8 DAT_00308260;
extern void FUN_00000a00();
extern u32 * FUN_0014e00c();

/* Deleting destructor of a script node subclass: sets its vtable, runs the base destructor, frees when delete_flag > 0. */
ScriptNode * FUN_0014ea80(ScriptNode *self,short delete_flag)
{
  if (self != (ScriptNode *)0x0) {
    self->vtable = &DAT_00308260;
    FUN_0014e00c(self,0);
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
