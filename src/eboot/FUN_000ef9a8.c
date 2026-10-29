/* HSTMATCH module=EBOOT.BIN start=0x000ef9a8 end=0x000ef9d8 symbol=FUN_000ef9a8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/pausable_obj.h"

extern void FUN_00103628();

/* Disables the object. */
void FUN_000ef9a8(PausableObj *self)
{
  FUN_00103628(self,1);
  self->disabled = 1;
}
