/* HSTMATCH module=hstp_trans_main.prx start=0x000d89c4 end=0x000d8a24 symbol=FUN_000d89c4 lang=c99 */
/* Clone of src/eboot/FUN_000d4cd4.c (hstclone.py tag x11): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/effect_set.h"

extern u8 DAT_003b0718;
extern void FUN_000007f4();
extern u32 * FUN_0001ec44();
extern void FUN_000d8acc();
extern void FUN_000577ec();
extern void FUN_00057904();

/* Constructor: base init, vtable, array of EFFECT_SLOTS slots, clears the byte at 0x710, then fills the entries. */
EffectSet * FUN_000d89c4(EffectSet *self)
{
  FUN_0001ec44();
  self->vtable = &DAT_003b0718;
  FUN_000007f4(self->slots,FUN_000577ec,FUN_00057904,EFFECT_SLOT_SIZE,EFFECT_SLOTS);
  self->unk710 = 0;
  FUN_000d8acc(self);
  return self;
}
