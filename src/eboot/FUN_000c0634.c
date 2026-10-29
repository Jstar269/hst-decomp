/* HSTMATCH module=EBOOT.BIN start=0x000c0634 end=0x000c067c symbol=FUN_000c0634 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/ptp_link.h"

extern void FUN_000ff5b0(PtpQueue *queue, int data, int length, int tail);

/* Appends length bytes to the write queue if they still fit; returns 1 on success. */
int FUN_000c0634(PtpLink *self, int data, int length)
{
  PtpQueue *queue = self->write_queue;
  int ok = 0;

  if ((unsigned)(length + (queue->tail - queue->head)) <= PTP_QUEUE_CAPACITY) {
    FUN_000ff5b0(queue, data, length, queue->tail);
    ok = 1;
  }
  return ok;
}
