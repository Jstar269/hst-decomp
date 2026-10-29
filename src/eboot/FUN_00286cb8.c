/* HSTMATCH module=EBOOT.BIN start=0x00286cb8 end=0x00286d08 symbol=FUN_00286cb8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/cmd_actor.h"

extern int FUN_0014c820(void *, int);

/* Deletes the two 36-byte objects of the actor and clears the pointers. */
void FUN_00286cb8(CmdActor *self)
{
  void *obj;

  if (self->objB != 0) {
    FUN_0014c820(self->objB,1);
    self->objB = 0;
  }
  obj = self->objA;
  if (obj != 0) {
    FUN_0014c820(obj,1);
    self->objA = 0;
  }
}
