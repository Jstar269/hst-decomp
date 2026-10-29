/* HSTMATCH module=EBOOT.BIN start=0x000e985c end=0x000e98f0 symbol=FUN_000e985c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256b) corrected by hand: the this argument Ghidra dropped from the base constructor call restored; readability pass; exact match verified; names and types await human review. */
#include "hst/elem_owner.h"

#define ELEM_SIZE 0x50

extern u8 DAT_002c0f70;
extern u8 DAT_0030770c;
extern void FUN_000007f4();
extern u32 * FUN_0001f06c();
extern void FUN_000e9980();
extern void FUN_000e7494();
extern void FUN_000e98f0();

/* Constructor: base constructor, vtable, the two elements (then given their own vtable), the argument and the plain fields. */
ElemOwner * FUN_000e985c(ElemOwner *self,u32 arg)
{
  FUN_0001f06c(self);
  self->vtable = &DAT_0030770c;
  FUN_000007f4(self->elem,FUN_000e98f0,FUN_000e7494,ELEM_SIZE,OWNER_ELEM_COUNT);
  self->unk3c = arg;
  FUN_000e9980(self);
  self->elem[0].vtable = &DAT_002c0f70;
  self->elem[1].vtable = &DAT_002c0f70;
  self->unk5f8 = 0;
  self->unk5f0 = 1.0f;
  self->unk5f4 = 0;
  self->unk5fc = 0x1e;
  return self;
}
