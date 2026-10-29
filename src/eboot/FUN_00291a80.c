/* HSTMATCH module=EBOOT.BIN start=0x00291a80 end=0x00291aec symbol=FUN_00291a80 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/material_set.h"

extern u8 DAT_00309ddc;

/* Constructor: installs the vtable and clears every member. */
MaterialSet * FUN_00291a80(MaterialSet *self)
{
  self->vtable = &DAT_00309ddc;
  self->owned = 0;
  self->res = 0;
  self->unk14 = 0;
  self->slot[0] = 0;
  self->slot[1] = 0;
  self->slot[2] = 0;
  self->slot[3] = 0;
  self->slot[4] = 0;
  self->slot[5] = 0;
  self->slot[6] = 0;
  self->unk14 = 0;
  self->unk4 = 0;
  self->unk8 = 0;
  self->unk34 = 0;
  self->unk38 = 0;
  self->unk3c = 0x3f800000;
  self->unk40 = 0;
  self->unk41 = 0;
  self->mode = 2;
  self->unk48 = 0;
  return self;
}
