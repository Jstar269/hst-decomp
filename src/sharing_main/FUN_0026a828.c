/* HSTMATCH module=hstp_trans_main.prx start=0x0026a828 end=0x0026a858 symbol=FUN_0026a828 lang=c99 */
/* Clone of src/eboot/FUN_00190ed0.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/block_deque.h"

/* Builds a position from a map cursor plus the element and block end inside the current block. */
BlockDequePos * FUN_0026a828(BlockDequePos *self,BlockDequePos *map_pos,char *elem,char *block_end)
{
  self->map_cur = map_pos->map_cur;
  self->map_begin = map_pos->map_begin;
  self->map_head = map_pos->map_head;
  self->map_end = map_pos->map_end;
  self->elem = elem;
  self->block_end = block_end;
  return self;
}
