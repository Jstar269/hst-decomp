/* Object with a vtable, two embedded sub-objects (at +0x30 and +0x80) and a few constructor-initialised fields. */
#ifndef HST_SUB_PAIR_OBJ_H
#define HST_SUB_PAIR_OBJ_H

#include "hst/types.h"

typedef struct SubPairObj {
  u32 vtable;      /* 0x00 */
  char pad04[0x2c];
  char subA[0x40]; /* 0x30 embedded sub-object */
  u32 unk70;       /* 0x70 cleared */
  u32 unk74;       /* 0x74 set to -1 */
  u32 unk78;       /* 0x78 bit pattern of 1.0f */
  u32 unk7c;       /* 0x7c bit pattern of 1.0f */
  char subB[0x40]; /* 0x80 embedded sub-object */
  u32 arg;         /* 0xc0 constructor argument */
  char padC4[0xc];
  u32 unkD0;       /* 0xd0 */
  u32 unkD4;       /* 0xd4 */
  u32 unkD8;       /* 0xd8 */
} SubPairObj;

#endif
