/* HSTMATCH module=EBOOT.BIN start=0x000f5dcc end=0x000f5e20 symbol=FUN_000f5dcc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

#define ENTRY_COUNT 16
#define FLOAT_ONE_BITS 0x3f800000 /* bit pattern of 1.0f */

/* 0x40-byte table entry; only the fields reset here are named. */
typedef struct Entry {
  u8 unk0;       /* 0x00 */
  char pad1[3];
  u32 unk4;      /* 0x04 reset to 0x10 */
  u32 unk8;      /* 0x08 */
  u32 unkc;      /* 0x0c reset to -1 */
  u32 unk10;     /* 0x10 */
  u32 unk14;     /* 0x14 */
  char pad18[8];
  u32 unk20;     /* 0x20 */
  u32 unk24;     /* 0x24 */
  u32 unk28;     /* 0x28 */
  u32 unk2c;     /* 0x2c holds the bit pattern of 1.0f */
  u32 unk30;     /* 0x30 */
  char pad34[0xc];
} Entry;

typedef struct EntryOwner {
  char pad0[0xa0];
  Entry entries[ENTRY_COUNT]; /* 0xa0 */
} EntryOwner;

/* Resets every entry of the table to its default values. */
void FUN_000f5dcc(EntryOwner *self)
{
  u32 i;
  
  /* The owner pointer itself advances one entry per pass. */
  i = 0;
  do {
    self->entries[0].unk0 = 0;
    self->entries[0].unk4 = 0x10;
    self->entries[0].unk8 = 0;
    self->entries[0].unkc = 0xffffffff;
    self->entries[0].unk10 = 0;
    self->entries[0].unk14 = 0;
    self->entries[0].unk20 = 0;
    self->entries[0].unk24 = 0;
    self->entries[0].unk28 = 0;
    self->entries[0].unk2c = FLOAT_ONE_BITS;
    i = i + 1;
    self->entries[0].unk30 = 0;
    self = (EntryOwner *)((char *)self + sizeof(Entry));
  } while (i < ENTRY_COUNT);
}
