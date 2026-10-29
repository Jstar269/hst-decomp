/* HSTMATCH module=hstp_trans_main.prx start=0x0019cb58 end=0x0019cb78 symbol=FUN_0019cb58 lang=c99 */
/* Clone of src/eboot/FUN_00190348.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/block_deque.h"

/* Default constructor: a position that points nowhere. */
BlockDequePos * FUN_0019cb58(BlockDequePos *self)
{
  self->map_cur = 0;
  self->map_begin = 0;
  self->map_head = 0;
  self->map_end = 0;
  self->elem = 0;
  self->block_end = 0;
  return self;
}
