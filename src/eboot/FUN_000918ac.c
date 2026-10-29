/* HSTMATCH module=EBOOT.BIN start=0x000918ac end=0x0009191c symbol=FUN_000918ac lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/model_set_full.h"

extern u8 DAT_00307264;
extern void FUN_00000a00();
extern void FUN_00091bc8();
extern int FUN_0009447c();

/* Destructor: release resources and the two bone sub-objects; free the object when the flag is positive. */
ModelSetFull * FUN_000918ac(ModelSetFull *self,short deleteFlag)
{
  if (self != (ModelSetFull *)0x0) {
    self->vtbl = &DAT_00307264;
    FUN_00091bc8();
    FUN_0009447c(self->boneB,0xffffffff);
    FUN_0009447c(self->boneA,0xffffffff);
    if (0 < deleteFlag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
