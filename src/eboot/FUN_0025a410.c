/* HSTMATCH module=EBOOT.BIN start=0x0025a410 end=0x0025a454 symbol=FUN_0025a410 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/block_deque.h"

/* Build a cursor on the first used slot of a block map. */
void FUN_0025a410(BlockDequePos *out, BlockMap *map)
{
  void **blocks;

  out->map_cur = map->blocks + map->head;
  blocks = map->blocks;
  out->map_begin = blocks;
  out->map_head = blocks + map->head;
  out->map_end = out->map_begin + map->capacity;
}
