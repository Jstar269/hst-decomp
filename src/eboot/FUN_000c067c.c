/* HSTMATCH module=EBOOT.BIN start=0x000c067c end=0x000c06b0 symbol=FUN_000c067c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/ptp_link.h"

extern u32 FUN_000ff678();

/* Takes data from the read queue; the in/out value is updated with the call's result. */
void FUN_000c067c(PtpLink *self,u32 dst,u32 *io_value)
{
  u32 result;
  
  result = FUN_000ff678(self->read_queue,dst,*io_value,0);
  *io_value = result;
}
