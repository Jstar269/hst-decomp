/* HSTMATCH module=hstp_trans_main.prx start=0x00166458 end=0x0016646c symbol=FUN_00166458 lang=c99 */
/* Clone of src/eboot/FUN_00159ee0.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/stream_cursor.h"

/* Read one signed 16-bit value and advance the cursor past it. */
int FUN_00166458(StreamCursor *cursor)
{
  short value;

  value = *(short *)cursor->pos;
  cursor->pos = (const u8 *)((short *)cursor->pos + 1);
  return (int)value;
}
