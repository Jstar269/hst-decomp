/* HSTMATCH module=hstp_trans_main.prx start=0x0015b050 end=0x0015b064 symbol=FUN_0015b050 lang=c99 */
/* Clone of src/eboot/FUN_0014f050.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/stream_cursor.h"

/* Read one 16-bit value from the stream and advance the cursor. */
u16 FUN_0015b050(StreamCursor *stream)
{
  u16 value;

  value = *(const u16 *)stream->pos;
  stream->pos = (const u8 *)((const u16 *)stream->pos + 1);
  return value;
}
