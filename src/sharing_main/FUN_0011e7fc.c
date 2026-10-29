/* HSTMATCH module=hstp_trans_main.prx start=0x0011e7fc end=0x0011e8a8 symbol=FUN_0011e7fc lang=c99 */
/* Clone of src/eboot/FUN_00114024.c (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/sub_pair_obj.h"

extern u8 DAT_002cc260;
extern u8 DAT_003b0a68;
extern u8 DAT_003b0d5c;
extern u32 FUN_00056cac();
extern u32 * FUN_001016c0();
extern u32 * FUN_00101748();
extern u32 * FUN_001017dc();

/* Constructor: base init, two embedded sub-objects, then the final vtable. */
SubPairObj * FUN_0011e7fc(SubPairObj *self,u32 arg)
{
  FUN_001017dc(self);
  FUN_00056cac(self->subA);
  self->vtable = (unsigned int)(&DAT_003b0a68);
  self->unk70 = 0;
  self->unk74 = 0xffffffff;
  self->unk78 = 0x3f800000;
  self->unk7c = 0x3f800000;
  FUN_00056cac(self->subB);
  self->arg = arg;
  FUN_00101748(self,&DAT_002cc260);
  FUN_001016c0(self->subB,&DAT_002cc260);
  self->vtable = (unsigned int)(&DAT_003b0d5c);
  self->unkD0 = 1;
  self->unkD4 = 2;
  self->unkD8 = 0;
  return self;
}
