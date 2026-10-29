/* HSTMATCH module=EBOOT.BIN start=0x00091db4 end=0x00091dd8 symbol=FUN_00091db4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/model_set_full.h"

/* Copy a 4-float vector into the second vector slot. */
void FUN_00091db4(ModelSetFull *self,float *src)
{
  self->vecB[0] = src[0];
  self->vecB[1] = src[1];
  self->vecB[2] = src[2];
  self->vecB[3] = src[3];
  return;
}
