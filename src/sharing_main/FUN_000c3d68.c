/* HSTMATCH module=hstp_trans_main.prx start=0x000c3d68 end=0x000c3d7c symbol=FUN_000c3d68 lang=c99 */
/* Clone of src/eboot/FUN_000c06c8.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/ptp_link.h"

/* Number of bytes waiting in the write queue. */
int FUN_000c3d68(PtpLink *self)
{
  return self->write_queue->tail - self->write_queue->head;
}
