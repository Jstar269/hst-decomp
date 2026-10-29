/* HSTMATCH module=hstp_trans_main.prx start=0x001a9c6c end=0x001a9c90 symbol=FUN_001a9c6c lang=c99 */
/* Clone of src/eboot/FUN_0019cab8.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/view_params.h"

/* Set the float4 at 0x1e0. */
void FUN_001a9c6c(ViewParams *self,Float4 *value)
{
  self->vec1e0.x = value->x;
  self->vec1e0.y = value->y;
  self->vec1e0.z = value->z;
  self->vec1e0.w = value->w;
  return;
}
