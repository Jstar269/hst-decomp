/* Global game record, as far as the challenge lobby uses it: per-slot flag bytes and the word after them. */
#ifndef HST_GAME_RECORD_H
#define HST_GAME_RECORD_H

#include "hst/types.h"

#define RECORD_SLOT_COUNT 10   /* challenge slots whose flag byte is kept */
#define SLOT_FLAG_BIT7 0x80    /* set by the lobby in states 6 and 7, tested by the slot refresh */

/* Part of the record that holds the slot flags; reached through its own base to keep offsets small. */
typedef struct RecordSlots {
  char pad0[0x8d00];
  u8 slot_flags[RECORD_SLOT_COUNT]; /* 0x8d00 */
  char pad8d0a[0xab24 - 0x8d0a];
  int unkab24;                      /* 0xab24 */
} RecordSlots;

typedef struct GameRecord {
  char pad0[0x3500];
  RecordSlots slots;                /* 0x3500 */
} GameRecord;

#endif
