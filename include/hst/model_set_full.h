/* Fuller view of the model-set owner (see model_set.h): adds the id table, the two float vectors and the tail fields. */
#ifndef HST_MODEL_SET_FULL_H
#define HST_MODEL_SET_FULL_H

#include "hst/types.h"

#define MSET_LINK_COUNT 7  /* ids at +0x04, reset to -1 */
#define MSET_SLOT_COUNT 6 /* model slots at +0x50, reset to 0 */
#define MSET_ENTRY_COUNT 7 /* entries in the heap table at +0x24 */
#define MSET_ENTRY_SIZE 8  /* bytes per table entry */

typedef struct ModelSetFull {
  void *vtbl;                      /* 0x00 */
  int link[MSET_LINK_COUNT];       /* 0x04 ids, -1 when unset */
  int unk20;                       /* 0x20 -1 when unset */
  void *entries;                   /* 0x24 heap table of MSET_ENTRY_COUNT entries, 0 when not built */
  int level;                       /* 0x28 clamped mode value, negative disables the table fill */
  char pad2c[4];
  float vecA[4];                   /* 0x30 reset to -1 in each lane */
  float vecB[4];                   /* 0x40 reset to (0, 1, 0, 0) */
  int model[MSET_SLOT_COUNT];     /* 0x50 model slot pointers, cleared by the reset */
  int unk68;                       /* 0x68 -1 when unset */
  int unk6c;                       /* 0x6c */
  int unk70;                       /* 0x70 */
  s8 unk74;                        /* 0x74 */
  u8 unk75;                        /* 0x75 */
  char pad76[10];
  char boneA[0x30];                /* 0x80 sub-object */
  char boneB[0x30];                /* 0xb0 sub-object */
} ModelSetFull;

#endif
