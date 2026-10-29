/* HSTMATCH module=EBOOT.BIN start=0x000c02d8 end=0x000c0308 symbol=FUN_000c02d8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/ptp_link.h"

extern const void *DAT_003073fc;

/* Constructor: no thread or semaphore yet, no shared cells or queues. */
PtpLink * FUN_000c02d8(PtpLink *self)
{
  self->vtable = &DAT_003073fc;
  self->sema_id = -1;
  self->thread_id = -1;
  self->shared_short = 0;
  self->stop_flag = 0;
  self->write_queue = 0;
  self->read_queue = 0;
  return self;
}
