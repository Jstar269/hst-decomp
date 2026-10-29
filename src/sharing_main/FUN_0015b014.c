/* HSTMATCH module=hstp_trans_main.prx start=0x0015b014 end=0x0015b028 symbol=FUN_0015b014 lang=c99 */
/* Clone of src/eboot/FUN_0014f014.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/stream_cursor.h"

/* Read one float from the stream and advance the cursor. */
float FUN_0015b014(StreamCursor *stream)
{
  float value;

  value = *(const float *)stream->pos;
  stream->pos = (const u8 *)((const float *)stream->pos + 1);
  return value;
}
