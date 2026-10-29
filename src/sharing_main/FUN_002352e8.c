/* HSTMATCH module=hstp_trans_main.prx start=0x002352e8 end=0x0023530c symbol=FUN_002352e8 lang=c99 */
/* Clone of src/eboot/FUN_00225d74.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/mode_parts.h"

/* Reset the +0x20 part's words; the last two only when `full` is nonzero. */
void FUN_002352e8(ModeObj *self,int full)
{
  ModePart20 *part20;

  part20 = self->parts->part20;
  part20->unk78 = -1;
  if (full != 0) {
    part20->unk7c = 0;
    part20->unk80 = 0;
  }
}
