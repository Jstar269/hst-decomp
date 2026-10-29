/* HSTMATCH module=EBOOT.BIN start=0x000c0738 end=0x000c07b8 symbol=FUN_000c0738 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag q4) corrected by hand: the flag global typed as a byte; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/data_pack.h"

extern u8 DAT_00307408;
extern u8 DAT_00338acc;
extern u32 DAT_00338ad0;
extern u32 * FUN_0001f06c();

/* Constructor: base init, then empty tables and mode 1. */
DataPack * FUN_000c0738(DataPack *self)
{
  FUN_0001f06c();
  self->vtable = &DAT_00307408;
  self->entries.data = 0;
  self->entries.size = 0;
  self->entries.cap = 0;
  self->items.data = 0;
  self->items.count = 0;
  self->items.cap = 0;
  self->mode = 1;
  self->unk40 = 0;
  self->unk694 = 0;
  DAT_00338acc = 0;
  DAT_00338ad0 = 0;
  self->unk44 = 0;
  self->table72c = 0;
  self->table76c = 0;
  self->unk788 = 0;
  self->unk78c = 0;
  return self;
}
