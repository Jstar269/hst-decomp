/* HSTMATCH module=hstp_trans_main.prx start=0x001a9c90 end=0x001a9cb4 symbol=FUN_001a9c90 lang=c99 */
/* Clone of src/eboot/FUN_0019cadc.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/view_params.h"

/* Set the float4 at 0x1d0. */
void FUN_001a9c90(ViewParams *self,Float4 *value)
{
  self->vec1d0.x = value->x;
  self->vec1d0.y = value->y;
  self->vec1d0.z = value->z;
  self->vec1d0.w = value->w;
  return;
}
