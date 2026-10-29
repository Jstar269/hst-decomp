/* HSTMATCH module=EBOOT.BIN start=0x0019cab8 end=0x0019cadc symbol=FUN_0019cab8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/view_params.h"

/* Set the float4 at 0x1e0. */
void FUN_0019cab8(ViewParams *self,Float4 *value)
{
  self->vec1e0.x = value->x;
  self->vec1e0.y = value->y;
  self->vec1e0.z = value->z;
  self->vec1e0.w = value->w;
  return;
}
