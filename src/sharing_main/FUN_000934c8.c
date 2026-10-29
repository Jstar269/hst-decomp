/* HSTMATCH module=hstp_trans_main.prx start=0x000934c8 end=0x00093544 symbol=FUN_000934c8 lang=c99 */
/* Clone of src/eboot/FUN_00091830.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/model_set_full.h"

extern u8 DAT_003b0530;
extern void FUN_0009378c();
extern void FUN_00093954();
extern u32 * FUN_00096370();

/* Constructor: set the vtable, build the two bone sub-objects and the default vectors. */
ModelSetFull * FUN_000934c8(ModelSetFull *self)
{
  self->vtbl = &DAT_003b0530;
  FUN_00096370(self->boneA);
  FUN_00096370(self->boneB);
  self->level = 0;
  self->vecA[0] = -1.0f;
  self->vecA[1] = -1.0f;
  self->vecA[2] = -1.0f;
  self->vecA[3] = -1.0f;
  self->vecB[0] = 0.0f;
  self->vecB[1] = 1.0f;
  self->vecB[2] = 0.0f;
  self->vecB[3] = 0.0f;
  FUN_0009378c(self);
  FUN_00093954(self);
  return self;
}
