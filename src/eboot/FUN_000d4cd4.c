/* HSTMATCH module=EBOOT.BIN start=0x000d4cd4 end=0x000d4d34 symbol=FUN_000d4cd4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128b) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/effect_set.h"

extern u8 DAT_0030744c;
extern void FUN_000007f4();
extern u32 * FUN_0001f06c();
extern void FUN_000d4ddc();
extern void FUN_00056b98();
extern void FUN_00056cb0();

/* Constructor: base init, vtable, array of EFFECT_SLOTS slots, clears the byte at 0x710, then fills the entries. */
EffectSet * FUN_000d4cd4(EffectSet *self)
{
  FUN_0001f06c();
  self->vtable = &DAT_0030744c;
  FUN_000007f4(self->slots,FUN_00056b98,FUN_00056cb0,EFFECT_SLOT_SIZE,EFFECT_SLOTS);
  self->unk710 = 0;
  FUN_000d4ddc(self);
  return self;
}
