/* Views used by the player-position getters: the scene's player table, a slot reference and a 4x4 matrix. */
#ifndef HST_PLAYER_SLOT_H
#define HST_PLAYER_SLOT_H

#include "hst/vec.h"

enum { PLAYER_SLOT_MAX = 4 };       /* singles use 2, doubles 4 */

typedef struct Mat4 {
  Float4 row[4];
} Mat4;

/* Data block hung off a player object. */
typedef struct PlayerExt {
  char pad0[0x58];
  int unk58;                        /* 0x58 */
  char pad5c[0x64 - 0x5c];
  int unk64;                        /* 0x64 */
} PlayerExt;

typedef struct PlayerObj {
  char pad0[0x5bc];
  PlayerExt *unk5bc;                /* 0x5bc */
} PlayerObj;

/* The scene object seen through its player array. */
typedef struct PlayerTable {
  char pad0[0x70];
  PlayerObj *players[PLAYER_SLOT_MAX];   /* 0x70 */
} PlayerTable;

/* Reference to one player slot plus an embedded transform source. */
typedef struct SlotRef {
  char pad0[8];
  int slot;                         /* 0x08 index into PlayerTable.players */
  char pad0c[0x1c - 0x0c];
  char unk1c[4];                    /* 0x1c passed by address to the matrix builder */
} SlotRef;

#endif
