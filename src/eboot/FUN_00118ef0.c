/* HSTMATCH module=EBOOT.BIN start=0x00118ef0 end=0x00118f34 symbol=FUN_00118ef0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/deque_owner.h"

/* begin(): iterator pointing at the first element of the circular deque. */
void FUN_00118ef0(CdequeIter *out,Cdeque *deq)
{
  int *block;
  
  out->ptr = deq->data + deq->start;
  block = deq->data;
  out->beg = block;
  out->first = block + deq->start;
  out->end = out->beg + deq->cap;
}
