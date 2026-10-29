/* HSTMATCH module=hstp_trans_main.prx start=0x001a9c48 end=0x001a9c6c symbol=FUN_001a9c48 lang=c99 */
/* Clone of src/eboot/FUN_0019ca94.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/view_params.h"

/* Set the float4 at 0x1f0. */
void FUN_001a9c48(ViewParams *self,Float4 *value)
{
  self->vec1f0.x = value->x;
  self->vec1f0.y = value->y;
  self->vec1f0.z = value->z;
  self->vec1f0.w = value->w;
  return;
}
