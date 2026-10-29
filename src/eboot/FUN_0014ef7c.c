/* HSTMATCH module=EBOOT.BIN start=0x0014ef7c end=0x0014efd8 symbol=FUN_0014ef7c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/script_node.h"

extern u8 DAT_003083f0;
extern u8 DAT_00308460;
extern void FUN_00000a00();

/* Deleting destructor of a script node: derived vtable, then the base vtable; frees the node when delete_flag > 0. */
ScriptNode * FUN_0014ef7c(ScriptNode *self,short delete_flag)
{
  if (self != (ScriptNode *)0x0) {
    self->vtable = &DAT_003083f0;
    if (self != (ScriptNode *)0x0) {
      self->vtable = &DAT_00308460;
    }
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
