/* Player objects of the 0x96000 sources: the player list, a player's slot index and flag, and the per-slot record copied out of a row. */
#ifndef HST_PLAYER_RECORD_H
#define HST_PLAYER_RECORD_H

#include "hst/types.h"
#include "hst/vec.h"

#define PLAYER_SLOTS 4   /* entries of the player list */

typedef struct SlotPlayer {
  char pad0[0x148];
  int index;           /* 0x148 slot index of the player */
  char pad14c[0x1b4 - 0x14c];
  u8 unk1b4;           /* 0x1b4 */
} SlotPlayer;

typedef struct PlayerList {
  char pad0[0x70];
  SlotPlayer *players[PLAYER_SLOTS]; /* 0x70 */
} PlayerList;

/* Record stored in a slot row (also mirrored into globals). */
typedef struct SlotRecord {
  Float4 a;            /* 0x00 */
  Float4 b;            /* 0x10 */
  float c0, c1, c2, c3; /* 0x20 */
  int d0;              /* 0x30 */
  short d1;            /* 0x34 */
  signed char d2;      /* 0x36 */
  signed char d3;      /* 0x37 */
  int d4;              /* 0x38 */
} SlotRecord;

/* Row returned by the slot table lookup; only the record at 0xf0 is named. */
typedef struct SlotRow {
  char pad0[0xf0];
  SlotRecord rec;      /* 0xf0 */
} SlotRow;

#endif
