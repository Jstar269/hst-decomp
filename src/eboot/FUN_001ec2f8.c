/* HSTMATCH module=EBOOT.BIN start=0x001ec2f8 end=0x001ec35c symbol=FUN_001ec2f8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/overlay_obj.h"

extern OverlayObj *DAT_0034a138;
extern void FUN_001ec3b8();
extern void FUN_001ec564();

/* Construct the overlay: clear its fields, register it globally and allocate its parts. */
OverlayObj * FUN_001ec2f8(OverlayObj *self)
{
  self->part_a = 0;
  self->part_b = 0;
  self->link = 0;
  DAT_0034a138 = self;
  FUN_001ec3b8();
  FUN_001ec564(self,0xb,0);
  self->unk10 = 0;
  self->unk1c = 0;
  self->unk14 = 0;
  self->unk1d = 1;
  self->unk1e = 0;
  return self;
}
