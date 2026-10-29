/* HSTMATCH module=EBOOT.BIN start=0x0019d23c end=0x0019d268 symbol=FUN_0019d23c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/step_obj.h"

extern u32 FUN_001d9eb0();

void FUN_0019d23c(StepObj *self)
{
  u32 value;

  value = FUN_001d9eb0(1);
  self->unk40 = value;
}
