/* HSTMATCH module=EBOOT.BIN start=0x00159ee0 end=0x00159ef4 symbol=FUN_00159ee0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/stream_cursor.h"

/* Read one signed 16-bit value and advance the cursor past it. */
int FUN_00159ee0(StreamCursor *cursor)
{
  short value;

  value = *(short *)cursor->pos;
  cursor->pos = (const u8 *)((short *)cursor->pos + 1);
  return (int)value;
}
