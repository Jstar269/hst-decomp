/* Object of the 0x216000 sources: a position, a lock flag, a few reset values and a target position that starts at the position. */
#ifndef HST_TARGET_OBJ_H
#define HST_TARGET_OBJ_H

#include "hst/types.h"

typedef struct Point3 {
  float x;
  float y;
  float z;
} Point3;

typedef struct TargetObj {
  Point3 pos;           /* 0x00 */
  u8 flag;              /* 0x0c cleared by the init; the init-from-args source does nothing while it is set */
  char pad0d[3];
  float unk10;          /* 0x10 -1.0f after the init, 0 after the init-from-args */
  char pad14[12];
  float unk20;          /* 0x20 */
  float unk24;          /* 0x24 */
  float unk28;          /* 0x28 */
  float unk2c;          /* 0x2c 1.0f after init */
  float unk30;          /* 0x30 */
  float unk34;          /* 0x34 */
  Point3 target;        /* 0x38 copy of pos made by the inits */
} TargetObj;

#endif
