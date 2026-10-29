/* HSTMATCH module=EBOOT.BIN start=0x00091830 end=0x000918ac symbol=FUN_00091830 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/model_set_full.h"

extern u8 DAT_00307264;
extern void FUN_00091af4();
extern void FUN_00091cbc();
extern u32 * FUN_0009444c();

/* Constructor: set the vtable, build the two bone sub-objects and the default vectors. */
ModelSetFull * FUN_00091830(ModelSetFull *self)
{
  self->vtbl = &DAT_00307264;
  FUN_0009444c(self->boneA);
  FUN_0009444c(self->boneB);
  self->level = 0;
  self->vecA[0] = -1.0f;
  self->vecA[1] = -1.0f;
  self->vecA[2] = -1.0f;
  self->vecA[3] = -1.0f;
  self->vecB[0] = 0.0f;
  self->vecB[1] = 1.0f;
  self->vecB[2] = 0.0f;
  self->vecB[3] = 0.0f;
  FUN_00091af4(self);
  FUN_00091cbc(self);
  return self;
}
