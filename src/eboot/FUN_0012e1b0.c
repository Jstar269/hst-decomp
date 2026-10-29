/* HSTMATCH module=EBOOT.BIN start=0x0012e1b0 end=0x0012e1e8 symbol=FUN_0012e1b0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

typedef struct PosObj {
  char pad00[0x70];
  float pos[4];               /* 0x70 position; the y component is lifted by a global offset */
} PosObj;

extern float DAT_0033b57c;

/* Copies the four floats into pos and raises y by the global offset. */
void FUN_0012e1b0(PosObj *self,float *src)
{
  self->pos[0] = src[0];
  self->pos[1] = src[1];
  self->pos[2] = src[2];
  self->pos[3] = src[3];
  self->pos[1] = self->pos[1] + DAT_0033b57c;
  return;
}
