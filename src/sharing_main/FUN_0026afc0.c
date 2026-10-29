/* HSTMATCH module=hstp_trans_main.prx start=0x0026afc0 end=0x0026aff0 symbol=FUN_0026afc0 lang=c99 */
/* Clone of src/eboot/FUN_0011d864.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/block_deque.h"

/* Drop the first element of a circular map: one fewer in use, head advances and wraps at capacity. */
void FUN_0026afc0(BlockMap *map)
{
  map->count--;
  if (++map->head == map->capacity) {
    map->head = 0;
  }
}
