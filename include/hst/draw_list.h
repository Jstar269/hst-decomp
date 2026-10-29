/* Frame-based draw owner: a table of frames and a growable queue of draw requests. */
#ifndef HST_DRAW_LIST_H
#define HST_DRAW_LIST_H

#include "hst/vec_reserve.h"

typedef struct DrawList {
  const void *vtable;  /* 0x00 */
  void **frames;       /* 0x04 frame objects, indexed by frame id */
  int frameCount;      /* 0x08 */
  char pad0c[4];
  RawVec queue;        /* 0x10 pending draw requests: storage, count, capacity */
} DrawList;

#endif
