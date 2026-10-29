/* Global state object returned by FUN_0019d474 (only the fields the menu-state sources read). */
#ifndef HST_GAME_STATE_H
#define HST_GAME_STATE_H

#include "hst/types.h"

typedef struct ItemList {
  int unk0;
  u32 count; /* number of rows */
} ItemList;

typedef struct GameState {
  char pad000[0x2dc];
  int cursor;        /* 0x2dc index of the highlighted row */
  char pad2e0[0x80];
  ItemList items;    /* 0x360 row list; its count bounds the row loops */
  char pad368[0x39];
  u8 unk3a1;         /* 0x3a1 selects which of two handlers to run */
} GameState;

#endif
