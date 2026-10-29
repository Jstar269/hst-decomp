/* HSTMATCH module=hstp_trans_main.prx start=0x001fa638 end=0x001fa69c symbol=FUN_001fa638 lang=c99 */
/* Clone of src/eboot/FUN_001ec2f8.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/overlay_obj.h"

extern OverlayObj *DAT_003f3470;
extern void FUN_001fa6f8();
extern void FUN_001fa8a4();

/* Construct the overlay: clear its fields, register it globally and allocate its parts. */
OverlayObj * FUN_001fa638(OverlayObj *self)
{
  self->part_a = 0;
  self->part_b = 0;
  self->link = 0;
  DAT_003f3470 = self;
  FUN_001fa6f8();
  FUN_001fa8a4(self,0xb,0);
  self->unk10 = 0;
  self->unk1c = 0;
  self->unk14 = 0;
  self->unk1d = 1;
  self->unk1e = 0;
  return self;
}
