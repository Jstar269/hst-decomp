/* HSTMATCH module=hstp_trans_main.prx start=0x0026a8c0 end=0x0026a904 symbol=FUN_0026a8c0 lang=c99 */
/* Clone of src/eboot/FUN_00118c5c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/deque_owner.h"

/* begin(): iterator pointing at the first element of the circular deque. */
void FUN_0026a8c0(CdequeIter *out,Cdeque *deq)
{
  int *block;
  
  out->ptr = deq->data + deq->start;
  block = deq->data;
  out->beg = block;
  out->first = block + deq->start;
  out->end = out->beg + deq->cap;
}
