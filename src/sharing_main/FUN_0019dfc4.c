/* HSTMATCH module=hstp_trans_main.prx start=0x0019dfc4 end=0x0019e008 symbol=FUN_0019dfc4 lang=c99 */
/* Clone of src/eboot/FUN_00118c5c.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/deque_owner.h"

/* begin(): iterator pointing at the first element of the circular deque. */
void FUN_0019dfc4(CdequeIter *out,Cdeque *deq)
{
  int *block;
  
  out->ptr = deq->data + deq->start;
  block = deq->data;
  out->beg = block;
  out->first = block + deq->start;
  out->end = out->beg + deq->cap;
}
