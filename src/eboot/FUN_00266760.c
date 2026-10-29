/* HSTMATCH module=EBOOT.BIN start=0x00266760 end=0x002667b8 symbol=FUN_00266760 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/mover.h"

extern u32 FUN_0012c364();
extern u32 FUN_0012c5ac();
extern void FUN_002667fc();

void FUN_00266760(Mover *self)
{
  u8 ready;
  u8 result;
  
  ready = FUN_0012c364(self->unk80);
  if (ready != 0) {
    result = FUN_0012c5ac(self->unk80);
    self->unk120 = result;
    if (self->unk120 == 0) {
      FUN_002667fc(self,1);
    }
  }
}
