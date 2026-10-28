/* Small records shared by the menu sources: a Cell (value + base) and a 0x8c-byte screen record. */
#ifndef HST_MENU_REC_H
#define HST_MENU_REC_H

#include "hst/types.h"

/* Object whose word at 0x24 is set from the word at 0x28 plus a delta. */
typedef struct Cell {
    char pad00[0x24];
    int unk24;  /* 0x24 */
    int unk28;  /* 0x28 */
} Cell;

/* 0x8c-byte record handled by FUN_00217940 and the move helpers. */
typedef struct Rec8c {
    char pad00[8];
    s16 x;      /* 0x08 */
    s16 y;      /* 0x0a */
    char pad0c[0x14];
    u32 color;  /* 0x20 */
    char pad24[0x8c - 0x24];
} Rec8c;

#define MENU_REC_COUNT 9

#endif
