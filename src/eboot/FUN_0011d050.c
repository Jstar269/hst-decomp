/* HSTMATCH module=EBOOT.BIN start=0x0011d050 end=0x0011d0ac symbol=FUN_0011d050 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/block_deque.h"

extern void FUN_0011d520(BlockMap *, BlockMap *);

/* Swap two block deques: the map, then the first-element index and the length. */
void FUN_0011d050(BlockDeque *a, BlockDeque *b)
{
  int tmp;
  
  if (a != b) {
    FUN_0011d520(&a->map, &b->map);
    tmp = a->first;
    a->first = b->first;
    b->first = tmp;
    tmp = a->length;
    a->length = b->length;
    b->length = tmp;
  }
}
