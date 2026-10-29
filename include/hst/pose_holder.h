/* Holder of two pose records (4x4 float rows plus a word tail), an element list and two owned objects. */
#ifndef HST_POSE_HOLDER_H
#define HST_POSE_HOLDER_H

#include "hst/types.h"
#include "hst/vec.h"
#include "hst/list_head.h"

#define POSE_TAIL_WORDS 0x12 /* integer words after the four rows */

typedef struct PoseObj {
  Float4 rows[4];                 /* 0x00 */
  u32 tail[POSE_TAIL_WORDS];      /* 0x40 */
  u8 flag;                        /* 0x88 */
} PoseObj;                        /* 0x8c bytes plus padding */

typedef struct PoseHolder {
  u32 unk0;                       /* 0x00 */
  DListHead list;                 /* 0x04 */
  void *objB;                     /* 0x10 owned object, deleted second */
  void *objA;                     /* 0x14 owned object, deleted first */
  char pad18[8];
  PoseObj poseA;                  /* 0x20 */
  char padac[0xb0 - 0x20 - 0x8c];
  PoseObj poseB;                  /* 0xb0 */
} PoseHolder;

#endif
