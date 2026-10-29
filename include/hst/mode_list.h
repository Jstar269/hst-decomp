/* List of selectable items shown three at a time, with a highlighted one chosen by a mode. */
#ifndef HST_MODE_LIST_H
#define HST_MODE_LIST_H

#include "hst/types.h"

/* Number of key records and of items shown together. */
#define MODE_LIST_KEY_WORDS 8
#define MODE_LIST_SHOWN 3

/* Item flag bits tested before the list reacts to input. */
#define MODE_ITEM_LOCKED 3

typedef struct ModeItem {
  char pad00[0xe];
  u16 flags;          /* 0x0e */
} ModeItem;

/* 12-byte record of the table at 0x120; the first two halfwords are copied into the list. */
typedef struct ModeRec {
  short unk00;        /* 0x00 */
  short unk02;        /* 0x02 */
  char pad04[8];
} ModeRec;

typedef struct ModeList {
  char pad00[0x10];
  ModeItem **items;   /* 0x10 */
  int item_count;     /* 0x14 */
  char pad18[0xd0 - 0x18];
  int unkd0;          /* 0xd0 */
  int first;          /* 0xd4 index of the first of the three shown items */
  int orient;         /* 0xd8 selects which pad keys step the cursor */
  int cur;            /* 0xdc current record */
  int unke0;          /* 0xe0 */
  int last;           /* 0xe4 index of the last record */
  u8 unke8;           /* 0xe8 */
  u8 unke9;           /* 0xe9 */
  u8 unkea;           /* 0xea */
  char padeb;
  short unkec;        /* 0xec copied from the current record */
  short unkee;        /* 0xee copied from the current record */
  int keys[MODE_LIST_KEY_WORDS]; /* 0xf0 repeat state of the cursor keys */
  int start;          /* 0x110 record the list restarts from */
  u8 unk114;          /* 0x114 */
  char pad115[3];
  int mode;           /* 0x118 which of the shown items is highlighted: 0 middle, 1 first, 2 last */
  short unk11c;       /* 0x11c */
  short unk11e;       /* 0x11e */
  ModeRec *recs;      /* 0x120 record table */
  int rec_count;      /* 0x124 */
  unsigned rec_cap;   /* 0x128 */
  u8 unk12c;          /* 0x12c */
  u8 unk12d;          /* 0x12d */
} ModeList;

#endif
