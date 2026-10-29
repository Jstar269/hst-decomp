/* HSTMATCH module=hstp_trans_main.prx start=0x00093544 end=0x000935b4 symbol=FUN_00093544 lang=c99 */
/* Clone of src/eboot/FUN_000918ac.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/model_set_full.h"

extern u8 DAT_003b0530;
extern void FUN_00000a00();
extern void FUN_00093860();
extern int FUN_000963a0();

/* Destructor: release resources and the two bone sub-objects; free the object when the flag is positive. */
ModelSetFull * FUN_00093544(ModelSetFull *self,short deleteFlag)
{
  if (self != (ModelSetFull *)0x0) {
    self->vtbl = &DAT_003b0530;
    FUN_00093860();
    FUN_000963a0(self->boneB,0xffffffff);
    FUN_000963a0(self->boneA,0xffffffff);
    if (0 < deleteFlag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
