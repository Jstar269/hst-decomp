/* HSTMATCH module=EBOOT.BIN start=0x0019ca94 end=0x0019cab8 symbol=FUN_0019ca94 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/view_params.h"

/* Set the float4 at 0x1f0. */
void FUN_0019ca94(ViewParams *self,Float4 *value)
{
  self->vec1f0.x = value->x;
  self->vec1f0.y = value->y;
  self->vec1f0.z = value->z;
  self->vec1f0.w = value->w;
  return;
}
