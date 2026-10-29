/* HSTMATCH module=hstp_trans_main.prx start=0x002983b4 end=0x00298404 symbol=FUN_002983b4 lang=c99 */
/* Clone of src/eboot/FUN_00286cb8.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/cmd_actor.h"

extern int FUN_00158308(void *, int);

/* Deletes the two 36-byte objects of the actor and clears the pointers. */
void FUN_002983b4(CmdActor *self)
{
  void *obj;

  if (self->objB != 0) {
    FUN_00158308(self->objB,1);
    self->objB = 0;
  }
  obj = self->objA;
  if (obj != 0) {
    FUN_00158308(obj,1);
    self->objA = 0;
  }
}
