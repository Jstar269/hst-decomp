/* HSTMATCH module=EBOOT.BIN start=0x0018a3a4 end=0x0018a468 symbol=FUN_0018a3a4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/layout_list.h"

#define FLOAT_ONE_BITS 0x3f800000 /* 1.0f as stored in the u32 fields */

extern u8 DAT_002bc410;
extern u8 DAT_002e0974;
extern u8 DAT_0030779c;
extern u8 DAT_003090e0;
extern u8 DAT_00309124;
extern u32 FUN_00056098();
extern u32 * FUN_000fbf84();
extern u32 * FUN_000fc00c();
extern u32 * FUN_000fc0a0();
extern u32 * FUN_00217440();

/* Constructor: base widget, two part sub-objects, then the empty layout list. */
LayoutList * FUN_0018a3a4(LayoutList *self)
{
  FUN_000fc0a0();
  FUN_00056098(self->partA);
  self->vtable = (unsigned int)(&DAT_0030779c);
  self->unk70 = 0;
  self->unk74 = 0xffffffff;
  self->unk78 = FLOAT_ONE_BITS;
  self->unk7c = FLOAT_ONE_BITS;
  FUN_00056098(self->partB);
  self->vtableC0 = (unsigned int)(&DAT_002e0974);
  FUN_000fc00c(self,&DAT_002bc410);
  FUN_000fbf84(self->partB,&DAT_002bc410);
  FUN_00217440(&self->vtableD0);
  self->vtable = (unsigned int)(&DAT_003090e0);
  self->vtableD0 = (unsigned int)(&DAT_00309124);
  self->count = 0;
  self->unkd4 = 0;
  self->unkd8 = 0;
  self->width = 0;
  self->height = 0;
  self->originX = 0;
  self->originY = 0;
  return self;
}
