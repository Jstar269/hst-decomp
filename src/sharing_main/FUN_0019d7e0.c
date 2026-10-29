/* HSTMATCH module=hstp_trans_main.prx start=0x0019d7e0 end=0x0019d810 symbol=FUN_0019d7e0 lang=c99 */
/* Clone of src/eboot/FUN_0011d864.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/block_deque.h"

/* Drop the first element of a circular map: one fewer in use, head advances and wraps at capacity. */
void FUN_0019d7e0(BlockMap *map)
{
  map->count--;
  if (++map->head == map->capacity) {
    map->head = 0;
  }
}
