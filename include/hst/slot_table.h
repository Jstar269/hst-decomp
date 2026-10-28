/* Slot table object used by the 0x1af000-0x1b0000 sources (slot reset, BGM start, menu state setup). */
#ifndef HST_SLOT_TABLE_H
#define HST_SLOT_TABLE_H

#include "hst/types.h"

#define SLOT_COUNT 0x1da /* number of slot pointers; also the "no slot" index */
#define SLOT_KEEP 0x58   /* slot that the reset leaves alone */
#define MENU_ENTRY_MAX 15

/* One row of the menu entry array; only the first word is used here. */
typedef struct MenuEntry {
  int widget;     /* 0x00 object whose flag is toggled when its row is not the cursor row */
  char pad04[0x10];
} MenuEntry;      /* size 0x14 */

typedef struct SlotTable {
  void *slot[SLOT_COUNT]; /* 0x000 owned objects; deleted and cleared by the reset */
  int unk768[4];          /* 0x768 */
  int unk778[4];          /* 0x778 */
  int unk788;             /* 0x788 */
  int unk78c[2];          /* 0x78c */
  int unk794;             /* 0x794 */
  u8 unk798[4];           /* 0x798 */
  int court_sound;        /* 0x79c current court sound index, -1 when none */
  int unk7a0;             /* 0x7a0 */
  int unk7a4;             /* 0x7a4 */
  int unk7a8;             /* 0x7a8 */
  int unk7ac;             /* 0x7ac */
  int unk7b0;             /* 0x7b0 */
  int unk7b4;             /* 0x7b4 */
  int unk7b8;             /* 0x7b8 */
  int unk7bc;             /* 0x7bc */
  int unk7c0;             /* 0x7c0 */
  int unk7c4;             /* 0x7c4 */
  int unk7c8;             /* 0x7c8 */
  volatile int cur;       /* 0x7cc current state id, SLOT_COUNT when none */
  char pad7d0[8];
  int unk7d8;             /* 0x7d8 */
  u8 unk7dc;              /* 0x7dc */
  char pad7dd[3];
  MenuEntry entry[MENU_ENTRY_MAX]; /* 0x7e0 */
  char pad90c[8];
  void *widget;           /* 0x914 */
} SlotTable;

/* State object whose owner field (0x0c) points at the slot table. */
typedef struct SlotMenuState {
  char pad00[0xc];
  SlotTable *owner; /* 0x0c */
} SlotMenuState;

#endif
