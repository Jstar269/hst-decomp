/* HSTMATCH module=hstp_trans_main.prx start=0x001aa68c end=0x001aa6c8 symbol=FUN_001aa68c lang=c99 */
/* Clone of src/eboot/FUN_0019d1b8.c (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/step_obj.h"

extern void FUN_001a871c();

/* Forward all seven arguments to the worker and count the call, only while the gate pointer is set. */
void FUN_001aa68c(StepObj *self,u32 a,u32 b,u32 c, u32 d,u32 e,u32 f,u32 g)
{
  if (self->gate != 0) {
    FUN_001a871c(self,a,b,c,d,e,f,g);
    self->calls = self->calls + 1;
  }
}
