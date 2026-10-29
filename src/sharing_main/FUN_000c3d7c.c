/* HSTMATCH module=hstp_trans_main.prx start=0x000c3d7c end=0x000c3d90 symbol=FUN_000c3d7c lang=c99 */
/* Clone of src/eboot/FUN_000c06dc.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/ptp_link.h"

/* Number of bytes waiting in the read queue. */
int FUN_000c3d7c(PtpLink *self)
{
  return self->read_queue->tail - self->read_queue->head;
}
