/* Object with a hand selector, four row vectors, a scale vector and a model pointer (C view; only these fields are described). */
#ifndef HST_RIG_OBJ_H
#define HST_RIG_OBJ_H

#include "hst/vec.h"

typedef struct RigObj {
  char pad000[0x150];
  int hand;           /* 0x150 0 = left hand, otherwise right hand */
  int unk154;         /* 0x154 */
  char pad158[0x550 - 0x158];
  Float4 rows[4];     /* 0x550 four row vectors, copied into a matrix after scaling; the last one is the position */
  char pad590[0x10];
  Float4 scale;       /* 0x5a0 vector multiplied into each row */
  char pad5b0[0xc];
  void *model;        /* 0x5bc model handed the finished matrix */
} RigObj;

#endif
