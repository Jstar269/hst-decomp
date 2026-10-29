/* HSTMATCH module=EBOOT.BIN start=0x000c06c8 end=0x000c06dc symbol=FUN_000c06c8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/ptp_link.h"

/* Number of bytes waiting in the write queue. */
int FUN_000c06c8(PtpLink *self)
{
  return self->write_queue->tail - self->write_queue->head;
}
