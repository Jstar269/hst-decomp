/* HSTMATCH module=EBOOT.BIN start=0x000936d8 end=0x00093750 symbol=FUN_000936d8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/model_set.h"

extern void FUN_00059100();

/* For the main, first and last model slots: run the helper with -1, then clear unkd0. */
void FUN_000936d8(ModelSet *self)
{
  ModelObj *model;

  model = self->model[MODEL_SLOT_MAIN];
  if (model != 0) {
    FUN_00059100(model,-1);
    model->unkd0 = 0;
  }
  model = self->model[0];
  if (model != 0) {
    FUN_00059100(model,-1);
    model->unkd0 = 0;
  }
  model = self->model[5];
  if (model != 0) {
    FUN_00059100(model,-1);
    model->unkd0 = 0;
  }
}
