/* HSTMATCH module=EBOOT.BIN start=0x00102e38 end=0x00102ea4 symbol=FUN_00102e38 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/node_item.h"

extern u8 DAT_00307b18;

/* Constructor: set the vtable and zero every field (the limit word gets its starting value). */
NodeItem * FUN_00102e38(NodeItem *self)
{
  self->vtable = &DAT_00307b18;
  self->unk04 = 0;
  self->unk08 = 0;
  self->unk0c = 0;
  self->unk10 = 0;
  self->unk14 = 0;
  self->unk18 = 0;
  self->unk1c = 0;
  self->node = 0;
  self->unk24 = 0;
  self->unk28 = 0;
  self->unk2c = 0;
  self->unk30 = 0;
  self->unk34 = 0;
  self->unk38 = 0;
  self->unk3c = 0;
  self->unk40 = 0;
  self->unk44 = 0;
  self->unk48 = 0;
  self->limit = NODE_ITEM_LIMIT_BITS;
  self->unk50 = 0;
  return self;
}
