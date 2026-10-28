/* HSTMATCH module=EBOOT.BIN start=0x00159ef4 end=0x00159f08 symbol=FUN_00159ef4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/stream_cursor.h"

/* Read one byte and advance the cursor past it. */
u8 FUN_00159ef4(StreamCursor *cursor)
{
  u8 value;

  value = *cursor->pos;
  cursor->pos = cursor->pos + 1;
  return value;
}
