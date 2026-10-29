/* HSTMATCH module=hstp_trans_main.prx start=0x0019edb0 end=0x0019ee00 symbol=FUN_0019edb0 lang=c99 */
/* Clone of src/eboot/FUN_0011d520.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/block_deque.h"

/* Swap two block maps word by word. */
void FUN_0019edb0(BlockMap *a, BlockMap *b)
{
  int tmp;
  void **blocks;
  
  if (a != b) {
    tmp = a->capacity;
    a->capacity = b->capacity;
    b->capacity = tmp;
    tmp = a->count;
    a->count = b->count;
    b->count = tmp;
    tmp = a->head;
    a->head = b->head;
    b->head = tmp;
    blocks = a->blocks;
    a->blocks = b->blocks;
    b->blocks = blocks;
  }
}
