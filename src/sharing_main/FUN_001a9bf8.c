/* HSTMATCH module=hstp_trans_main.prx start=0x001a9bf8 end=0x001a9c38 symbol=FUN_001a9bf8 lang=c99 */
/* Clone of src/eboot/FUN_0019ca44.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/view_params.h"

/* Half of the degrees-to-radians factor (pi / 360). */
#define HALF_RAD_PER_DEG 0.008726646f

extern float FUN_0000c018(float param_1);

/* Set the angle in degrees and the value derived from half of it in radians. */
void FUN_001a9bf8(float angleDeg,ViewParams *self)
{
  float derived;
  
  self->angleDeg = angleDeg;
  derived = FUN_0000c018(self->angleDeg * HALF_RAD_PER_DEG);
  self->unk214 = derived;
  return;
}
