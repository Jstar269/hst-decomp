/* HSTMATCH module=hstp_trans_main.prx start=0x0015b03c end=0x0015b050 symbol=FUN_0015b03c lang=c99 */
/* Clone of src/eboot/FUN_0014f028.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/stream_cursor.h"

/* Read one 32-bit word from the stream and advance the cursor. */
u32 FUN_0015b03c(StreamCursor *stream)
{
  u32 value;

  value = *(const u32 *)stream->pos;
  stream->pos = (const u8 *)((const u32 *)stream->pos + 1);
  return value;
}
