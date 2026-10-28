/* Record layouts shared by the entry/info initialiser family (0x8d000 and 0x201000 ranges). */
#ifndef HST_ENTRY_RECORDS_H
#define HST_ENTRY_RECORDS_H

#include "hst/types.h"

/* Number of short ids at the start of a Rec200; -1 marks an unused id. */
#define REC_ID_COUNT 6
#define REC_ID_NONE (-1)
/* Entries in an EntryTable. */
#define ENTRY_TABLE_COUNT 4

typedef struct Pair3 {
    u8 unk0;
    u8 unk1;
    u8 unk2;
} Pair3;

/* 0x14-byte record cleared by memset, then three bytes set. */
typedef struct Rec14 {
    u8 unk00; /* 0x00 */
    u8 unk01; /* 0x01, initial 1 */
    u8 unk02; /* 0x02, initial 2 */
    u8 unk03; /* 0x03 */
    char pad04[5];
    u8 unk09; /* 0x09 */
    u8 unk0a; /* 0x0a */
    char pad0b[5];
    u8 unk10; /* 0x10 */
    char pad11[3];
} Rec14;

/* 0x6c-byte record; three halfwords are set to -1 after the clear. */
typedef struct Rec6c {
    char pad00[0x24];
    s16 unk24; /* 0x24 */
    char pad26[0x42];
    s16 unk68; /* 0x68 */
    s16 unk6a; /* 0x6a */
} Rec6c;

/* 0xc8-byte base record: six ids, two strings, a byte-triple table. */
typedef struct Rec200 {
    s16 ids[REC_ID_COUNT]; /* 0x00 */
    char pad0c[0x14];
    u16 unk20; /* 0x20 */
    u16 unk22; /* 0x22 */
    char pad24[0x30];
    char str54[0x14]; /* 0x54, initial "-1" */
    char str68[0x12]; /* 0x68, initial "-1" */
    s16 unk7a;        /* 0x7a */
    char pad7c[2];
    Pair3 pairs[4];   /* 0x7e */
    char pad8a[0xc8 - 0x8a];
} Rec200;

/* 0xf4-byte entry: Rec200 base plus a default UTF-8 string and two tail fields. */
typedef struct Entry {
    Rec200 base;  /* 0x00 */
    u8 unkc8;     /* 0xc8 */
    char strc9[0x23]; /* 0xc9, default UTF-8 string */
    float unkec;  /* 0xec, initial 5.0f */
    u8 unkf0;     /* 0xf0, initial 10 */
    u8 unkf1;     /* 0xf1 */
    char padf2[2];
} Entry;

/* Table object: four Entries (array-constructed) followed by a Rec6c. */
typedef struct EntryTable {
    char pad00[0x94];
    Entry entries[ENTRY_TABLE_COUNT]; /* 0x94 */
    Rec6c info;                       /* 0x464 */
} EntryTable;

#endif
