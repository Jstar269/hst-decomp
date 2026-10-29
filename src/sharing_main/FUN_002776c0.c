/* HSTMATCH module=hstp_trans_main.prx start=0x002776c0 end=0x002776fc symbol=FUN_002776c0 lang=c99 */
/* Clone of src/eboot/FUN_002667b8.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/mover.h"

extern float DAT_003a6b4c;

/* Stores the value into the mover, raised to the minimum DAT_003a6b4c. */
void FUN_002776c0(float value,Mover *self)
{
  float *chosen;
  float local_4;

  local_4 = value;
  if (value < DAT_003a6b4c) {
    chosen = &DAT_003a6b4c;
  }
  else {
    chosen = &local_4;
  }
  self->unk110 = *chosen;
}
