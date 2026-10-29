/* HSTMATCH module=EBOOT.BIN start=0x000d4d34 end=0x000d4ddc symbol=FUN_000d4d34 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/effect_set.h"

extern u8 DAT_0030744c;
extern void FUN_00000788();
extern void FUN_00000a00();
extern u32 * FUN_0001f0f0();
extern int FUN_00053718();
extern int FUN_00055e48();
extern void FUN_00056cb0();

/* Destructor: frees the two owned members, destroys the slot array, runs the base destructor, frees the object if delete_flag > 0. */
EffectSet * FUN_000d4d34(EffectSet *self,short delete_flag)
{
  void *member;
  
  if (self != (EffectSet *)0x0) {
    self->vtable = &DAT_0030744c;
    if (self->unk3c != 0) {
      FUN_00053718(self->unk3c,1);
      self->unk3c = 0;
    }
    member = self->unk40;
    if (member != 0) {
      FUN_00055e48(member,1);
      self->unk40 = 0;
    }
    FUN_00000788(self->slots,FUN_00056cb0,EFFECT_SLOT_SIZE,EFFECT_SLOTS);
    FUN_0001f0f0(self,0);
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
