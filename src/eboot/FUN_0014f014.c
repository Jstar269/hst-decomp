/* HSTMATCH module=EBOOT.BIN start=0x0014f014 end=0x0014f028 symbol=FUN_0014f014 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/stream_cursor.h"

/* Read one float from the stream and advance the cursor. */
float FUN_0014f014(StreamCursor *stream)
{
  float value;

  value = *(const float *)stream->pos;
  stream->pos = (const u8 *)((const float *)stream->pos + 1);
  return value;
}
