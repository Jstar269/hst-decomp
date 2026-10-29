/* Object owning two deque containers (0x118000 sources: constructor, destructor, resets) and the container head layouts. */
#ifndef HST_DEQUE_OWNER_H
#define HST_DEQUE_OWNER_H

#include "hst/types.h"

#define OWNER_FLAG_COUNT 27   /* flag bytes cleared by the reset */
#define OWNER_TABLE_BANKS 4   /* outer groups of the cleared table */
#define OWNER_TABLE_ROWS 2    /* rows per bank */
#define OWNER_TABLE_COLS 11   /* ints per row */

/* 24-byte container: opaque head, then two words that are zeroed by the constructors. */
typedef struct DequeBox {
    char head[0x10];  /* 0x00, set up by the base constructor */
    u32 unk10;        /* 0x10 */
    u32 unk14;        /* 0x14 */
} DequeBox;

/* Circular deque header: capacity, a word, start index and the element block. */
typedef struct Cdeque {
    int cap;          /* 0x00, elements in the block */
    int unk4;         /* 0x04 */
    int start;        /* 0x08, index of the first element */
    int *data;        /* 0x0c */
} Cdeque;

/* Iterator over a Cdeque: current position, block start, first element, block end. */
typedef struct CdequeIter {
    int *ptr;         /* 0x00 */
    int *beg;         /* 0x04 */
    int *first;       /* 0x08 */
    int *end;         /* 0x0c */
} CdequeIter;

typedef struct DequeOwner {
    const void *vtable;       /* 0x00 */
    char pad04[0x44 - 4];
    u8 unk44;                 /* 0x44 */
    char pad45[0xb4 - 0x45];
    u8 flags[OWNER_FLAG_COUNT]; /* 0xb4, cleared by the reset */
    char padcf[0xec - 0xcf];
    void *unkec;              /* 0xec, released by FUN_001188c8 */
    char padf0[4];
    int unkf4[OWNER_TABLE_BANKS];  /* 0xf4 */
    int table[OWNER_TABLE_BANKS][OWNER_TABLE_ROWS][OWNER_TABLE_COLS]; /* 0x104 */
    char pad264[0x2e0 - 0x264];
    DequeBox deque2e0;        /* 0x2e0 */
    DequeBox deque2f8;        /* 0x2f8 */
} DequeOwner;

#endif
