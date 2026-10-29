/* Player object that steps through a global table of 64-byte records, and the record layout. */
#ifndef HST_TABLE_PLAYER_H
#define HST_TABLE_PLAYER_H

#define TABLE_REC_COUNT 0x80 /* records in the global table */

/* One record; the table is an array of these. */
typedef struct TableRec {
    char pad00[0x24];
    int unk24; /* 0x24 */
    char pad28[0x30 - 0x28];
    int key;   /* 0x30 looked up by id */
    int unk34; /* 0x34 */
    char pad38[4];
    int unk3c; /* 0x3c must be positive for a record to be picked */
} TableRec;    /* size 0x40 */

typedef struct TablePlayerSub {
    char pad00[0x30];
    int key; /* 0x30 */
} TablePlayerSub;

typedef struct TablePlayer {
    char pad00[0x50];
    TablePlayerSub *sub;    /* 0x50 */
    int cur;                /* 0x54 index of the current record, -1 for none */
    char pad58[4];
    float unk5c;            /* 0x5c */
    float time;             /* 0x60 */
    unsigned char active;   /* 0x64 */
    char pad65[3];
    int unk68;              /* 0x68 */
    float pos;              /* 0x6c */
    float limit;            /* 0x70 */
    int offset;             /* 0x74 */
    int override_idx;       /* 0x78 */
    int override_kind;      /* 0x7c */
} TablePlayer;

#endif
