/* HSTMATCH module=EBOOT.BIN start=0x0027c2c8 end=0x0027c328 symbol=FUN_0027c2c8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag p128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/blend_obj.h"

extern void FUN_0027c328(BlendObj *, int, float *);

/* Restarts the timer with the given duration and passes the two float blocks on. */
void FUN_0027c2c8(float duration, BlendObj *self, float *slotA, float *slotB)
{
  self->unk48 = 0;
  FUN_0027c328(self, 1, slotA);
  FUN_0027c328(self, 2, slotB);
  self->elapsed = 0;
  self->duration = duration;
}
