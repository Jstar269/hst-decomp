/* HSTMATCH module=EBOOT.BIN start=0x0014f000 end=0x0014f014 symbol=FUN_0014f000 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/stream_cursor.h"

/* Read one signed byte from the stream and advance the cursor. */
int FUN_0014f000(StreamCursor *stream)
{
  char value;

  value = *(const char *)stream->pos;
  stream->pos = stream->pos + 1;
  return (int)value;
}
