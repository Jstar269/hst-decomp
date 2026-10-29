/* HSTMATCH module=EBOOT.BIN start=0x000935b0 end=0x00093654 symbol=FUN_000935b0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a7/v21) corrected by hand: restored the float parameter and typed both helper calls; readability pass; exact match verified; names and types await human review. */
#include "hst/model_set.h"

extern void FUN_00058f38(ModelObj *, float, int);
extern void FUN_0005f110(ModelObj *, float);

/* Run the two helpers on the main, first and last model slots (those that exist). */
void FUN_000935b0(ModelSet *self,float arg)
{
  ModelObj *model;

  model = self->model[MODEL_SLOT_MAIN];
  if (model != 0) {
    FUN_00058f38(model,arg,-1);
    FUN_0005f110(model,arg);
  }
  model = self->model[0];
  if (model != 0) {
    FUN_00058f38(model,arg,-1);
    FUN_0005f110(model,arg);
  }
  model = self->model[5];
  if (model != 0) {
    FUN_00058f38(model,arg,-1);
    FUN_0005f110(model,arg);
  }
}
