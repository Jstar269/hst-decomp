/* HSTMATCH module=hstp_trans_main.prx start=0x00093a4c end=0x00093a70 symbol=FUN_00093a4c lang=c99 */
/* Clone of src/eboot/FUN_00091db4.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/model_set_full.h"

/* Copy a 4-float vector into the second vector slot. */
void FUN_00093a4c(ModelSetFull *self,float *src)
{
  self->vecB[0] = src[0];
  self->vecB[1] = src[1];
  self->vecB[2] = src[2];
  self->vecB[3] = src[3];
  return;
}
