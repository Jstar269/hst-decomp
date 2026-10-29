/* HSTMATCH module=hstp_trans_main.prx start=0x001a9c40 end=0x001a9c48 symbol=FUN_001a9c40 lang=c99 */
/* Clone of src/eboot/FUN_0019ca8c.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/view_params.h"

/* Set the float at 0x204. */
void FUN_001a9c40(float value,ViewParams *self)
{
  self->unk204 = value;
  return;
}
