/* HSTMATCH module=hstp_trans_main.prx start=0x0015a5e0 end=0x0015a628 symbol=FUN_0015a5e0 lang=c99 */
/* Clone of src/eboot/FUN_0014de24.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/script_node.h"
#include "hst/stream_cursor.h"

extern u8 DAT_003b1568;
extern u8 DAT_003b16d8;
extern u16 FUN_0015b050();

/* Node whose 16-bit payload is read from the stream and discarded. */
ScriptNode * FUN_0015a5e0(ScriptNode *self,StreamCursor *stream)
{
  self->vtable = &DAT_003b16d8;
  self->unk04 = 0;
  self->vtable = &DAT_003b1568;
  FUN_0015b050(stream);
  return self;
}
