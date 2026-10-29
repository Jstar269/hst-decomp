/* HSTMATCH module=EBOOT.BIN start=0x0025be98 end=0x0025bee8 symbol=FUN_0025be98 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/deque_owner.h"

/* Swap two circular-deque iterators field by field (no-op when they are the same object). */
void FUN_0025be98(CdequeIter *a,CdequeIter *b)
{
  int *tmp;
  
  if (a != b) {
    tmp = a->ptr;
    a->ptr = b->ptr;
    b->ptr = tmp;
    tmp = a->beg;
    a->beg = b->beg;
    b->beg = tmp;
    tmp = a->first;
    a->first = b->first;
    b->first = tmp;
    tmp = a->end;
    a->end = b->end;
    b->end = tmp;
  }
}
