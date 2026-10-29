/* HSTMATCH module=hstp_trans_main.prx start=0x002577a4 end=0x002577c4 symbol=FUN_002577a4 lang=c99 */
/* Clone of src/eboot/FUN_0024759c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/posed_obj.h"

/* Set the mode; when it changes, mark the object dirty. */
void FUN_002577a4(PosedObj *self,int mode)
{
  if (self->mode != mode) {
    self->mode = mode;
    self->dirty = 1;
  }
}
