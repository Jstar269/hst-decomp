/* HSTMATCH module=EBOOT.BIN start=0x0014eb50 end=0x0014ebac symbol=FUN_0014eb50 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/script_node.h"

extern u8 DAT_0030829c;
extern u8 DAT_0030840c;
extern void FUN_00000a00();

/* Deleting destructor of a script node: derived vtable, then the base vtable; frees the node when delete_flag > 0. */
ScriptNode * FUN_0014eb50(ScriptNode *self,short delete_flag)
{
  if (self != (ScriptNode *)0x0) {
    self->vtable = &DAT_0030829c;
    if (self != (ScriptNode *)0x0) {
      self->vtable = &DAT_0030840c;
    }
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
