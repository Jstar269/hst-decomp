/* HSTMATCH module=hstp_trans_main.prx start=0x00235034 end=0x00235074 symbol=FUN_00235034 lang=c99 */
/* Clone of src/eboot/FUN_00225ac0.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/mode_parts.h"

extern void FUN_000fc200();

/* Reset: clear the part at +0x30, then restore the +0x20 part's selection words. */
void FUN_00235034(ModeObj *self)
{
  ModeParts *parts;
  ModePart20 *part20;

  parts = self->parts;
  FUN_000fc200(parts->part30,0);
  part20 = parts->part20;
  part20->unk78 = -1;
  part20->unk7c = 0;
  part20->unk80 = 0;
}
