/* HSTMATCH module=hstp_trans_main.prx start=0x0019d6e0 end=0x0019d710 symbol=FUN_0019d6e0 lang=c99 */
/* Clone of src/eboot/FUN_00190ed0.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/block_deque.h"

/* Builds a position from a map cursor plus the element and block end inside the current block. */
BlockDequePos * FUN_0019d6e0(BlockDequePos *self,BlockDequePos *map_pos,char *elem,char *block_end)
{
  self->map_cur = map_pos->map_cur;
  self->map_begin = map_pos->map_begin;
  self->map_head = map_pos->map_head;
  self->map_end = map_pos->map_end;
  self->elem = elem;
  self->block_end = block_end;
  return self;
}
