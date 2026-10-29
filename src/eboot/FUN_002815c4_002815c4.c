/* HSTMATCH module=EBOOT.BIN start=0x002815c4 end=0x002817e0 symbol=FUN_002815c4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v0c) corrected by hand: matching idiom: signed-char constants for high-bit byte fields; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/slot_block.h"

/* Name source object: nested tables from which a default name string is chosen. */
typedef struct NameEntry {
  char pad00[0xc];
  u8 *text;               /* 0x0c */
} NameEntry;
typedef struct NameTable {
  NameEntry *entries;     /* 0x00 */
  int count;              /* 0x04 */
} NameTable;
typedef struct NameCount {
  char pad00[8];
  int count;              /* 0x08 */
} NameCount;
typedef struct NameSource {
  char pad00[4];
  int unk4;               /* 0x04, zero when there is no name data */
  NameCount *unk8;        /* 0x08 */
  NameTable *unkc;        /* 0x0c */
} NameSource;

extern u8 DAT_002c0e18;
extern u8 DAT_002c0e1c;
extern u8 DAT_002c0e20;
extern void FUN_000133f4();
extern u32 FUN_0001342c();
extern u32 * FUN_000149a8();
extern NameSource * FUN_0018c9f4();
extern int FUN_002b78f8();

/* Resets the records of slots 1 and 2 to defaults and gives both the chosen name. */
void FUN_002815c4(SlotBlockOwner *self)
{
  NameSource *src;
  u32 seed;
  u8 *text;
  
  self->block.slots[1].rec.unk00 = 0;
  self->block.slots[1].rec.unk03 = 0;
  self->block.slots[1].rec.unk01 = 0;
  self->block.slots[1].rec.unk25 = 0;
  self->block.slots[1].rec.unk26 = 0;
  self->block.slots[1].rec.unk27 = 0;
  self->block.slots[1].rec.unk28 = 0;
  self->block.slots[1].rec.unk2c = SLOT_ID_NONE;
  self->block.slots[1].rec.unk30 = SLOT_ID_NONE;
  self->block.slots[1].rec.unk34 = SLOT_REC_DEFAULT_SCALE;
  self->block.slots[1].rec.unk38 = 10;
  self->block.slots[1].rec.unk39 = 0;
  self->block.slots[1].rec.unk3c = 0;
  self->block.slots[1].rec.name[0] = (signed char)0xe3;
  self->block.slots[1].rec.name[1] = (signed char)0x81;
  self->block.slots[1].rec.name[2] = (signed char)0xbf;
  self->block.slots[1].rec.name[3] = (signed char)0xe3;
  self->block.slots[1].rec.name[4] = (signed char)0x82;
  self->block.slots[1].rec.name[5] = (signed char)0x93;
  self->block.slots[1].rec.name[6] = (signed char)0xe3;
  self->block.slots[1].rec.name[7] = (signed char)0x83;
  self->block.slots[1].rec.name[8] = (signed char)0x86;
  self->block.slots[1].rec.name[9] = (signed char)0xe3;
  self->block.slots[1].rec.name[10] = (signed char)0x83;
  self->block.slots[1].rec.name[11] = (signed char)0x8b;
  self->block.slots[1].rec.name[12] = 0x50;
  self->block.slots[2].rec.unk00 = 0;
  self->block.slots[2].rec.unk03 = 0;
  self->block.slots[2].rec.unk01 = 0;
  self->block.slots[2].rec.unk25 = 0;
  self->block.slots[2].rec.unk26 = 0;
  self->block.slots[2].rec.unk27 = 0;
  self->block.slots[2].rec.unk28 = 0;
  self->block.slots[2].rec.unk2c = SLOT_ID_NONE;
  self->block.slots[2].rec.unk30 = SLOT_ID_NONE;
  self->block.slots[2].rec.unk34 = SLOT_REC_DEFAULT_SCALE;
  self->block.slots[2].rec.unk38 = 10;
  self->block.slots[2].rec.unk39 = 0;
  self->block.slots[2].rec.unk3c = 0;
  self->block.slots[2].rec.name[0] = (signed char)0xe3;
  self->block.slots[2].rec.name[1] = (signed char)0x81;
  self->block.slots[2].rec.name[2] = (signed char)0xbf;
  self->block.slots[2].rec.name[3] = (signed char)0xe3;
  self->block.slots[2].rec.name[4] = (signed char)0x82;
  self->block.slots[2].rec.name[5] = (signed char)0x93;
  self->block.slots[2].rec.name[6] = (signed char)0xe3;
  self->block.slots[2].rec.name[7] = (signed char)0x83;
  self->block.slots[2].rec.name[8] = (signed char)0x86;
  self->block.slots[2].rec.name[9] = (signed char)0xe3;
  self->block.slots[2].rec.name[10] = (signed char)0x83;
  self->block.slots[2].rec.name[11] = (signed char)0x8b;
  self->block.slots[2].rec.name[12] = 0x50;
  self->block.slots[1].rec.unk25 = 1;
  self->block.slots[2].rec.unk25 = 1;
  self->block.slots[1].rec.unk00 = 1;
  self->block.slots[2].rec.unk00 = 1;
  src = FUN_0018c9f4(0x13);
  if (src->unk4 == 0) {
    text = &DAT_002c0e20;
  }
  else if (src->unk8->count < 1) {
    text = &DAT_002c0e1c;
  }
  else if (src->unkc->count < 4) {
    text = &DAT_002c0e18;
  }
  else {
    text = src->unkc->entries->text;
  }
  FUN_000149a8(self->block.slots[1].rec.name,text);
  if (src->unk4 == 0) {
    text = &DAT_002c0e20;
  }
  else if (src->unk8->count < 1) {
    text = &DAT_002c0e1c;
  }
  else if (src->unkc->count < 4) {
    text = &DAT_002c0e18;
  }
  else {
    text = src->unkc->entries->text;
  }
  FUN_000149a8(self->block.slots[2].rec.name,text);
  seed = FUN_002b78f8();
  FUN_000133f4(seed);
  seed = FUN_0001342c();
  self->block.slots[1].rec.unk3c = seed;
  seed = FUN_0001342c();
  self->block.slots[2].rec.unk3c = seed;
}
