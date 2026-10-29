/* HSTMATCH module=EBOOT.BIN start=0x0025b160 end=0x0025b1a4 symbol=FUN_0025b160 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/deque_owner.h"

/* begin() of a circular deque: iterator at the first element, spanning the whole block. */
void FUN_0025b160(CdequeIter *out,Cdeque *deque)
{
  int *data;
  
  out->ptr = deque->data + deque->start;
  data = deque->data;
  out->beg = data;
  out->first = data + deque->start;
  out->end = out->beg + deque->cap;
}
