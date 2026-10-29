/* HSTMATCH module=hstp_trans_main.prx start=0x00128224 end=0x00128280 symbol=FUN_00128224 lang=c99 */
/* Clone of src/eboot/FUN_0011d050.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/block_deque.h"

extern void FUN_001286f4(BlockMap *, BlockMap *);

/* Swap two block deques: the map, then the first-element index and the length. */
void FUN_00128224(BlockDeque *a, BlockDeque *b)
{
  int tmp;
  
  if (a != b) {
    FUN_001286f4(&a->map, &b->map);
    tmp = a->first;
    a->first = b->first;
    b->first = tmp;
    tmp = a->length;
    a->length = b->length;
    b->length = tmp;
  }
}
