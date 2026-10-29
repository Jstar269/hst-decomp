/* HSTMATCH module=EBOOT.BIN start=0x001621e0 end=0x00162200 symbol=FUN_001621e0 lang=c99 */
/* Clone of src/eboot/FUN_00190348.c (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/block_deque.h"

/* Default constructor: a position that points nowhere. */
BlockDequePos * FUN_001621e0(BlockDequePos *self)
{
  self->map_cur = 0;
  self->map_begin = 0;
  self->map_head = 0;
  self->map_end = 0;
  self->elem = 0;
  self->block_end = 0;
  return self;
}
