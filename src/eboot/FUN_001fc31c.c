/* HSTMATCH module=EBOOT.BIN start=0x001fc31c end=0x001fc374 symbol=FUN_001fc31c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/part_holder.h"

extern u8 DAT_00309534;
extern u32 * FUN_0001f06c();
extern void FUN_001fc718();

/* Constructor: no parts yet, mode NONE, disabled. */
PartHolder * FUN_001fc31c(PartHolder *self)
{
  FUN_0001f06c();
  self->vtbl = &DAT_00309534;
  self->partB = 0;
  self->partC = 0;
  self->partA = 0;
  self->partD = 0;
  FUN_001fc718(self,HOLDER_MODE_NONE);
  self->timer = 0;
  self->enabled = 0;
  return self;
}
