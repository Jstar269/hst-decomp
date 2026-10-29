/* HSTMATCH module=EBOOT.BIN start=0x0011d5ac end=0x0011d5fc symbol=FUN_0011d5ac lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/block_deque.h"

/* Swap two block maps word by word. */
void FUN_0011d5ac(BlockMap *a, BlockMap *b)
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
