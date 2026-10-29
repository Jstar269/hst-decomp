/* HSTMATCH module=EBOOT.BIN start=0x00190ed0 end=0x00190f00 symbol=FUN_00190ed0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/block_deque.h"

/* Builds a position from a map cursor plus the element and block end inside the current block. */
BlockDequePos * FUN_00190ed0(BlockDequePos *self,BlockDequePos *map_pos,char *elem,char *block_end)
{
  self->map_cur = map_pos->map_cur;
  self->map_begin = map_pos->map_begin;
  self->map_head = map_pos->map_head;
  self->map_end = map_pos->map_end;
  self->elem = elem;
  self->block_end = block_end;
  return self;
}
