/* HSTMATCH module=EBOOT.BIN start=0x00091d90 end=0x00091db4 symbol=FUN_00091d90 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/model_set_full.h"

/* Copy a 4-float vector into the first vector slot. */
void FUN_00091d90(ModelSetFull *self,float *src)
{
  self->vecA[0] = src[0];
  self->vecA[1] = src[1];
  self->vecA[2] = src[2];
  self->vecA[3] = src[3];
  return;
}
