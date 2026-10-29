/* HSTMATCH module=hstp_trans_main.prx start=0x0015b000 end=0x0015b014 symbol=FUN_0015b000 lang=c99 */
/* Clone of src/eboot/FUN_0014f000.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/stream_cursor.h"

/* Read one signed byte from the stream and advance the cursor. */
int FUN_0015b000(StreamCursor *stream)
{
  char value;

  value = *(const char *)stream->pos;
  stream->pos = stream->pos + 1;
  return (int)value;
}
