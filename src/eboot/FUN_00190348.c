/* HSTMATCH module=EBOOT.BIN start=0x00190348 end=0x00190368 symbol=FUN_00190348 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/block_deque.h"

/* Default constructor: a position that points nowhere. */
BlockDequePos * FUN_00190348(BlockDequePos *self)
{
  self->map_cur = 0;
  self->map_begin = 0;
  self->map_head = 0;
  self->map_end = 0;
  self->elem = 0;
  self->block_end = 0;
  return self;
}
