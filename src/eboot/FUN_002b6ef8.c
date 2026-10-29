/* HSTMATCH module=EBOOT.BIN start=0x002b6ef8 end=0x002b6f24 symbol=FUN_002b6ef8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/dtor_pair_obj.h"

extern u8 DAT_00309ff0;

/* Constructor: sets the vtable and clears the six words after it. */
DtorPairObj * FUN_002b6ef8(DtorPairObj *self)
{
  self->vtable = &DAT_00309ff0;
  self->unk4 = 0;
  self->unk8 = 0;
  self->unkc = 0;
  self->unk10 = 0;
  self->unk14 = 0;
  self->unk18 = 0;
  return self;
}
