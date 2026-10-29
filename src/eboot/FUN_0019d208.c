/* HSTMATCH module=EBOOT.BIN start=0x0019d208 end=0x0019d230 symbol=FUN_0019d208 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag u1ge) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/step_obj.h"

extern void FUN_0019be18();

/* Run the worker only while the gate pointer is set. */
void FUN_0019d208(StepObj *self)
{
  if (self->gate != 0) {
    FUN_0019be18(self);
  }
}
