/* HSTMATCH module=EBOOT.BIN start=0x0025a2c0 end=0x0025a2ec symbol=FUN_0025a2c0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/block_deque.h"

/* Advance a map cursor by one slot, wrapping to the start of the map at its end. */
BlockDequePos * FUN_0025a2c0(BlockDequePos *pos)
{
  void **next;

  next = pos->map_cur + 1;
  pos->map_cur = next;
  if (next == pos->map_end) {
    pos->map_cur = pos->map_begin;
  }
  return pos;
}
