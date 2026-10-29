/* HSTMATCH module=EBOOT.BIN start=0x0025a378 end=0x0025a3a8 symbol=FUN_0025a378 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/block_deque.h"

/* Build a deque position from a map cursor plus the element and block end inside its block. */
BlockDequePos * FUN_0025a378(BlockDequePos *out, BlockDequePos *map_pos, char *elem, char *block_end)
{
  out->map_cur = map_pos->map_cur;
  out->map_begin = map_pos->map_begin;
  out->map_head = map_pos->map_head;
  out->map_end = map_pos->map_end;
  out->elem = elem;
  out->block_end = block_end;
  return out;
}
