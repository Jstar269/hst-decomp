/* HSTMATCH module=hstp_trans_main.prx start=0x000d8a24 end=0x000d8acc symbol=FUN_000d8a24 lang=c99 */
/* Clone of src/eboot/FUN_000d4d34.c (hstclone.py tag c43): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/effect_set.h"

extern u8 DAT_003b0718;
extern void FUN_00000788();
extern void FUN_00000a00();
extern u32 * FUN_0001ed28();
extern int FUN_000541d8();
extern int FUN_000569f4();
extern void FUN_00057904();

/* Destructor: frees the two owned members, destroys the slot array, runs the base destructor, frees the object if delete_flag > 0. */
EffectSet * FUN_000d8a24(EffectSet *self,short delete_flag)
{
  void *member;
  
  if (self != (EffectSet *)0x0) {
    self->vtable = &DAT_003b0718;
    if (self->unk3c != 0) {
      FUN_000541d8(self->unk3c,1);
      self->unk3c = 0;
    }
    member = self->unk40;
    if (member != 0) {
      FUN_000569f4(member,1);
      self->unk40 = 0;
    }
    FUN_00000788(self->slots,FUN_00057904,EFFECT_SLOT_SIZE,EFFECT_SLOTS);
    FUN_0001ed28(self,0);
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
