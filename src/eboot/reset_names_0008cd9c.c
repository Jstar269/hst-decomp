/* HSTMATCH module=EBOOT.BIN start=0x0008cd9c end=0x0008cea4 symbol=FUN_0008cd9c lang=c99 helpers=FUN_0008cae8@0x0008cae8-0x0008cb14 */
/* Hand-written reconstruction from the disassembly (lane sw1 near miss wip/reset_names_0008cd9c.c, completed with its same-file static helper FUN_0008cae8 defined in front of it and placed at its own retail address by helpers=); exact match verified; names and types await human review. */
#include "hst/room_block.h"

typedef unsigned char uchar;
typedef unsigned int uint;

enum { ROOM_ENTRY_COUNT = 4, ROOM_ENTRY_SIZE = 0xf4 };

/* The tail of one entry as seen from the start of the record: the cursor starts at the record and advances
   by ROOM_ENTRY_SIZE per entry, so the fields sit 0x15c bytes past the cursor. */
typedef struct RoomRow {
  char pad0[0x15c];
  uchar unk15c;          /* 0x15c */
  char text[0x23];       /* 0x15d default UTF-8 text bytes; the first byte is cleared again afterwards */
  float unk180;          /* 0x180 */
  uchar unk184;          /* 0x184 */
  uchar unk185;          /* 0x185 */
} RoomRow;

/* Room record (0x4e4 bytes), cleared and filled with defaults by the initialiser. */
typedef struct RoomInfo {
  char pad0[0x10];
  char unk10[0x48];      /* 0x10 passed by address to the helper call */
  char unk58[8];         /* 0x58 cleared */
  int unk60;             /* 0x60 */
  char unk64[0x74 - 0x64]; /* 0x64 cleared */
  char pad74[0x94 - 0x74];
  char entries[ROOM_ENTRY_COUNT * ROOM_ENTRY_SIZE]; /* 0x94 four entries, walked with RoomRow */
  RoomBlock block;       /* 0x464 */
  char pad4d0[0x4e4 - 0x4d0];
} RoomInfo;

extern char DAT_002beac0[];
extern uint * FUN_000114c0(void *, int, uint);
static void FUN_0008cae8(...)
{
}
extern void FUN_002b7898(void *);

/* Resets the room record to its defaults. */
void FUN_0008cd9c(RoomInfo *info)
{
  uint i;
  RoomRow *entry;
  
  FUN_000114c0(info,0,sizeof(RoomInfo));
  i = 0;
  entry = (RoomRow *)info;
  do {
    entry->unk15c = 0;
    entry->unk180 = 5.0f;
    entry->unk184 = 10;
    entry->unk185 = 0;
    entry->text[0] = 0xe3;
    entry->text[1] = 0x81;
    entry->text[2] = 0xbf;
    entry->text[3] = 0xe3;
    entry->text[4] = 0x82;
    entry->text[5] = 0x93;
    entry->text[6] = 0xe3;
    entry->text[7] = 0x83;
    entry->text[8] = 0x86;
    entry->text[9] = 0xe3;
    entry->text[10] = 0x83;
    entry->text[11] = 0x8b;
    entry->text[12] = 0x50;
    i = i + 1;
    entry->text[0] = 0;
    entry = (RoomRow *)((char *)entry + ROOM_ENTRY_SIZE);
  } while (i < ROOM_ENTRY_COUNT);
  FUN_002b7898(info->unk10);
  FUN_000114c0(&info->unk58,0,0x1c);
  info->unk60 = 1;
  FUN_000114c0(&info->block,0,sizeof(RoomBlock));
  info->block.unk68 = -1;
  info->block.unk6a = -1;
  info->block.unk24 = -1;
  FUN_0008cae8(DAT_002beac0,sizeof(RoomInfo));
  return;
}
