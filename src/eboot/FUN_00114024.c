/* HSTMATCH module=EBOOT.BIN start=0x00114024 end=0x001140d0 symbol=FUN_00114024 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag q1) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/sub_pair_obj.h"

extern u8 DAT_002bc410;
extern u8 DAT_0030779c;
extern u8 DAT_00307a90;
extern u32 FUN_00056098();
extern u32 * FUN_000fbf84();
extern u32 * FUN_000fc00c();
extern u32 * FUN_000fc0a0();

/* Constructor: base init, two embedded sub-objects, then the final vtable. */
SubPairObj * FUN_00114024(SubPairObj *self,u32 arg)
{
  FUN_000fc0a0(self);
  FUN_00056098(self->subA);
  self->vtable = (unsigned int)(&DAT_0030779c);
  self->unk70 = 0;
  self->unk74 = 0xffffffff;
  self->unk78 = 0x3f800000;
  self->unk7c = 0x3f800000;
  FUN_00056098(self->subB);
  self->arg = arg;
  FUN_000fc00c(self,&DAT_002bc410);
  FUN_000fbf84(self->subB,&DAT_002bc410);
  self->vtable = (unsigned int)(&DAT_00307a90);
  self->unkD0 = 1;
  self->unkD4 = 2;
  self->unkD8 = 0;
  return self;
}
