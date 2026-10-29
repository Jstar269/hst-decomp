/* HSTMATCH module=hstp_trans_main.prx start=0x0026a770 end=0x0026a79c symbol=FUN_0026a770 lang=c99 */
/* Clone of src/eboot/FUN_0025a2c0.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/block_deque.h"

/* Advance a map cursor by one slot, wrapping to the start of the map at its end. */
BlockDequePos * FUN_0026a770(BlockDequePos *pos)
{
  void **next;

  next = pos->map_cur + 1;
  pos->map_cur = next;
  if (next == pos->map_end) {
    pos->map_cur = pos->map_begin;
  }
  return pos;
}
