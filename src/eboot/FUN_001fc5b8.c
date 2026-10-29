/* HSTMATCH module=EBOOT.BIN start=0x001fc5b8 end=0x001fc614 symbol=FUN_001fc5b8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/part_holder.h"

extern void FUN_00103628();
extern void FUN_001fc718();

/* Set the enabled flag on the holder and its parts B and A, then refresh the widgets. */
void FUN_001fc5b8(PartHolder *self,u8 enabled)
{
  PartA *part;

  self->enabled = enabled;
  self->partB->enabled = enabled;
  part = self->partA;
  FUN_00103628(part);
  part->enabled = enabled;
  FUN_001fc718(self,HOLDER_MODE_SYNC);
}
