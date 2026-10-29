/* HSTMATCH module=EBOOT.BIN start=0x0019cadc end=0x0019cb00 symbol=FUN_0019cadc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/view_params.h"

/* Set the float4 at 0x1d0. */
void FUN_0019cadc(ViewParams *self,Float4 *value)
{
  self->vec1d0.x = value->x;
  self->vec1d0.y = value->y;
  self->vec1d0.z = value->z;
  self->vec1d0.w = value->w;
  return;
}
