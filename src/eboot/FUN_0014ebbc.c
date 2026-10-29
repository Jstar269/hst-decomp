/* HSTMATCH module=EBOOT.BIN start=0x0014ebbc end=0x0014ec18 symbol=FUN_0014ebbc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/script_node.h"

extern u8 DAT_003082b8;
extern u8 DAT_00308460;
extern void FUN_00000a00();

/* Deleting destructor of a script node: derived vtable, then the base vtable; frees the node when delete_flag > 0. */
ScriptNode * FUN_0014ebbc(ScriptNode *self,short delete_flag)
{
  if (self != (ScriptNode *)0x0) {
    self->vtable = &DAT_003082b8;
    if (self != (ScriptNode *)0x0) {
      self->vtable = &DAT_00308460;
    }
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
