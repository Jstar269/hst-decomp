/* HSTMATCH module=EBOOT.BIN start=0x001c1ff8 end=0x001c2118 symbol=FUN_001c1ff8 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py candidate FUN_001c1ff8) corrected by hand: swapped the declaration order of the loop counter and pointer; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void *FUN_000114c0();

#define SLOT_COUNT 4
#define NO_VALUE_16 (-1)

/* One 0x120-byte slot; only the leading fields are initialised here. */
typedef struct NameSlot {
  u8 unk0;                /* 0x00 */
  u8 unk1;                /* 0x01 */
  char pad02;
  u8 unk3;                /* 0x03 */
  char name[13];          /* 0x04 UTF-8 default name */
  char pad11[0x14];
  u8 unk25;               /* 0x25 */
  u8 unk26;               /* 0x26 */
  u8 unk27;               /* 0x27 */
  u8 unk28;               /* 0x28 */
  char pad29[3];
  int unk2c;              /* 0x2c -1 when unset */
  int unk30;              /* 0x30 -1 when unset */
  int unk34;              /* 0x34 bit pattern of 5.0f */
  u8 unk38;               /* 0x38 */
  u8 unk39;               /* 0x39 */
  char pad3a[2];
  int unk3c;              /* 0x3c */
  char pad40[0x120 - 0x40];
} NameSlot;               /* size 0x120 */

typedef struct NameTable {
  u8 unk0;                /* 0x00 */
  u8 unk1;                /* 0x01 */
  u8 unk2;                /* 0x02 */
  u8 unk3;                /* 0x03 */
  char pad04[5];
  u8 unk9;                /* 0x09 */
  u8 unka;                /* 0x0a */
  char padb[5];
  u8 unk10;               /* 0x10 */
  char pad11[3];
  u8 unk14;               /* 0x14 */
  char pad15[0xe0 - 0x15];
  NameSlot slot[SLOT_COUNT]; /* 0xe0 */
} NameTable;

/* Fields that follow the slot array's first three entries in the same object. */
typedef struct NameTableTail {
  char pad00[0x498];
  u8 unk498;              /* 0x498 */
  u8 unk499;              /* 0x499 */
  char pad49a[2];
  char block[0x6c];       /* 0x49c cleared block */
} NameTableTail;

void FUN_001c1ff8(NameTable *self)
{
  int i;
  NameTable *cur;
  NameTableTail *tail = (NameTableTail *)self;
  
  self->unk0 = 0;
  self->unk1 = 1;
  self->unk2 = 2;
  self->unk3 = 0;
  self->unk9 = 0;
  self->unka = 0;
  self->unk10 = 0;
  self->unk14 = 0;
  i = 0;
  cur = self; /* advanced one slot per pass; its first slot is the one filled */
  do {
    cur->slot[0].unk0 = 0;
    cur->slot[0].unk3 = 0;
    cur->slot[0].unk1 = 0;
    cur->slot[0].unk25 = 0;
    cur->slot[0].unk26 = 0;
    cur->slot[0].unk27 = 0;
    cur->slot[0].unk28 = 0;
    cur->slot[0].unk2c = -1;
    cur->slot[0].unk30 = -1;
    cur->slot[0].unk34 = 0x40a00000;
    cur->slot[0].unk38 = 10;
    cur->slot[0].unk39 = 0;
    cur->slot[0].unk3c = 0;
    /* default name: UTF-8 bytes of a 4-character string, then 'P' */
    cur->slot[0].name[0] = 0xe3;
    cur->slot[0].name[1] = 0x81;
    cur->slot[0].name[2] = 0xbf;
    cur->slot[0].name[3] = 0xe3;
    cur->slot[0].name[4] = 0x82;
    cur->slot[0].name[5] = 0x93;
    cur->slot[0].name[6] = 0xe3;
    cur->slot[0].name[7] = 0x83;
    cur->slot[0].name[8] = 0x86;
    cur->slot[0].name[9] = 0xe3;
    cur->slot[0].name[10] = 0x83;
    cur->slot[0].name[11] = 0x8b;
    i = i + 1;
    cur->slot[0].name[12] = 0x50;
    cur = (NameTable *)((char *)cur + sizeof(NameSlot));
  } while (i < SLOT_COUNT);
  tail->unk498 = 0;
  tail->unk499 = 0;
  FUN_000114c0(tail->block,0,0x6c);
  *(s16 *)((char *)self + 0x504) = NO_VALUE_16;
  *(s16 *)((char *)self + 0x506) = NO_VALUE_16;
  *(s16 *)((char *)self + 0x4c0) = NO_VALUE_16;
  return;
}
