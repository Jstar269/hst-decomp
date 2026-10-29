/* HSTMATCH module=hstp_trans_main.prx start=0x0020aa34 end=0x0020aa8c symbol=FUN_0020aa34 lang=c99 */
/* Clone of src/eboot/FUN_001fc31c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/part_holder.h"

extern u8 DAT_003b2800;
extern u32 * FUN_0001ec44();
extern void FUN_0020ae30();

/* Constructor: no parts yet, mode NONE, disabled. */
PartHolder * FUN_0020aa34(PartHolder *self)
{
  FUN_0001ec44();
  self->vtbl = &DAT_003b2800;
  self->partB = 0;
  self->partC = 0;
  self->partA = 0;
  self->partD = 0;
  FUN_0020ae30(self,HOLDER_MODE_NONE);
  self->timer = 0;
  self->enabled = 0;
  return self;
}
