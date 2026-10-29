/* HSTMATCH module=EBOOT.BIN start=0x0014e650 end=0x0014e698 symbol=FUN_0014e650 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/script_node.h"
#include "hst/stream_cursor.h"

extern u8 DAT_0030829c;
extern u8 DAT_0030840c;
extern u16 FUN_0014f050();

/* Constructor of a script node read from a stream: base vtable, cleared byte, then own vtable. */
ScriptNode * FUN_0014e650(ScriptNode *self,StreamCursor *stream)
{
  self->vtable = &DAT_0030840c;
  self->unk04 = 0;
  self->vtable = &DAT_0030829c;
  FUN_0014f050(stream);
  return self;
}
