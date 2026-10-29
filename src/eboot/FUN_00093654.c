/* HSTMATCH module=EBOOT.BIN start=0x00093654 end=0x000936d8 symbol=FUN_00093654 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/model_set.h"

extern void FUN_00059084();

/* For the main, first and last model slots: run the helper with -1, then copy unkc4 into unkd0. */
void FUN_00093654(ModelSet *self)
{
  ModelObj *model;

  model = self->model[MODEL_SLOT_MAIN];
  if (model != 0) {
    FUN_00059084(model,-1);
    model->unkd0 = model->unkc4;
  }
  model = self->model[0];
  if (model != 0) {
    FUN_00059084(model,-1);
    model->unkd0 = model->unkc4;
  }
  model = self->model[5];
  if (model != 0) {
    FUN_00059084(model,-1);
    model->unkd0 = model->unkc4;
  }
  return;
}
