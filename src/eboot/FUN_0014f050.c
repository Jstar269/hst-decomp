/* HSTMATCH module=EBOOT.BIN start=0x0014f050 end=0x0014f064 symbol=FUN_0014f050 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/stream_cursor.h"

/* Read one 16-bit value from the stream and advance the cursor. */
u16 FUN_0014f050(StreamCursor *stream)
{
  u16 value;

  value = *(const u16 *)stream->pos;
  stream->pos = (const u8 *)((const u16 *)stream->pos + 1);
  return value;
}
