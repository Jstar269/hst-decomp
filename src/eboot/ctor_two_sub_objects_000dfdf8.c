/* HSTMATCH module=EBOOT.BIN start=0x000dfdf8 end=0x000dfec0 symbol=FUN_000dfdf8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: sub-object allocation is 'p = alloc(); if (p) p = ctor(p, 1, 4, 1, 1, 0); m = p;' with the dropped sixth argument; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/two_sub_obj.h"

/* Size of each sub-object allocation. */
#define SUB_OBJ_SIZE 0x70

extern u8 DAT_003076d4;
extern int FUN_00000bcc();
extern u32 * FUN_0001f06c();
extern u32 * FUN_0005aa44();

TwoSubObj * FUN_000dfdf8(TwoSubObj *self,u32 arg)
{
  u32 *sub;
  
  FUN_0001f06c(self);
  self->vtable = &DAT_003076d4;
  self->arg = arg;
  sub = (u32 *)FUN_00000bcc(SUB_OBJ_SIZE);
  if (sub != (u32 *)0x0) {
    sub = FUN_0005aa44(sub,1,4,1,1,0);
  }
  self->subA = sub;
  sub = (u32 *)FUN_00000bcc(SUB_OBJ_SIZE);
  if (sub != (u32 *)0x0) {
    sub = FUN_0005aa44(sub,1,4,1,1,0);
  }
  self->subB = sub;
  self->unk50 = 0x3f800000;
  self->unk60 = 0x43000000;
  self->unk64 = 0x43000000;
  self->unk68 = 0x43000000;
  self->unk6c = 0x42800000;
  self->unk78 = 0;
  return self;
}
