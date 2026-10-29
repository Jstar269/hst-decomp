/* HSTMATCH module=EBOOT.BIN start=0x0025ab10 end=0x0025ab40 symbol=FUN_0025ab10 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/block_deque.h"

/* Drop the first used slot of a circular block map: one fewer in use, head moves on and wraps at the capacity. */
void FUN_0025ab10(BlockMap *map)
{
  int head;

  map->count = map->count + -1;
  head = map->head;
  map->head = head + 1;
  if (head + 1 == map->capacity) {
    map->head = 0;
  }
}
