/* HSTMATCH module=hstp_trans_main.prx start=0x00095578 end=0x000955fc symbol=FUN_00095578 lang=c99 */
/* Clone of src/eboot/FUN_00093654.c (hstclone.py tag c43): addresses substituted; exact match verified; names and types await human review. */
#include "hst/model_set.h"

extern void FUN_00059d68();

/* For the main, first and last model slots: run the helper with -1, then copy unkc4 into unkd0. */
void FUN_00095578(ModelSet *self)
{
  ModelObj *model;

  model = self->model[MODEL_SLOT_MAIN];
  if (model != 0) {
    FUN_00059d68(model,-1);
    model->unkd0 = model->unkc4;
  }
  model = self->model[0];
  if (model != 0) {
    FUN_00059d68(model,-1);
    model->unkd0 = model->unkc4;
  }
  model = self->model[5];
  if (model != 0) {
    FUN_00059d68(model,-1);
    model->unkd0 = model->unkc4;
  }
  return;
}
