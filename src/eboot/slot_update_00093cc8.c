/* HSTMATCH module=EBOOT.BIN start=0x00093cc8 end=0x00093da4 symbol=FUN_00093cc8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: local declaration order changed (uVar3, iVar2, piVar1) to fix the saved-register assignment; readability pass; exact match verified; names and types await human review. */
#include "hst/model_set.h"

extern int DAT_002beb1c; /* slot indices in update order, MODEL_SLOT_COUNT entries */
extern void FUN_00055044();
extern void FUN_00059174();
extern void FUN_0005f0d8();
extern void FUN_00094978();

/* Per-frame update of every model slot in table order. */
void FUN_00093cc8(ModelSet *self)
{
  u32 i;
  ModelObj *model;
  int *slot_index;

  i = 0;
  slot_index = &DAT_002beb1c;
  do {
    model = self->model[*slot_index];
    if (model != 0) {
      if (((model->unk1b0 == 5) && (model->unk180 == 0)) &&
         (self->model[MODEL_SLOT_MAIN] != 0)) {
        FUN_00055044(model,self->model[MODEL_SLOT_MAIN]->unk30);
      }
      FUN_00059174(model);
      FUN_0005f0d8(model);
      if (model->unk1b0 == 2) {
        FUN_00094978(self->unk80,self->model[MODEL_SLOT_MAIN]);
        FUN_00094978(self->unkb0,self->model[MODEL_SLOT_MAIN]);
      }
    }
    i = i + 1;
    slot_index = slot_index + 1;
  } while (i < MODEL_SLOT_COUNT);
}
