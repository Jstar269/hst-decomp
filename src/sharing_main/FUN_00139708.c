/* HSTMATCH module=hstp_trans_main.prx start=0x00139708 end=0x00139740 symbol=FUN_00139708 lang=c99 */
/* Clone of src/eboot/FUN_0012e1b0.c (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

typedef struct PosObj {
  char pad00[0x70];
  float pos[4];               /* 0x70 position; the y component is lifted by a global offset */
} PosObj;

extern float DAT_003e48bc;

/* Copies the four floats into pos and raises y by the global offset. */
void FUN_00139708(PosObj *self,float *src)
{
  self->pos[0] = src[0];
  self->pos[1] = src[1];
  self->pos[2] = src[2];
  self->pos[3] = src[3];
  self->pos[1] = self->pos[1] + DAT_003e48bc;
  return;
}
