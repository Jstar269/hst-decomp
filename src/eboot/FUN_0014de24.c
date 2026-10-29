/* HSTMATCH module=EBOOT.BIN start=0x0014de24 end=0x0014de6c symbol=FUN_0014de24 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/script_node.h"
#include "hst/stream_cursor.h"

extern u8 DAT_003082f4;
extern u8 DAT_0030840c;
extern u16 FUN_0014f050();

/* Node whose 16-bit payload is read from the stream and discarded. */
ScriptNode * FUN_0014de24(ScriptNode *self,StreamCursor *stream)
{
  self->vtable = &DAT_0030840c;
  self->unk04 = 0;
  self->vtable = &DAT_003082f4;
  FUN_0014f050(stream);
  return self;
}
