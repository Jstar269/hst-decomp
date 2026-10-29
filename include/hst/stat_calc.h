/* Stat records, per-record modifiers and the clamp limit tables used by the stat calculations. */
#ifndef HST_STAT_CALC_H
#define HST_STAT_CALC_H

#define STAT_REC_SIZE 0x22c /* size of one stat record in the record table */
#define STAT_LIMIT_COUNT 5  /* stats with a limit column */
#define RANK_ROW_SIZE 0x14  /* bytes per rank row of the bonus table */
#define RANK_BONUS_BASE 0xf0 /* offset of the first stat's bonus within a rank row */

/* A record of base stats (percent scales at +0x88 and +0x94). */
typedef struct StatRec {
    char pad00[0x44];
    float stat0;     /* 0x44 */
    char pad48[4];
    float stat1;     /* 0x4c */
    float stat2;     /* 0x50 */
    float stat3;     /* 0x54 */
    float stat4;     /* 0x58 */
    char pad5c[0x88 - 0x5c];
    float scale88;   /* 0x88 */
    char pad8c[0x94 - 0x8c];
    float scale94;   /* 0x94 */
    char pad98[STAT_REC_SIZE - 0x98];
} StatRec;

/* The modifier whose id selects a record and whose rank selects a row of bonuses. */
typedef struct StatMod {
    char pad00[10];
    short id;         /* 0x0a */
    char pad0c[0xa0 - 0xc];
    signed char rank; /* 0xa0 */
} StatMod;

/* One row of the limit table: a value per stat. */
typedef struct LimitRow {
    float v[STAT_LIMIT_COUNT];
} LimitRow;

/* Table header: rows of `base`, `count` of them; `index` maps an id to a row. */
typedef struct StatRecTable {
    char *base;      /* 0x00 records of STAT_REC_SIZE bytes */
    int count;       /* 0x04 */
    int pad08;       /* 0x08 */
    short *index;    /* 0x0c */
} StatRecTable;

typedef struct LimitTable {
    char *base;      /* 0x00 rows of LimitRow: first = minimum, last = maximum */
    int count;       /* 0x04 */
} LimitTable;

/* The record for a modifier id, and the limit row `row` of a limit table. */
#define STAT_REC_AT(tbl, id) ((StatRec *)((tbl)->base + (tbl)->index[id] * STAT_REC_SIZE))
#define LIMIT_ROW_AT(tbl, row) ((LimitRow *)((tbl)->base + (row) * sizeof(LimitRow)))

#endif
