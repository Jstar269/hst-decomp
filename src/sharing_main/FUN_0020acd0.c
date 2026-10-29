/* HSTMATCH module=hstp_trans_main.prx start=0x0020acd0 end=0x0020ad2c symbol=FUN_0020acd0 lang=c99 */
/* Clone of src/eboot/FUN_001fc5b8.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/part_holder.h"

extern void FUN_00108f54();
extern void FUN_0020ae30();

/* Set the enabled flag on the holder and its parts B and A, then refresh the widgets. */
void FUN_0020acd0(PartHolder *self,u8 enabled)
{
  PartA *part;

  self->enabled = enabled;
  self->partB->enabled = enabled;
  part = self->partA;
  FUN_00108f54(part);
  part->enabled = enabled;
  FUN_0020ae30(self,HOLDER_MODE_SYNC);
}
