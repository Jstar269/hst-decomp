/* HSTMATCH module=EBOOT.BIN start=0x0019d1b8 end=0x0019d1f4 symbol=FUN_0019d1b8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag u1ge) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/step_obj.h"

extern void FUN_0019b490();

/* Forward all seven arguments to the worker and count the call, only while the gate pointer is set. */
void FUN_0019d1b8(StepObj *self,u32 a,u32 b,u32 c, u32 d,u32 e,u32 f,u32 g)
{
  if (self->gate != 0) {
    FUN_0019b490(self,a,b,c,d,e,f,g);
    self->calls = self->calls + 1;
  }
}
