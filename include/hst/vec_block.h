/* 0xa8-byte record of 4-float vectors, set by the small 0x166000 setters and cleared by FUN_00166a44. */
#ifndef HST_VEC_BLOCK_H
#define HST_VEC_BLOCK_H

#include "hst/vec.h"

#include "hst/types.h"

typedef struct VecBlock {
  Float4 v00;        /* 0x00 point, w = 1 */
  Float4 v10;        /* 0x10 point, w = 1 */
  Float4 v20;        /* 0x20 point, w = 1 */
  float unk30;       /* 0x30 */
  float unk34;       /* 0x34 */
  float unk38;       /* 0x38 */
  float unk3c;       /* 0x3c */
  float unk40[4];    /* 0x40 */
  float unk50[4];    /* 0x50 */
  float unk60;       /* 0x60 */
  u8 unk64;          /* 0x64 */
  u8 unk65;          /* 0x65 */
  char pad66[0xa];
  Float4 v70;        /* 0x70 copy of v00 made by its setter */
  Float4 v80;        /* 0x80 copy of v10 made by its setter */
  float unk90[6];    /* 0x90 */
} VecBlock;          /* size 0xa8 */

#endif
