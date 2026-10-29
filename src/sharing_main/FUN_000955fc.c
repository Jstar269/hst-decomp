/* HSTMATCH module=hstp_trans_main.prx start=0x000955fc end=0x00095674 symbol=FUN_000955fc lang=c99 */
/* Clone of src/eboot/FUN_000936d8.c (hstclone.py tag c43): addresses substituted; exact match verified; names and types await human review. */
#include "hst/model_set.h"

extern void FUN_00059de4();

/* For the main, first and last model slots: run the helper with -1, then clear unkd0. */
void FUN_000955fc(ModelSet *self)
{
  ModelObj *model;

  model = self->model[MODEL_SLOT_MAIN];
  if (model != 0) {
    FUN_00059de4(model,-1);
    model->unkd0 = 0;
  }
  model = self->model[0];
  if (model != 0) {
    FUN_00059de4(model,-1);
    model->unkd0 = 0;
  }
  model = self->model[5];
  if (model != 0) {
    FUN_00059de4(model,-1);
    model->unkd0 = 0;
  }
}
