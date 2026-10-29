/* HSTMATCH module=hstp_trans_main.prx start=0x0028d638 end=0x0028d698 symbol=FUN_0028d638 lang=c99 */
/* Clone of src/eboot/FUN_0027c2c8.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/blend_obj.h"

extern void FUN_0028d698(BlendObj *, int, float *);

/* Restarts the timer with the given duration and passes the two float blocks on. */
void FUN_0028d638(float duration, BlendObj *self, float *slotA, float *slotB)
{
  self->unk48 = 0;
  FUN_0028d698(self, 1, slotA);
  FUN_0028d698(self, 2, slotB);
  self->elapsed = 0;
  self->duration = duration;
}
