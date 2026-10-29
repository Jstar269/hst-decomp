/* HSTMATCH module=EBOOT.BIN start=0x001fc374 end=0x001fc3dc symbol=FUN_001fc374 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/part_holder.h"

extern u8 DAT_00309534;
extern void FUN_00000a00();
extern u32 * FUN_0001f0f0();
extern void FUN_001fc4e8();

/* Destructor: frees all parts; frees the object itself when deleteFlag is positive. */
PartHolder * FUN_001fc374(PartHolder *self,short deleteFlag)
{
  if (self != (PartHolder *)0x0) {
    self->vtbl = &DAT_00309534;
    FUN_001fc4e8(self,1);
    FUN_0001f0f0(self,0);
    if (0 < deleteFlag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
