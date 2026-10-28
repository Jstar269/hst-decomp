/* HSTMATCH module=EBOOT.BIN start=0x002347c4 end=0x00234800 symbol=FUN_002347c4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag u1ge) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/holder.h"

extern u8 DAT_00309898;
extern u8 DAT_003098a4;

/* Constructor of the derived holder: base vtable first, then the derived one, all members zeroed. */
HolderDerived * FUN_002347c4(HolderDerived *self)
{
  self->base.vptr = (void *)(&DAT_003098a4);
  self->base.member08[0] = 0;
  self->base.member08[1] = 0;
  self->base.member08[2] = 0;
  self->base.unk04 = 0;
  self->base.vptr = (void *)(&DAT_00309898);
  self->member14[0] = 0;
  self->member14[1] = 0;
  self->member14[2] = 0;
  return self;
}
