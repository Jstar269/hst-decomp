/* HSTMATCH module=hstp_trans_main.prx start=0x0016646c end=0x00166480 symbol=FUN_0016646c lang=c99 */
/* Clone of src/eboot/FUN_00159ef4.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/stream_cursor.h"

/* Read one byte and advance the cursor past it. */
u8 FUN_0016646c(StreamCursor *cursor)
{
  u8 value;

  value = *cursor->pos;
  cursor->pos = cursor->pos + 1;
  return value;
}
