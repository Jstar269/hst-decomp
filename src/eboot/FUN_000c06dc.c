/* HSTMATCH module=EBOOT.BIN start=0x000c06dc end=0x000c06f0 symbol=FUN_000c06dc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/ptp_link.h"

/* Number of bytes waiting in the read queue. */
int FUN_000c06dc(PtpLink *self)
{
  return self->read_queue->tail - self->read_queue->head;
}
