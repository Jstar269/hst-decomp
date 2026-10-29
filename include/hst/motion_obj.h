/* Object driven by the motion sources (motion kinds, item link, countdown) and the global tables they share. */
#ifndef HST_MOTION_OBJ_H
#define HST_MOTION_OBJ_H

#include "hst/types.h"

#define MOTION_TABLE_COUNT 800   /* entries in the global entry table */
#define ID_TABLE_COUNT 18        /* entries in the global id table */

/* Item linked from the object; only its id and two words are read here. */
typedef struct MotionItem {
  char pad00[0xf0];
  int unkf0;            /* 0xf0 compared with every entry of the id table */
  char pad0f4[0x124 - 0xf4];
  int unk124;           /* 0x124 negative while the item is idle */
} MotionItem;

/* One 0x10-byte entry of the global entry table. */
typedef struct MotionEntry {
  int unk00;            /* 0x00 */
  char pad04[0xc];
} MotionEntry;

typedef struct MotionObj {
  char pad00[0x50];
  void *unk50;          /* 0x50 */
  char pad54[4];
  MotionItem *item;     /* 0x58 */
  char pad5c[0x198 - 0x5c];
  int unk198;           /* 0x198 */
  char pad19c[0x1d0 - 0x19c];
  char data1d0[0x339 - 0x1d0];  /* 0x1d0 sub-block passed on to the setup helper */
  u8 flag339;           /* 0x339 */
  char pad33a[2];
  int unk33c;           /* 0x33c cleared when the flag changes */
  char pad340[4];
  int countdown;        /* 0x344 */
} MotionObj;

#endif
