/* HSTMATCH module=EBOOT.BIN start=0x0010c17c end=0x0010c228 symbol=FUN_0010c17c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: the virtual-base constructor argument is the base sub-object pointer plus 0x120 (not this+400), and the vbase back-pointer store is the pointer difference (this+0x70)-*this; exact match verified; readability pass; names and types await human review. */
#include "hst/types.h"
#include "hst/stream_obj.h"

extern u8 DAT_002d9210;
extern u8 DAT_00307f04;
extern u8 DAT_00307f18;
extern u8 DAT_00307f60;
extern u32 * FUN_00103d6c();
extern u32 * FUN_00103d80();
extern void FUN_0010b308();
extern void FUN_0010c2b4();

/* Constructs the stream; the virtual base is built first when with_base is nonzero. */
StreamObj * FUN_0010c17c(StreamObj *self,short with_base)
{
  StreamBase *base;
  
  if (with_base != 0) {
    base = &self->base;
    self->vbase = base;
    FUN_00103d80(base,&DAT_002d9210);
    base->vtable = &DAT_00307f60;
    FUN_00103d6c(base->member120);
    FUN_0010b308(base);
  }
  self->vtable = &DAT_00307f04;
  self->vbase->vtable = &DAT_00307f18;
  self->vbase->derived_offset = (int)&self->base - (int)self->vbase;
  self->unk08 = 0;
  self->unk0c = 0;
  self->unk6c = 0;
  self->unk6d = 0;
  FUN_0010c2b4(self);
  return self;
}
