/* HSTMATCH module=hstp_trans_main.prx start=0x000c3978 end=0x000c39a8 symbol=FUN_000c3978 lang=c99 */
/* Clone of src/eboot/FUN_000c02d8.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/ptp_link.h"

extern const void *DAT_003b06c8;

/* Constructor: no thread or semaphore yet, no shared cells or queues. */
PtpLink * FUN_000c3978(PtpLink *self)
{
  self->vtable = &DAT_003b06c8;
  self->sema_id = -1;
  self->thread_id = -1;
  self->shared_short = 0;
  self->stop_flag = 0;
  self->write_queue = 0;
  self->read_queue = 0;
  return self;
}
