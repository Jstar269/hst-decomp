/* HSTMATCH module=EBOOT.BIN start=0x0014eaec end=0x0014eb48 symbol=FUN_0014eaec lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/script_node.h"

extern u8 DAT_00308280;
extern u8 DAT_0030840c;
extern void FUN_00000a00();

/* Deleting destructor of a script node: derived vtable, then the base vtable; frees the node when delete_flag > 0. */
ScriptNode * FUN_0014eaec(ScriptNode *self,short delete_flag)
{
  if (self != (ScriptNode *)0x0) {
    self->vtable = &DAT_00308280;
    if (self != (ScriptNode *)0x0) {
      self->vtable = &DAT_0030840c;
    }
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
