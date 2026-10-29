/* HSTMATCH module=EBOOT.BIN start=0x0019ca44 end=0x0019ca84 symbol=FUN_0019ca44 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/view_params.h"

/* Half of the degrees-to-radians factor (pi / 360). */
#define HALF_RAD_PER_DEG 0.008726646f

extern float FUN_0000c000(float param_1);

/* Set the angle in degrees and the value derived from half of it in radians. */
void FUN_0019ca44(float angleDeg,ViewParams *self)
{
  float derived;
  
  self->angleDeg = angleDeg;
  derived = FUN_0000c000(self->angleDeg * HALF_RAD_PER_DEG);
  self->unk214 = derived;
  return;
}
