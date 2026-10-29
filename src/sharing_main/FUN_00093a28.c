/* HSTMATCH module=hstp_trans_main.prx start=0x00093a28 end=0x00093a4c symbol=FUN_00093a28 lang=c99 */
/* Clone of src/eboot/FUN_00091d90.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/model_set_full.h"

/* Copy a 4-float vector into the first vector slot. */
void FUN_00093a28(ModelSetFull *self,float *src)
{
  self->vecA[0] = src[0];
  self->vecA[1] = src[1];
  self->vecA[2] = src[2];
  self->vecA[3] = src[3];
  return;
}
