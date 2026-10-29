/* Object with ten growable slot vectors and per-slot counters; shared by its constructor, destructor and element destructor. */
#ifndef HST_SLOT_ARRAY_OBJ_H
#define HST_SLOT_ARRAY_OBJ_H

#include "hst/types.h"

#define SLOT_ARRAY_COUNT 10     /* slot vectors, and entries of each per-slot counter table */
#define SLOT_ARRAY_RESERVE 20   /* capacity every slot vector is grown to when smaller */

/* Growable vector of one slot (12 bytes). */
typedef struct SlotVec {
  void *data;             /* 0x00 */
  u32 unk04;              /* 0x04 */
  u32 capacity;           /* 0x08 */
} SlotVec;

typedef struct SlotArrayObj {
  void *vtbl;             /* 0x000 */
  char pad04[0x38];
  void *vtbl2;            /* 0x03c second base */
  char pad40[0x90 - 0x40];
  u8 unk90;               /* 0x090 */
  char pad91[7];
  SlotVec slots[SLOT_ARRAY_COUNT]; /* 0x098 */
  char pad110[0x168 - 0x110];
  u8 unk168;              /* 0x168 */
  u8 unk169;              /* 0x169 */
  char pad16a[0x38a - 0x16a];
  u8 unk38a;              /* 0x38a */
  char pad38b;
  int unk38c;             /* 0x38c */
  char pad390[0x3a8 - 0x390];
  int unk3a8[SLOT_ARRAY_COUNT]; /* 0x3a8 */
  int unk3d0[SLOT_ARRAY_COUNT]; /* 0x3d0 */
  int unk3f8;             /* 0x3f8 starts at -1 */
  char pad3fc[4];
  int unk400;             /* 0x400 */
  char pad404[4];
  u8 unk408;              /* 0x408 */
  char pad409[3];
  int unk40c;             /* 0x40c */
  int unk410;             /* 0x410 */
  u8 unk414;              /* 0x414 */
  char pad415[3];
  int unk418;             /* 0x418 */
  char member41c[0x4a8 - 0x41c]; /* 0x41c sub-object */
  void *owned;            /* 0x4a8 heap object (0x74 bytes), deleted by the destructor */
} SlotArrayObj;
#endif
