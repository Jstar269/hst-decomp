/* HSTMATCH module=EBOOT.BIN start=0x0011d864 end=0x0011d894 symbol=FUN_0011d864 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/block_deque.h"

/* Drop the first element of a circular map: one fewer in use, head advances and wraps at capacity. */
void FUN_0011d864(BlockMap *map)
{
  map->count--;
  if (++map->head == map->capacity) {
    map->head = 0;
  }
}
