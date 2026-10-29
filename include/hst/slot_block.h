/* Slot block of the 0x281000 sources: three 0x120-byte slots (id, team, record) after a short header, and the setup data they read. */
#ifndef HST_SLOT_BLOCK_H
#define HST_SLOT_BLOCK_H

#include "hst/types.h"

#define SLOT_BLOCK_COUNT 3     /* slots per block */
#define SLOT_REC_NAME_SIZE 0x21
#define SLOT_ID_NONE (-1)
#define SLOT_REC_DEFAULT_SCALE 5.0f
#define SETUP_ENTRY_COUNT 15   /* entries in SetupData.table */

/* Per-slot record at slot + 0xe0 (0x40 bytes). */
typedef struct SlotRec {
    u8 unk00;                       /* 0x00 */
    u8 unk01;                       /* 0x01 */
    char pad02;
    u8 unk03;                       /* 0x03 */
    char name[SLOT_REC_NAME_SIZE];  /* 0x04, default UTF-8 name, overwritten from the setup data */
    u8 unk25;                       /* 0x25 */
    u8 unk26;                       /* 0x26 */
    u8 unk27;                       /* 0x27 */
    u8 unk28;                       /* 0x28 */
    char pad29[3];
    int unk2c;                      /* 0x2c, initial -1 */
    int unk30;                      /* 0x30, initial -1 */
    float unk34;                    /* 0x34, initial 5.0f */
    u8 unk38;                       /* 0x38, initial 10 */
    u8 unk39;                       /* 0x39 */
    char pad3a[2];
    u32 unk3c;                      /* 0x3c */
} SlotRec;

/* One slot (0x120 bytes): a 200-byte info record at 0x18 whose first id is read here, a team byte and the SlotRec. */
typedef struct TeamSlot {
    char unk00[0x10];        /* 0x00, second slot is filled from the setup data */
    char unk10[8];           /* 0x10 */
    s16 id;                  /* 0x18 first id of the info record */
    char pad1a[0x7f - 0x1a];
    char team;               /* 0x7f */
    char pad80[0xe0 - 0x80];
    SlotRec rec;             /* 0xe0 */
} TeamSlot;

/* Block initialised by FUN_00281238: header then the slots. */
typedef struct SlotBlock {
    int ids[4];              /* 0x00, initial -1 */
    int unk10;               /* 0x10, initial -1 */
    u8 unk14;                /* 0x14 */
    char pad15[3];
    char unk18[8];           /* 0x18, start of a 0x1c-byte area cleared at init (runs into the first slot) */
    int unk20;               /* 0x20, initial 1 */
    char pad24[4];
    TeamSlot slots[SLOT_BLOCK_COUNT]; /* 0x28 */
} SlotBlock;

/* Object that owns the block. */
typedef struct SlotBlockOwner {
    char pad00[0x5c];
    int unk5c;               /* 0x5c */
    char pad60[0x80 - 0x60];
    int mode;                /* 0x80, 0..3 */
    char pad84[0x4e8 - 0x84];
    SlotBlock block;         /* 0x4e8 */
    char pad870[0x890 - 0x870];
    char unk890[4];          /* 0x890, passed by address */
} SlotBlockOwner;

/* One row of the setup table; only the float at +4 is read. */
typedef struct SetupEntry {
    int pad0;
    float f4;                /* 0x04 */
    char pad08[0x38 - 8];
} SetupEntry;

/* Count followed by the setup rows. */
typedef struct SetupTable {
    int count;                          /* 0x00 */
    SetupEntry entries[SETUP_ENTRY_COUNT]; /* 0x04 */
} SetupTable;

/* Global setup data (DAT_003415a8); only the fields these sources read. */
typedef struct SetupData {
    char pad00[4];
    char unk04[0x10];        /* 0x04 */
    char pad14[4];
    char unk18[8];           /* 0x18 */
    char unk20[0x60];        /* 0x20, NUL-terminated string */
    SetupTable table;        /* 0x80 */
    char pad3cc[0x1414 - 0x3cc];
    float unk1414;           /* 0x1414 */
} SetupData;

#endif
