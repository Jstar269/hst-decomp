/* HSTMATCH module=EBOOT.BIN start=0x0027e71c end=0x0027e748 symbol=FUN_0027e71c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/dtor_pair_obj.h"

extern u8 DAT_00309c7c;

/* Constructor: sets the vtable and clears the six words after it. */
DtorPairObj * FUN_0027e71c(DtorPairObj *self)
{
  self->vtable = &DAT_00309c7c;
  self->unk4 = 0;
  self->unk8 = 0;
  self->unkc = 0;
  self->unk10 = 0;
  self->unk14 = 0;
  self->unk18 = 0;
  return self;
}
