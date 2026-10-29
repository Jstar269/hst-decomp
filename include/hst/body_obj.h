/* Object with four vectors, three 16-float blocks and a hit counter; shared by its constructor and the setter that fills it. */
#ifndef HST_BODY_OBJ_H
#define HST_BODY_OBJ_H

#include "hst/types.h"
#include "hst/vec.h"

#define BODY_COUNTER_LIMIT 2  /* the setter bumps the counter only while it is below this */

typedef struct BodyObj {
  void *vtbl;           /* 0x000 */
  int unk04;            /* 0x004 */
  char pad08[8];
  Float4 vec10;         /* 0x010 */
  Float4 vec20;         /* 0x020 */
  Float4 vec30;         /* 0x030 */
  Float4 vec40;         /* 0x040 */
  float block50[16];    /* 0x050 */
  float block90[16];    /* 0x090 */
  float blockd0[16];    /* 0x0d0 */
  u32 unk110;           /* 0x110 */
  u32 unk114;           /* 0x114 */
  char pad118[4];
  u32 unk11c;           /* 0x11c */
  float unk120;         /* 0x120 */
  float unk124;         /* 0x124 */
  int unk128;           /* 0x128 */
  int unk12c;           /* 0x12c */
  char pad130[4];
  int unk134;           /* 0x134 */
  char pad138[0x170 - 0x138];
  u32 unk170;           /* 0x170 */
  int unk174;           /* 0x174 */
  char pad178[4];
  int unk17c;           /* 0x17c */
  int unk180;           /* 0x180 */
  char pad184[0x1d0 - 0x184];
  u8 unk1d0;            /* 0x1d0 */
  char pad1d1[3];
  int counter;          /* 0x1d4 */
} BodyObj;
#endif
