/* HSTMATCH module=hstp_trans_main.prx start=0x001a9c38 end=0x001a9c40 symbol=FUN_001a9c38 lang=c99 */
/* Clone of src/eboot/FUN_0019ca84.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/view_params.h"

/* Set the float at 0x208. */
void FUN_001a9c38(float value,ViewParams *self)
{
  self->unk208 = value;
  return;
}
