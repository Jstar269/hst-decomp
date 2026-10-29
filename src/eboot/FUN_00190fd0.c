/* HSTMATCH module=EBOOT.BIN start=0x00190fd0 end=0x00191000 symbol=FUN_00190fd0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/block_deque.h"

/* Removes the first slot of the circular map: one fewer in use, head advances and wraps at capacity. */
void FUN_00190fd0(BlockMap *map)
{
  int next;
  
  map->count--;
  next = map->head;
  map->head = next + 1;
  if (next + 1 == map->capacity) {
    map->head = 0;
  }
}
