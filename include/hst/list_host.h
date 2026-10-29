/* Host object of the 0x1792xx-0x1797xx sources: state fields, sub-objects and the per-kind pointer lists they read. */
#ifndef HST_LIST_HOST_H
#define HST_LIST_HOST_H

#include "hst/types.h"
#include "hst/vec_reserve.h"

/* Row of the table at the end of the host: a weight word is summed by the stat accessor. */
typedef struct StatRow {
  int unk00;       /* 0x00 */
  int weight;      /* 0x04 */
  int unk08;       /* 0x08 */
} StatRow;         /* size 0xc */

typedef struct ListHost {
  char pad00[0x6c];
  int unk6c;                /* 0x6c */
  int state;                /* 0x70 */
  char pad74[0x90 - 0x74];
  u32 unk90;                /* 0x90 */
  char pad94[0x174 - 0x94];
  void *sub174;             /* 0x174 */
  void *sub178;             /* 0x178 */
  void *sub17c;             /* 0x17c */
  char pad180[0x1a8 - 0x180];
  int unk1a8;               /* 0x1a8 */
  char pad1ac[0x1d4 - 0x1ac];
  RawVec *shared;           /* 0x1d4 */
  RawVec list1a;            /* 0x1d8 */
  RawVec list1b;            /* 0x1e4 */
  RawVec list2a;            /* 0x1f0 */
  RawVec list2b;            /* 0x1fc */
  RawVec list3;             /* 0x208 used for two kinds */
  char pad214[0x508 - 0x214];
  StatRow *rows;            /* 0x508 */
  unsigned rowCount;        /* 0x50c */
  char pad510[0x558 - 0x510];
  u32 (*callback)(void);    /* 0x558 */
  char pad55c[0x634 - 0x55c];
  int soundHandle;          /* 0x634 handle of the playing sound, -1 when none */
} ListHost;

#endif
