/* HSTMATCH module=EBOOT.BIN start=0x00093484 end=0x00093524 symbol=FUN_00093484 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: local declaration order changed (uVar3, pfVar2, iVar1) to fix the saved-register assignment; readability pass; exact match verified; names and types await human review. */
#include "hst/model_set.h"

#define SCALE_COUNT 7 /* entries in the scale table and in the unk24 table */

extern u8 DAT_002d28b8; /* float scale table */
extern int FUN_000550ec(float, int);
extern void FUN_0006e110(float param_1,float param_2,void *entry);

/* Apply scale to the main model and, when unk28 is 1, to each 8-byte entry of the unk24 table (weighted by the scale table). */
void FUN_00093484(float scale,ModelSet *self)
{
  u32 i;
  float *weight;
  int offset;

  if ((self->model[MODEL_SLOT_MAIN] != 0) &&
     (FUN_000550ec((float)(scale),(int)(self->model[MODEL_SLOT_MAIN])), self->unk28 == 1)) {
    i = 0;
    weight = (float *)&DAT_002d28b8;
    offset = 0;
    do {
      FUN_0006e110(scale * *weight,scale * *weight,self->unk24 + offset);
      i = i + 1;
      weight = weight + 1;
      offset = offset + 8;
    } while (i < SCALE_COUNT);
  }
}
