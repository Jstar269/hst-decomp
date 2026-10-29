/* HSTMATCH module=hstp_trans_main.prx start=0x00123e30 end=0x00123e74 symbol=FUN_00123e30 lang=c99 */
/* Clone of src/eboot/FUN_00118c5c.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/deque_owner.h"

/* begin(): iterator pointing at the first element of the circular deque. */
void FUN_00123e30(CdequeIter *out,Cdeque *deq)
{
  int *block;
  
  out->ptr = deq->data + deq->start;
  block = deq->data;
  out->beg = block;
  out->first = block + deq->start;
  out->end = out->beg + deq->cap;
}
