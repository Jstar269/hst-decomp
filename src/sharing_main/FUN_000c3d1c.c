/* HSTMATCH module=hstp_trans_main.prx start=0x000c3d1c end=0x000c3d50 symbol=FUN_000c3d1c lang=c99 */
/* Clone of src/eboot/FUN_000c067c.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/ptp_link.h"

extern u32 FUN_00104f10();

/* Takes data from the read queue; the in/out value is updated with the call's result. */
void FUN_000c3d1c(PtpLink *self,u32 dst,u32 *io_value)
{
  u32 result;
  
  result = FUN_00104f10(self->read_queue,dst,*io_value,0);
  *io_value = result;
}
