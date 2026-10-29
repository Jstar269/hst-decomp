/* HSTMATCH module=EBOOT.BIN start=0x0014f028 end=0x0014f03c symbol=FUN_0014f028 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/stream_cursor.h"

/* Read one 32-bit word from the stream and advance the cursor. */
u32 FUN_0014f028(StreamCursor *stream)
{
  u32 value;

  value = *(const u32 *)stream->pos;
  stream->pos = (const u8 *)((const u32 *)stream->pos + 1);
  return value;
}
