/* Global game-mode record: current mode id at +0x3c and a flag byte at +0x4c. */
#ifndef HST_GAME_MODE_STATE_H
#define HST_GAME_MODE_STATE_H

#include "hst/types.h"

typedef struct GameModeState {
  char pad00[0x3c];
  int mode;               /* 0x3c current mode id */
  char pad40[0xc];
  u8 flag;                /* 0x4c */
} GameModeState;

#endif
