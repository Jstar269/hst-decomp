/* HSTMATCH module=hstp_trans_main.prx start=0x001aa6dc end=0x001aa704 symbol=FUN_001aa6dc lang=c99 */
/* Clone of src/eboot/FUN_0019d208.c (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/step_obj.h"

extern void FUN_001a9088();

/* Run the worker only while the gate pointer is set. */
void FUN_001aa6dc(StepObj *self)
{
  if (self->gate != 0) {
    FUN_001a9088(self);
  }
}
