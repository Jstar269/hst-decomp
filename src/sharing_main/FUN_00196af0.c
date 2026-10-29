/* HSTMATCH module=hstp_trans_main.prx start=0x00196af0 end=0x00196bb4 symbol=FUN_00196af0 lang=c99 */
/* Clone of src/eboot/FUN_0018a3a4.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/layout_list.h"

#define FLOAT_ONE_BITS 0x3f800000 /* 1.0f as stored in the u32 fields */

extern u8 DAT_002cc260;
extern u8 DAT_00387fac;
extern u8 DAT_003b0a68;
extern u8 DAT_003b23ac;
extern u8 DAT_003b23f0;
extern u32 FUN_00056cac();
extern u32 * FUN_001016c0();
extern u32 * FUN_00101748();
extern u32 * FUN_001017dc();
extern u32 * FUN_002264e8();

/* Constructor: base widget, two part sub-objects, then the empty layout list. */
LayoutList * FUN_00196af0(LayoutList *self)
{
  FUN_001017dc();
  FUN_00056cac(self->partA);
  self->vtable = (unsigned int)(&DAT_003b0a68);
  self->unk70 = 0;
  self->unk74 = 0xffffffff;
  self->unk78 = FLOAT_ONE_BITS;
  self->unk7c = FLOAT_ONE_BITS;
  FUN_00056cac(self->partB);
  self->vtableC0 = (unsigned int)(&DAT_00387fac);
  FUN_00101748(self,&DAT_002cc260);
  FUN_001016c0(self->partB,&DAT_002cc260);
  FUN_002264e8(&self->vtableD0);
  self->vtable = (unsigned int)(&DAT_003b23ac);
  self->vtableD0 = (unsigned int)(&DAT_003b23f0);
  self->count = 0;
  self->unkd4 = 0;
  self->unkd8 = 0;
  self->width = 0;
  self->height = 0;
  self->originX = 0;
  self->originY = 0;
  return self;
}
